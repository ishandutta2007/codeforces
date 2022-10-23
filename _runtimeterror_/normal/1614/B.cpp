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
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;++i) {
    	cin >> a[i];
    }
    vector<int> b, c;
    for(int i=1;sz(b)<n;++i) {
    	b.push_back(i);
    	b.push_back(i);
    	c.push_back(i);
    	c.push_back(-i);
    }
    vector<int> id(n);
    iota(all(id),0);
    sort(all(id), [&](int x,int y) {
    	return a[x] > a[y];
    });
    ll ans = 0;
    vector<int> p(n);
    for(int i=0;i<n;++i) {
    	p[id[i]] = c[i];
    	ans += a[id[i]] * 1ll * b[i] * 2;
    }
    cout << ans << "\n";
    cout << "0 ";
    for(int i=0;i<n;++i) {
    	cout << p[i] <<  " ";
    }
    cout << "\n";
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