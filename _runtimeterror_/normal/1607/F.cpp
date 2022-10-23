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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n,vector<char>(m));
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(dp[i][j] >= 1) {
                amax(ans, dp[i][j]);
                continue;
            }
            vector<pii> v;
            int x = i, y = j;
            int cnt = 0;
            while(x < n && x >= 0 && y >= 0 && y < m) {
                if(dp[x][y] == 0) {
                    int cnt = 0;
                    vector<pii> t;
                    while(v.back() != make_pair(x, y)) {
                        ++cnt;
                        t.push_back(v.back());
                        v.pop_back();
                    }
                    t.push_back(v.back());
                    ++cnt;
                    v.pop_back();
                    for(auto &[f, g]:t) {
                        dp[f][g] = cnt;
                    }
                    while(!v.empty()) {
                        dp[v.back().F][v.back().S] = cnt + 1;
                        ++cnt;
                        v.pop_back();
                    }
                    break;
                }
                if(dp[x][y] > 0) {
                    cnt += dp[x][y];
                    break;
                }
                dp[x][y] = 0;
                int xx = x, yy = y;
                v.push_back({x, y});
                x += a[xx][yy] == 'D';
                x -= a[xx][yy] == 'U';
                y += a[xx][yy] == 'R';
                y -= a[xx][yy] == 'L';
            }
            while(!v.empty()) {
                dp[v.back().F][v.back().S] = cnt + 1;
                ++cnt;
                v.pop_back();
            }
            amax(ans, dp[i][j]);
        }

    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(ans == dp[i][j]) {
                cout << i + 1 << " " << j + 1 << " " << ans << "\n";
                return 0;
            }
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
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}