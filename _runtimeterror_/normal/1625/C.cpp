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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif

const int N = 505;

ll dp[N][N];

int _runtimeTerror_()
{
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> d(n), a(n);
    for(int i=0;i<n;++i) {
        cin >> d[i];
    }
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    for(int i=0;i<=n;++i) {
        for(int j=0;j<=n;++j) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i=1;i<n;++i) {
        for(int j=0;j<i;++j) {
            int rm = 0;
            for(int k=i-1;k>=0;--k) {
                if(j >= rm) {
                    amin(dp[i][j], dp[k][j-rm] + a[k] * (d[i] - d[k]));
                }
                ++rm;
            }
        }
    }
    ll ans = INF;
    int rm = 0;
    for(int i=n-1;i>=0;--i) {
        for(int j=0;j<=k-rm;++j) {
            amin(ans, dp[i][j] + (l - d[i]) * a[i]);
        }
        ++rm;
    }
    cout << ans << "\n";
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
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}