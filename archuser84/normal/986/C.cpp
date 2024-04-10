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

const int N = 22;
bool vis[1<<N] = {};
bool ex[1<<N] = {};
int n, m;
int mxn;

void dfs(int u)
{
    vis[u] = 1;
    Loop(i,0,n)
    {
        int v = (u | (1<<i))^(1<<i);
        if(!vis[v]) dfs(v);
    }
    if(ex[u] && !vis[mxn^u]) dfs(mxn^u);
}

int a[1<<N];

int main()
{
    FAST;
    cin >> n >> m; mxn = (1<<n)-1;
    Loop(i,0,m)
        cin >> a[i],
        ex[a[i]] = 1;
    int ans = 0;
    Loop(i,0,m)
    {
        if(!vis[a[i]])
            ans++,
            dfs(a[i]);
    }
    cout << ans << '\n';
}