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
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=k;++i) {
        int c;
        cin >> c;
        pii cur = {1, c};
        while(cur.F <= n) {
            auto [x,y] = cur;
            if(a[x][y] == 2) {
                ++cur.F;
                continue;
            }
            if(a[x][y] == 3) {
                --cur.S;
            }
            else {
                ++cur.S;
            }   
            a[x][y] = 2;
        }
        cout << cur.S << " ";
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