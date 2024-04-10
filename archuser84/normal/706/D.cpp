#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

struct node
{
    node* child[2] = {};
    int cnt = 0;
}t;

inline bool Bit(int x, int i)
{
    return (x >> i) & 1;
}

void insert(int x)
{
    node* n = &t;
    LoopR(i,0,31)
    {
        bool bit = Bit(x, i);
        if(!(n->child[bit]))
            n->child[bit] = new node;
        n = n->child[bit];
        ++(n->cnt);
    }
}
void remove(int x)
{
    node* n = &t;
    LoopR(i,0,31)
    {
        bool bit = Bit(x, i);
        n = n->child[bit];
        --(n->cnt);
    }
}

int get_ans(int x)
{
    node* n = &t;
    int ans = 0;
    LoopR(i,0,31)
    {
        bool bit = Bit(x, i);
        if(n->child[!bit] && n->child[!bit]->cnt)
            (n = n->child[!bit]), (ans = 2*ans+1);
        else
            (n = n->child[bit]), (ans = 2*ans);
    }
    return ans;
}

int main()
{
    FAST;
    insert(0);
    int q;
    cin >> q;
    while(q--)
    {
        char c; int x;
        cin >> c >> x;
        switch(c)
        {
        case '+': insert(x); break;
        case '-': remove(x); break;
        case '?': cout << get_ans(x) << '\n'; break;
        }
    }
}