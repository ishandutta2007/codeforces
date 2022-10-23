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
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> psum(n+1,vector<int>(2,0));
    for(int i=1;i<=n;++i) {
        psum[i][0] = psum[i-1][0] + (i % 2 == 0 && (s[i-1] == '[' || s[i-1] == ']'));
        psum[i][1] = psum[i-1][1] + (i % 2 == 1 && (s[i-1] == '[' || s[i-1] == ']'));
    }
    int Q;
    cin >> Q;
    for(int i=1;i<=Q;++i) {
        int l, r;
        cin >> l >> r;
        int f = psum[r][0] - psum[l-1][0], g = psum[r][1] - psum[l-1][1];
        cout << abs(f - g) << "\n";
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