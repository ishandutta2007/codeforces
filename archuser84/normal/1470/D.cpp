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

const int N = 300'010;
vector<int> A[N];
vector<int> V;
bool ans[N];
bool vis[N];
int cnt;
int n, m;

void rsolve()
{
    if(V.size() == 0) return;
    int u = V.back();
    V.pop_back();
    rsolve();
    for(int v : A[u])
        if(ans[v])
            return;
    ans[u] = 1;
    ++cnt;
}

void dfs(int u)
{
    vis[u] = 1;
    for(int v : A[u])
        if(!vis[v])
            dfs(v);
    V.push_back(u);
}

void solve()
{
    cin >> n >> m;

    Loop(i,0,n) A[i].clear();
    V.clear();
    memset(vis, 0, n);
    memset(ans, 0, n);
    cnt = 0;

    Loop(i,0,m)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    dfs(0);
    if(V.size() < n){cout << "NO\n"; return;}
    reverse(all(V));
    rsolve();
    cout << "YES\n" << cnt << '\n';
    Loop(i,0,n)
        if(ans[i])
            cout << i+1 << ' ';
    cout << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}