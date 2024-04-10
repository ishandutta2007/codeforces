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

const int N = 110;
vector<pii> A[N];
int n;

int dfs(int u, int p)
{
    int ans = 0;
    for(auto e : A[u])
        if(e.F != p)
            ans = max(ans, dfs(e.F, u) + e.S);
    return ans;
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,1,n)
    {
        int u, v, c;
        cin >> u >> v >> c;
        A[u].push_back({v, c});
        A[v].push_back({u, c});
    }
    cout << dfs(0, -1) << '\n';
}