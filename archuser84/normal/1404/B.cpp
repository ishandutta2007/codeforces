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

const int N = 100'010;
vector<int> A[N];
int dis[N];
int md;
int n, a, b, da, db;

void reset()
{
    memset(dis, 0, 4*n);
    Loop(i,0,n)
        A[i].clear();
    md = a;
}

void dfs(int u, int p, int d)
{
    dis[u] = d;
    if(d > dis[md])
        md = u;
    for(int v : A[u])
        if(v != p)
            dfs(v, u, d+1);
}

int solve()
{
    cin >> n >> a >> b >> da >> db;
    a--; b--;
    reset();
    Loop(i,1,n)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    if(db <= 2*da)
        Kill("Alice");
    dfs(a,-1,0);
    if(dis[b] <= da)
        Kill("Alice");
    dfs(md,-1,0);
    if(dis[md] <= 2*da)
        Kill("Alice");
    Kill("Bob");
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}