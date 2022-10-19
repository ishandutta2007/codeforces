///
///    I have a dream and a piano
///

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

const int N = 1e5+10;
vector<int> A[N];
vector<int> l[N];
int ans[N];
int st[N], ft[N];
int n, m;

namespace seg
{
    pii t[N<<2];
    int l[N<<2];

    inline pii min(pii x, pii y)
    {
        if(x.F == y.F) x.S += y.S;
        return x.F > y.F? y: x;
    }

    inline void ppg(int i)
    {
        if(l[i])
        {
            t[2*i+1].F += l[i];
            t[2*i+2].F += l[i];
            l[2*i+1] += l[i];
            l[2*i+2] += l[i];
            l[i] = 0;
        }
    }

    void add(int l, int r, int x, int i=0, int b=0, int e=N)
    {
        if(l <= b && e <= r) {t[i].F += x; seg::l[i] += x; return;}
        if(r <= b || e <= l) return;
        ppg(i);
        add(l,r,x,2*i+1,b,(b+e)/2);
        add(l,r,x,2*i+2,(b+e)/2,e);
        t[i] = min(t[2*i+1], t[2*i+2]);
    }

    void init(int i=0, int b=0, int e=N)
    {
        t[i] = {0,e-b};
        if(e-b > 1)
        {
            init(2*i+1,b,(b+e)/2);
            init(2*i+2,(b+e)/2,e);
        }
    }
}

void dfs1(int v, int p=-1, int& t = *new int(0))
{
    st[v] = t++;
    for(int u : A[v])
        if(u != p)
            dfs1(u,v,t);
    ft[v] = t;
}

void dfs2(int v, int p=-1)
{
    for(int u : l[v]) seg::add(st[u], ft[u], 1);
    seg::add(st[v], ft[v], l[v].size());
    ans[v] = seg::t[0].F? n-1: max(0, N-seg::t[0].S-1);
    for(int u : A[v])
        if(u != p)
            dfs2(u, v);
    for(int u : l[v]) seg::add(st[u], ft[u], -1);
    seg::add(st[v], ft[v], -l[v].size());
}

int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,1,n)
    {
        int v, u;
        cin >> v >> u;
        --v; --u;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    Loop(i,0,m)
    {
        int v, u;
        cin >> v >> u;
        --v; --u;
        l[u].push_back(v);
        l[v].push_back(u);
    }
    seg::init();
    dfs1(0);
    dfs2(0);
    Loop(i,0,n) cout << ans[i] << ' ';
}