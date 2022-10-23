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
#define debug(...) 2401
#endif

const int N = 1005;

ll dp[N][N][4];

int st[N][N];

int _runtimeTerror_()
{
    int n, m, Q;
    cin >> n >> m >> Q;
    ll ans = 0; 
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            dp[i][j][3] = dp[i][j-1][2] + 1;
            dp[i][j][2] = dp[i-1][j][3] + 1;
        }
    }
    for(int i=n;i>=1;--i) {
        for(int j=m;j>=1;--j) {
            dp[i][j][0] = dp[i][j+1][1] + 1;
            dp[i][j][1] = dp[i+1][j][0] + 1;
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            ans += dp[i][j][0] + dp[i][j][1] - 1;
        }
    }
    auto go = [&](int x,int y) {
        int it = 0;
        int i = x, j = y;
        auto upd1 = [&](int i,int j) {
            if(i < 1 || i > n || j < 1 || j > m) {
                return ;
            }
            if(st[i][j] == 1) {
                return ;
            }
            dp[i][j][3] = dp[i][j-1][2] + 1;
            dp[i][j][2] = dp[i-1][j][3] + 1;
        };
        while(true) {
            upd1(i+1,j);
            upd1(i,j+1);
            upd1(i+1,j+1);
            i += 1, j += 1;
            if(i > n || j > m) {
                break;
            }
        }
        auto upd2 = [&](int i,int j) {
            if(i < 1 || i > n || j < 1 || j > m) {
                return ;
            }
            if(st[i][j] == 1) {
                return ;
            }
            dp[i][j][0] = dp[i][j+1][1] + 1;
            dp[i][j][1] = dp[i+1][j][0] + 1;
        };
        i = x, j = y;
        while(true) {
            upd2(i-1,j);
            upd2(i,j-1);
            upd2(i-1,j-1);
            i -= 1, j -= 1;
            if(i < 1 || j < 1) {
                break;
            }
        }
    };
    auto update = [&](int x,int y) {
        if(st[x][y]) {
            int i = x, j = y;
            dp[i][j][3] = dp[i][j-1][2] + 1;
            dp[i][j][2] = dp[i-1][j][3] + 1;
            dp[i][j][0] = dp[i][j+1][1] + 1;
            dp[i][j][1] = dp[i+1][j][0] + 1;
            ans += dp[i][j][0] * dp[i][j][2];
            ans += dp[i][j][1] * dp[i][j][3];
            ans -= 1;
            go(x, y);
        }
        else {
            int i = x, j = y;
            ans -= dp[i][j][0] * dp[i][j][2];
            ans -= dp[i][j][1] * dp[i][j][3];
            ans += 1;
            dp[i][j][3] = 0;
            dp[i][j][2] = 0;
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
            go(x, y);
        }
        st[x][y] ^= 1;
    };  
    for(int i=1;i<=Q;++i) {
        int x, y;
        cin >> x >> y;
        update(x, y);
        assert(ans >= 0);
        cout << ans << "\n";
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