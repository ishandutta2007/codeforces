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


int _runtimeTerror_()
{
    int n;
   	ll h;
   	cin >> n >> h;
   	vector<int> a(n+1);
   	for(int i=1;i<=n;++i) {
   		cin >> a[i];
   	}

   	auto good = [&](ll x) {
   		ll cnt = 0;
   		ll r = 0;
   		for(int i=1;i<=n;++i) {
   			amax(r, a[i]);
   			cnt += max(0ll, a[i] + x - r);
   			r = a[i] + x;
   		}
   		return cnt >= h;
   	};
   	ll lo = 1, hi = 1e18, ans = -1;
   	while(lo <= hi) {
   		ll mid = (lo + hi)/2;
   		if(good(mid)) {
   			ans = mid;
   			hi = mid - 1;
   		}
   		else {
   			lo = mid + 1;
   		}
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
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}