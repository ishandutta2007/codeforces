// Har Har Mahadev
#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif

const int N = 105;

int dp[N][N][N];
bool vis[N][N][N];
int mod;

int ncr[N][N], fac[N];

int dfs(int n, int m,int k) {
    // debug(n,m,k);
    if(n == 0) {
        return (k == 0) % mod;
    }
    if(m == 1) {
        return (k == 1) * fac[n];
    }
    if(m > n) {
        return (k == 0) * fac[n] % mod;
    }
    if(k > (n + 1)/2) {
        return 0;
    }
    if(vis[n][m][k]) {
        return dp[n][m][k];
    }
    vis[n][m][k] = 1;
    int &ans = dp[n][m][k];
    for(int i=1;i<=n;++i) {
        for(int j=0;j<=k;++j) {
            ans += dfs(i-1,m-1,j) * 1ll * dfs(n - i, m - 1, k - j) % mod * ncr[n-1][i-1] % mod;
            ans %= mod;
        }
    }
    return ans;
}


int _runtimeTerror_()
{
    int n,m,k;
    cin >> n >> m >> k >> mod;  
    for(int i=0;i<=n;++i) {
        ncr[i][0] = 1 % mod;
        if(i == 0) {
            fac[i] = 1 % mod;
        }
        else {
            fac[i] = fac[i-1] * 1ll * i % mod;
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=i;++j) {
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) % mod;
        }
    }
    cout << dfs(n,m,k) << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}