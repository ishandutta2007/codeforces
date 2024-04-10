#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 1'000'010;
vector<int> A[N];
ll d[N] = {};
ll lp = 0;
int n, m;

bool vis[N] = {};
int dfs(int u)
{
    int ans = 1;
    vis[u] = 1;
    for(int v : A[u])
        if(!vis[v])
            ans += dfs(v);
    return ans;
}

int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,0,m)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        d[u]++; d[v]++;
        if(v == u) ++lp;
        else{
            A[u].push_back(v);
            A[v].push_back(u);
        }
    }
    int iso = 0;
    Loop(i,0,n) if(d[i] == 0) iso++;
    Loop(i,0,n) {
        if(d[i] == 0) continue;
        if(dfs(i) != n - iso) Kill(0);
        else break;
    }
    ll ans = 0;
    ans += lp*(lp-1)/2;
    ans += lp*(m-lp);
    Loop(i,0,n) ans += ll(A[i].size()) * (A[i].size()-1)/2;
    cout << ans << '\n';
}