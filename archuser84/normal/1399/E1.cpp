#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) {cout << x << '\n'; return 0;}
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int N = 200'010;
vector<int> A[N];
int subs[N];
int vist[N];
pair<pii, ll> E[N];
int n;

int dfs(int u, int par, int& time)
{
    vist[u] = time++;
    subs[u] = 0;
    bool found = 0;
    for(auto v : A[u])
        if(v != par)
        {
            found = 1;
            subs[u] += dfs(v, u, time);
        }
    if(!found)
        subs[u] = 1;
    return subs[u];
}

void solve()
{
    priority_queue<pair<ll, int>> H;
    ll Sss, sum = 0;
    cin >> n >> Sss;
    Loop(i,0,n)
        A[i].clear();
    Loop(i,0,n-1)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        E[i].F.F = u; E[i].F.S = v;
        E[i].S = w;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    int dummy = 0;
    dfs(0, -1, dummy);
    Loop(i,0,n-1)
    {
        if(vist[E[i].F.F] < vist[E[i].F.S])
            swap(E[i].F.F, E[i].F.S);
        H.push({(E[i].S+1)/2 * subs[E[i].F.F], i});
        sum += E[i].S * subs[E[i].F.F];
    }
    int ans = 0;
    while(sum > Sss)
    {
        int i = H.top().second;
        H.pop();
        sum -= E[i].S * subs[E[i].F.F];
        E[i].S /= 2;
        H.push({(E[i].S+1)/2 * subs[E[i].F.F], i});
        sum += E[i].S * subs[E[i].F.F];
        ans++;
    }
    cout << ans << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--)
    solve();
}