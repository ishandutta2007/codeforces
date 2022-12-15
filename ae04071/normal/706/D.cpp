#include <cstdio>

const int MAX_EXPO = 30;

struct TrieNode
{
    int size, num;
    TrieNode* children[2];
    bool end;
    
    TrieNode() : size(0), num(0), end(false)
    {
        for(int i = 0; i < 2; i++)
            children[i] = nullptr;
    }
    ~TrieNode()
    {
        for(int i = 0; i < 2; i++)
        {
            if(children[i] != nullptr)
                delete children[i];
        }
    }
    void Add(int _num, int _expo)
    {
        size++;
        if(_expo == -1)
        {
            end = true;
            num = _num;
            
            return;
        }
        
        int index = (_num & (1 << _expo)) >> _expo;
        if(children[index] == nullptr)
            children[index] = new TrieNode();
        children[index]->Add(_num, _expo -1);
    }
    void Sub(int _num, int _expo)
    {
        size--;
        if(!end)
        {
            int index = (_num & (1 << _expo)) >> _expo;
            children[index]->Sub(_num, _expo - 1);
        }
    }
    int Find(int _num, int _expo)
    {
        if(end)
            return num;
        else{
            int index = (_num & (1 << _expo)) >> _expo;
            if(children[(index+1)%2] != nullptr && children[(index+1)%2]->size > 0)
                return children[(index+1)%2]->Find(_num, _expo - 1);
            else
                return children[index]->Find(_num, _expo - 1);
        }
    }
};

TrieNode* root;

int main()
{
    int test;
    scanf("%d",&test);
    
    root = new TrieNode();
    root->Add(0, MAX_EXPO);
    while(test--)
    {
        char ch;
        int num;
        scanf(" %c %d", &ch, &num);
        if(ch == '+')
            root->Add(num, MAX_EXPO);
        else if(ch == '-')
            root->Sub(num, MAX_EXPO);
        else
            printf("%d\n", num ^ root->Find(num, MAX_EXPO));
    }
    
    return 0;
}