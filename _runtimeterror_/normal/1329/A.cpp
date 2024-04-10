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
    int n, m;
    cin >> n >> m;
    vector<int> a(m+1);
    for(int i=1;i<=m;++i)
        cin >> a[i];
    if(accumulate(all(a),0ll) < n) {
        cout << "-1\n";
        return 0;
    }
    for(int i=1;i<=m;++i)
    {
        if(i + a[i] - 1 > n) {
            cout << "-1\n";
            return 0;
        }
    }
    vector<int> pmax(m+1,0),ans(m+1);
    for(int i=1;i<=m;++i) {
        pmax[i] = (pmax[i-1], i + a[i] - 1);
        ans[i] = i;
    }
    int last = n;
    for(int i=m;i>=1;--i)
    {
        if(pmax[i] >= last) {
            break;
        }
        last -= a[i];
        ans[i] = last + 1;
    }
    for(int i=1;i<=m;++i)
    {
        cout << ans[i] << " ";
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