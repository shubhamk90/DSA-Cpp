#include<iostream>
#include<queue>
using namespace std;

class Node{
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        std::cout << node->data << std::endl;
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, false);
    }
}

void printBT(const Node* node)
{
    printBT("", node, false);
}

void rightView(Node* root)
{

    if(root==NULL)
        return;

    Node* temp = root;

    while(temp->left!=NULL && temp->right!=NULL)
    {
        cout<<temp->data<<" ";

        if(temp->right==NULL)
            temp = temp->left;

        else if(temp->right->left==NULL && temp->right->right==NULL)
        {
            cout<<temp->right->data<<" ";

            if(temp->left->right==NULL)
                temp = temp->left->left;
            else
                temp = temp->left->right;
        }  
        else
            temp = temp->right;
    }

    cout<<temp->data<<" ";
}


int RightViewUsingQueue(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        for(int i =0; i<n; i++)
        {
            Node* curr = q.front();
            q.pop();

            if(i==n-1)
                cout<<curr->data<<" ";
            

            if(curr->left!=NULL)
                q.push(curr->left);

            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->left->left = new Node(7);
    root->right->right = new Node(6);

    RightViewUsingQueue(root);
    return 0;
}