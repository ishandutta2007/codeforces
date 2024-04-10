// Jai Mahakal
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
    int h,w;
    cin >> h >> w;
    vector<vector<int>> ans(h,vector<int>(w,0));
    ans[0][0] = ans[h-1][0] = ans[0][w-1] = ans[h-1][w-1] = 1;
    for(int i=2;i<=w-3;i+=2)
        ans[0][i] = ans[h-1][i] = 1;
    for(int i=2;i<=h-3;i+=2)
        ans[i][0] = ans[i][w-1] = 1;
    for(int i=0;i<h;++i)
    {
        for(int j=0;j<w;++j)
            cout << ans[i][j];
        cout << "\n";
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
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}