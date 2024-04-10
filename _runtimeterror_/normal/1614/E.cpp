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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T , null_type ,less<T> ,rb_tree_tag ,tree_order_statistics_node_update>;

int _runtimeTerror_()
{
    int n;
    cin >> n;
    ordered_set<int> s;
    int inc = 0;
    auto add = [&](int x) {
    	if(x < inc) {
    		--inc;
    		return ;
    	}
    	// need to compute x here
    	ll lo = 0, hi = 2e9, ans = -1;
    	while(lo <= hi) {
    		ll mid = (lo + hi)/2;
    		ll f = inc + mid - s.order_of_key(mid + 1);
    		if(f <= x) {
    			ans = mid;
    			lo = mid + 1;
    		}
    		else {
    			hi = mid - 1;
    		}
    	}
    	assert(ans != -1);
    	s.insert(ans + 1);
    	lo = 0, hi = 2e9, ans = -1;
    	while(lo <= hi) {
    		ll mid = (lo + hi)/2;
    		ll f = inc + mid - s.order_of_key(mid + 1);
    		if(f >= x) {
    			ans = mid;
    			hi = mid - 1;
    		}
    		else {
    			lo = mid + 1;
    		}
    	}
    	assert(ans != -1);
    	if(ans > 0) {
    		s.insert(ans);
    		++inc;
    	}
    };
    auto query = [&](int x) {
    	return inc + x - s.order_of_key(x + 1);
    };
    int last = 0;
    for(int d=0;d<n;++d) {
    	int T;
    	cin >> T;
    	int k;
    	cin >> k;
    	add(T);
    	for(int i=0;i<k;++i) {
    		int q;
    		cin >> q;
    		q = (q + last) % (1000000000 + 1);
    		cout << (last = query(q)) << "\n";
    	}
    }
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