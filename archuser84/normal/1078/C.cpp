///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

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
//#pragma GCC optimize("O0")

const int mod = 998244353;
const int N = 300'010;

vector<int> A[N];
int n;

ll mpow(ll x, ll e)
{
    ll ans = 1;
    while(e)
    {
        if(e&1) ans = ans*x % mod;
        x = x*x % mod;
        e >>= 1;
    }
    return ans;
}

// yal nadare, dare vasl nist, dare vasl hast
tuple<ll,ll,ll> dfs(int v, int p)
{
    vector<tuple<ll,ll,ll>> c;
    for(int u : A[v])
        if(u != p)
            c.push_back(dfs(u, v));
    ll p3 = 1;
    for(auto [x,y,z] : c)
        p3 = p3*(x+y) % mod;
    ll p2 = 0;
    for(auto [x,y,z] : c)
        p2 = (p2 + (z*p3%mod)*mpow(x+y,mod-2)) % mod;
    ll p1 = 1;
    for(auto [x,y,z] : c)
        p1 = p1*x % mod;
    p1 = (p1 + p2) % mod;
    return {p1,p2,p3};
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,1,n)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    cout << get<0>(dfs(0, -1));
}