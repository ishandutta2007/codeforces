#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
#define ull uint64_t
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

const int N = 200'010;
int a[N];
vector<int> A[N];
int n;

pii dfs(int u, int p = -1, int l = 0)
{
    pii ans = {0, u};
    for(int v : A[u])
        if(v != p)
            ans = max(ans, dfs(v, u, a[u]? a[u]: l));
    return {ans.F + (l+a[u] == 3 || (a[u] && !l)), ans.S};
}

void solve()
{
    cin >> n;
    Loop(i,0,n) cin >> a[i], A[i].clear();
    Loop(i,1,n)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    //cout << dfs(0).S << ' ';
    cout << (dfs(dfs(0).S).F)/2+1 << '\n';
}

int main()
{
    FAST;
    int t;
    cin >> t;
    while(t--) solve();
}