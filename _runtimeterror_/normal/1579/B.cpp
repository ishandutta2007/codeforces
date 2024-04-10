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


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    vector<pair<int,pii>> ops;
    for(int i=0;i<n;++i) {
        auto it = min_element(i+all(a)) - a.begin();
        if(it == i) {
            continue;
        }
        ops.push_back({i+1,{n,it-i}});
        vector<int> tmp = a;
        int len = n - i;
        int sh = it - i;
        for(int j=0;j<len;++j) {
            a[i+j] = tmp[i + (j + sh)%len];
        }
        // debug(a);
    }
    cout << sz(ops) << "\n";
    for(auto &[i,j]:ops) {
        cout << i << " " << j.F << " " << j.S << "\n";
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
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}