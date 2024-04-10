#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

const int Nmax = 100005;

int get_rand()
{
    int ret=rand()*rand();
    if(ret<0) ret=-ret;
    if(!ret) ret++;
    return ret;
}

struct Treap{
    int key, pry, size, count, maxs;
    long long sum;
    Treap *left, *right;
    Treap() {};
    Treap(int _key, int _pry, int _size, int _count, const long long _sum, const int _maxs, Treap* _left, Treap* _right)
    {
        key=_key;
        pry=_pry;
        size=_size;
        count=_count;
        sum=_sum;
        maxs=_maxs;
        left=_left;
        right=_right;
    }
};

Treap *Root, *NIL;

void Update(Treap* &node)
{
    node->size=node->left->size+node->right->size+node->count;
    node->sum=node->left->sum+node->right->sum+1LL*node->key*node->count;
    node->maxs=max(node->key, node->right->maxs);
}

void RotLeft(Treap* &node)
{
    Treap *t=node->left;
    node->left=t->right;
    t->right=node;
    node=t;

    Update(node->right);
    Update(node);
}

void RotRight(Treap* &node)
{
    Treap *t=node->right;
    node->right=t->left;
    t->left=node;
    node=t;

    Update(node->left);
    Update(node);
}

void Balance(Treap* &node)
{
    if(node->left->pry>node->pry) RotLeft(node);
    else if(node->right->pry>node->pry) RotRight(node);
}

long long S, Sump;
double Sol;
int Sz;

void Query(Treap* &node)
{
    if (node == NIL) return;

    double PP = double(Sump + node->left->sum + S + 1LL * node->key * node->count) / (Sz + node->left->size + node->count);

    if (PP >= node->key)
    {
        Sol = min(Sol, PP);
        Sump += node->left->sum + 1LL * node->key * node->count;
        Sz += node->left->size + node->count;

        Query(node->right);
    }
    else
    {
        Query(node->left);
    }
}

void Insert(Treap* &node, int key, int pry)
{
    if(node==NIL)
    {
        node=new Treap(key, pry, 1, 1, key, key, NIL, NIL);
        return;
    }
    if(key<node->key) Insert(node->left, key, pry);
    else if(key>node->key) Insert(node->right, key, pry);
    else node->count++;
    Balance(node);
    Update(node);
}

void Erase(Treap* &node, int key)
{
    if(node==NIL) return;

    if(key==node->key)
    {
        if(node->count>1)
        {
            node->count--;
        }
        else if(node->left==NIL&&node->right==NIL)
        {
            delete node;
            node=NIL;
            return;
        }
        else if(node->left->pry>node->right->pry)
        {
            RotLeft(node);
            Erase(node->right, key);
        }
        else
        {
            RotRight(node);
            Erase(node->left, key);
        }
    }
    else
    {
        if(key<node->key) Erase(node->left, key);
        else if(key>node->key) Erase(node->right, key);
    }

    Update(node);
}

void Init()
{
    srand(unsigned(time(0)));
    Root=NIL=new Treap(0, 0, 0, 0, 0, 0, NULL, NULL);
    NIL->left=NIL->right=NIL;
}

int A[Nmax];
long long SumT;

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

    Init();

    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &A[i]);
        SumT += A[i];

        Insert(Root, A[i], get_rand());
    }

    while (M--)
    {
        int op;
        scanf("%d", &op);

        if (op == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);

            SumT -= A[x];
            SumT += y;

            Erase(Root, A[x]);
            Insert(Root, y, get_rand());

            A[x] = y;
        }
        else
        {
            scanf("%I64d", &S);

            Sol = 1e17;
            Sump = 0;
            Sz = 0;
            Query(Root);

            printf("%.5f\n", Sol);
        }
    }
}