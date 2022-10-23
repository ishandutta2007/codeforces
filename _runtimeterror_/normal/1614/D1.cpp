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
#define debug(...) 2401
#endif

const int N = 5e6 + 5;

int f[N];
ll dp[N];

int _runtimeTerror_()
{
    int n;
    cin >> n;
    for(int i=0;i<n;++i) {
    	int x;
    	cin >> x;
    	++f[x];
    }
    n = 5e6;
    for(int i=1;i<=n;++i) {
    	int cnt = 0;
    	for(int j=i;j<=n;j+=i) {
    		cnt += f[j];
    	}
    	f[i] = cnt;
    }
    ll ans = 0;
    for(int i=1;i<=n;++i) {
    	amax(dp[i], f[i] * 1ll * i);
    	for(int j=2*i;j<=n;j+=i) {
    		// assert(f[i] >= f[j]);
    		// debug(dp[i] + f[j] * 1ll * j - (f[i] - f[j]) * 1ll * i);
    		amax(dp[j], dp[i] + f[j] * 1ll * j - (f[j]) * 1ll * i);
    	}
    	amax(ans, dp[i]);
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
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}