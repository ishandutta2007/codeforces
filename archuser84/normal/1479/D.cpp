#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

const int N = 300'010;
const int lgN = 19;
int n;
ll w[N];
int c[N];

#pragma GCC push_options
#pragma GCC optimize ("O0")
void calc_rand()
{
    Loop(i,0,N)
    {
        asm("rdrand %0" : "=r"(w[i]));
    }
}
#pragma GCC pop_options

namespace seg
{
    struct node
    {
        node *l, *r;
        ll cnt;

        node(node* le, node* ri) : l(le), r(ri), cnt(le->cnt ^ ri->cnt) {}
        node(ll v) : l(0), r(0), cnt(v) {}
    };

    node* build(int b = 0, int e = n)
    {
        if(b+1 == e) return new node(0);
        return new node(build(b, (b+e)/2), build((b+e)/2, e));
    }

    node* update(node* t, int p, int b = 0, int e = n)
    {
        if(b+1 == e) return new node(t->cnt ^ w[b]);
        int m = (b+e)/2;
        if(p < m) return new node(update(t->l, p, b, m), t->r);
        else      return new node(t->l, update(t->r, p, m, e));
    }

    int odd(array<node*, 4> t, int l, int r, int b = 0, int e = n)
    {
        if(b+1 == e) return b+1;
        int lx = t[0]->l->cnt ^ t[1]->l->cnt ^ t[2]->l->cnt ^ t[3]->l->cnt;
        int rx = t[0]->r->cnt ^ t[1]->r->cnt ^ t[2]->r->cnt ^ t[3]->r->cnt;
        int m = (b+e)/2;
        if(lx && l < m && t[0]->l){
            int x = odd({t[0]->l,t[1]->l,t[2]->l,t[3]->l}, l, r, b, m);
            if(x != -1) return x;
        }
        if(rx && m < r && t[0]->r){
            int x = odd({t[0]->r,t[1]->r,t[2]->r,t[3]->r}, l, r, m, e);
            if(x != -1) return x;
        }
        return -1;
    }
}
seg::node* rt[N];
vector<int> A[N];

namespace lca
{
    int d[N];
    int anc[lgN][N];

    void dfs(int u, int par, seg::node* sg, int h)
    {
        d[u] = h;
        rt[u] = sg;
        anc[0][u] = par;
        Loop(k,1,lgN) anc[k][u] = anc[k-1][anc[k-1][u]];
        for(int v : A[u])
            if(v != par)
                dfs(v, u, seg::update(sg, c[v]), h+1);
    }

    int lca(int a, int b)
    {
        if(d[a] > d[b]) swap(a, b);
        LoopR(k,0,lgN)
            if(d[b] - (1<<k) >= d[a])
                b = anc[k][b];
        if(a == b) return a;
        LoopR(k,0,lgN)
            if(anc[k][a] != anc[k][b])
                a = anc[k][a],
                b = anc[k][b];
        return anc[0][a];
    }
}

int main()
{
    FAST;
    calc_rand();
    int q;
    cin >> n >> q;
    Loop(i,0,n) cin >> c[i], c[i]--;
    Loop(i,1,n)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    A[n].push_back(0);
    lca::dfs(n, n, seg::build(), 0);
    while(q--)
    {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        u--; v--; l--;
        int a = lca::lca(u, v);
        cout << seg::odd({rt[u], rt[v], rt[a], rt[lca::anc[0][a]]}, l, r) << '\n';
    }
}