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
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 200'010;
vector<int> A[N];
map<int, vector<int>> aa;
int a[N];
int st[N], ft[N];
vector<int> layer[N];
int d[N];
int n, m;

namespace seg
{
    ll t[N << 2] = {};
    ll lazy[N << 2] = {};

    inline int lc(int x){return 2*x+1;}
    inline int rc(int x){return 2*x+2;}

    inline void ppg(int i, int b, int m, int e)
    {
        if(lazy[i] == 0) return;
        t[lc(i)] += (m-b) * lazy[i];
        t[rc(i)] += (e-m) * lazy[i];
        lazy[lc(i)] += lazy[i];
        lazy[rc(i)] += lazy[i];
        lazy[i] = 0;
    }

    void add(int i, ll v, int l, int r, int b, int e)
    {
        if(l <= b && e <= r){
            t[i] += v*(e-b);
            lazy[i] += v;
            return;
        }
        if(r <= b || e <= l) return;
        int m = (b+e)/2;
        ppg(i, b, m, e);
        add(lc(i), v, l, r, b, m);
        add(rc(i), v, l, r, m, e);
    }

    ll get(int i, int p, int b, int e)
    {
        if(b+1 == e) return t[i];
        int m = (b+e)/2;
        ppg(i, b, m, e);
        if(p < m) return get(lc(i), p, b, m);
        else      return get(rc(i), p, m, e);
    }

    void add(int l, int r, int v){ add(0, v, l, r, 1, n+1); }
    ll get(int p){ return get(0, p, 1, n+1); }
}

void dfs(int u, int p = -1, int d = 0, int& t = *new int(1))
{
    st[u] = t++;
    ::d[u] = d;
    layer[d].push_back(u);
    for(int v : A[u])
        if(v != p)
            dfs(v, u, d+1, t);
    ft[u] = t;
}

int bin(int u, int v)
{
    auto& a = layer[d[u]+1];
    int l = 0, r = a.size() - 1;
    while(l < r)
    {
        int m = (l+r+1)/2;
        if(st[a[m]] > st[v])
            r = m-1;
        else
            l = m;
    }
    return a[l];
}

map<int, vector<int>> par;
map<int, int> cnt;
bool ptag[N] = {};

bool dfs2(int u, int p = -1)
{
    if(par[a[u]].size() > 1) return 0;
    if(par[a[u]].size() == 1){
        seg::add(1, n+1, 1);
        int w = bin(par[a[u]][0], u);
        seg::add(st[w], ft[w], -1);
        ptag[par[a[u]][0]] = 1;
    }
    par[a[u]].push_back(u);
    for(int v : A[u])
        if(v != p)
            if(!dfs2(v, u))
                return 0;
    if(!ptag[u]) par[a[u]].pop_back();
    return 1;
}

bool dfs3(int u, int p = -1)
{
    if(par[a[u]].size() && st[par[a[u]][0]] > st[u] || ft[par[a[u]][0]] <= st[u]) return 0;
    for(int v : A[u])
        if(v != p)
            if(!dfs3(v, u))
                return 0;
    return 1;
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
    {
        cin >> a[i+1];
        aa[a[i+1]].push_back(i+1);
    }
    Loop(i,1,n)
    {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    dfs(1);
    if(!dfs2(1)) Kill(0);
    if(!dfs3(1)) Kill(0);
    for(auto& c : aa)
        for(int& v : c.S)
            if(c.S.size() > 1 && !ptag[v])
                seg::add(st[v], ft[v], 1);
    int ans = 0;
    Loop(i,1,n+1)
        if(!seg::get(st[i]))
            ++ans;
    cout << ans << '\n';
}