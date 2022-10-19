///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize("O0")

mt19937 rd(time(0));
const int mod = 1e9 + 7;
const int N = 300'010;
ll pow2[N];
ll pow2i[N];
int n;

namespace treap
{
    struct node
    {
        ll X = 0, Y = 0;
        ll ans = 0;
        int cnt = 1; ll v=0;
        int pr = rd();
        node *l = 0, *r = 0;
        node(ll x)
        {
            X = x;
            Y = x;
            v = x;
        }
    };

    inline void update(node* T)
    {
        T->X = T->v;
        T->Y = T->v;
        T->cnt = 1;
        T->ans = 0;
        if(T->l)
        {
            T->cnt += T->l->cnt;
            T->X = T->X*pow2[T->l->cnt] % mod;
            T->Y = T->Y*pow2i[T->l->cnt] % mod;
            T->ans += T->l->ans;
            T->ans += T->l->X*T->Y % mod;
            T->X += T->l->X;
            T->Y += T->l->Y;
        }
        if(T->r)
        {
            T->ans += T->r->ans;
            T->ans += T->X*T->r->Y % mod * pow2i[T->cnt] % mod;
            T->X += T->r->X*pow2[T->cnt] % mod;
            T->Y += T->r->Y*pow2i[T->cnt] % mod;
            T->cnt += T->r->cnt;
        }
        T->ans %= mod;
        T->X %= mod;
        T->Y %= mod;
    }

    void merge(node* &T, node* L, node* R)
    {
        if(!L) {T = R; return;}
        if(!R) {T = L; return;}
        if(L->pr > R->pr)
        {
            T = L;
            merge(L->r, L->r, R);
        }
        else
        {
            T = R;
            merge(R->l, L, R->l);
        }
        update(T);
    }

    void split(node* T, node* &L, node* &R, int x)
    {
        if(!T){L=R=0; return;}
        if(T->v < x)
        {
            L = T;
            split(T->r, T->r, R, x);
            update(T);
        }
        else
        {
            R = T;
            split(T->l, L, T->l, x);
            update(T);
        }
    }

    void erasemin(node* T, node* &R)
    {
        if(!T->l)
        {
            R = T->r;
            delete T;
            return;
        }
        R = T;
        erasemin(T->l, T->l);
        update(T);
    }
}

int a[N];
int b[N];

int main()
{
    FAST;
    pow2[0] = pow2i[0] = 1;
    Loop(k,1,N) pow2[k] = pow2[k-1]*2 % mod;
    Loop(k,1,N) pow2i[k] = pow2i[k-1]*500000004 % mod;
    treap::node* t = 0;
    cin >> n;
    Loop(i,0,n)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    Loop(i,0,n) treap::merge(t, t, new treap::node(b[i]));
    cout << t->ans*500000004 % mod << '\n';
    int q;
    cin >> q;
    while(q--)
    {
        int i, x;
        cin >> i >> x; --i;
        treap::node *A=0, *B=0;
        treap::split(t, A, B, a[i]);
        treap::erasemin(B, B);
        treap::merge(t, A, B);
        a[i] = x;
        treap::split(t, A, B, a[i]);
        treap::merge(B, new treap::node(a[i]), B);
        treap::merge(t, A, B);
        cout << t->ans*500000004 % mod << '\n';
    }
}