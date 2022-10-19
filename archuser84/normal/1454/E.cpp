#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 200'010;
vector<pii> A[N];
ll n;

bool vis[N];
bool gedge[N];
int dfs1(int u=0, int p=-1)
{
    vis[u] = 1;
    int ans = -1;
    for(auto& v : A[u])
        if(v.F != p && gedge[v.S])
        {
            if(vis[v.F]) gedge[v.S] = 0, ans = v.F;
            else
            {int t = dfs1(v.F, u);
            if(t != -1)
                gedge[v.S] = 0, ans = t;}
        }
    if(ans == u) return -1;
    return ans;
}

int dfs2(int u)
{
    vis[u] = 1;
    int ans = 0;
    for(auto& v : A[u])
        if(!vis[v.F] && gedge[v.S])
            ans += dfs2(v.F);
    ans++;
    return ans;
}

void solve()
{
    cin >> n;
    Loop(i,0,n) A[i].clear();
    Loop(i,0,n)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u].push_back({v, i});
        A[v].push_back({u, i});
    }
    memset(gedge, 1, n);
    memset(vis, 0, n); dfs1();
    memset(vis, 0, n);
    ll sum = 0;
    Loop(i,0,n)
    {
        if(vis[i]) continue;
        ll t = dfs2(i);
        sum += t*(t-1)/2;
    }
    cout << n*(n-1) - sum << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
        solve();
}