#include<bits/stdc++.h>
using namespace std;

const int BASE = 30;
const uint32_t INF = (uint32_t(1)<<BASE) - 1;
struct Node
{
    Node *L;
    Node *R;
    int count;
    Node()
    {
        L = R = nullptr;
        count = 0;
    }
    uint32_t erasemin(uint32_t x, int b)
    {
        --count;
        if(b==0) return 0;
        if(x&(uint32_t(1)<<(b-1)))
        {
            if(R && R->count != 0)
                return R->erasemin(x, b-1);
            else
            {
                return (uint32_t(1)<<(b-1)) + L->erasemin(x, b-1);
            }
        }
        else
        {
            if(L && L->count != 0)
                return L->erasemin(x, b-1);
            else
            {
                return (uint32_t(1)<<(b-1)) + R->erasemin(x, b-1);
            }
        }
    }
    void ins(uint32_t x)
    {
        Node *p = this;
        p->count++;
        for(int i=BASE-1; i>=0; --i)
        {
            if(!(x&(uint32_t(1)<<i)))
            {
                if(!p->L) p->L = new Node();
                p = p->L;
            }
            else
            {
                if(!p->R) p->R = new Node();
                p = p->R;
            }
            p->count++;
        }
    }
};

Node *root;
int N;
uint32_t A[303030];
uint32_t P[303030];
int main()
{
    cin >> N;
    for(int i=0; i<N; ++i) cin >> A[i];
    for(int i=0; i<N; ++i) cin >> P[i];
    root = new Node();
    for(int i=0; i<N; ++i)
        root->ins(P[i]);
    for(int i=0; i<N; ++i)
        cout << root->erasemin(A[i], BASE) << " ";
    cout << endl;
}