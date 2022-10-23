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


int _runtimeTerror_()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n+1, vector<char>(m+1));
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    vector<vector<int>> cnt(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            cin >> a[i][j];
        }
    }
    auto ans = a;
    vector<pii> q;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            for(int k=0;k<4;++k) {
                int x = i + dx[k], y = j + dy[k];
                if(x >= 1 and x <= n and y >= 1 and y <= m && a[x][y] != '#') {
                    ++cnt[i][j];
                }
            }
            if(a[i][j] == 'L') {
                q.push_back({i, j});
            }
        }
    }
    vector<vector<bool>> vis(n+1,vector<bool>(m+1,0));

    while(!q.empty()) {
        vector<pii> nq;

        for(auto &[x, y]:q) {
            vis[x][y] = 1;
            for(int i=0;i<4;++i) {
                int xx = x + dx[i], yy = y + dy[i];
                if(xx >= 1 and xx <= n and yy >= 1 and yy <= m && a[xx][yy] == '.' && !vis[xx][yy]) {
                    --cnt[xx][yy];
                    if(cnt[xx][yy] <= 1) {
                        nq.push_back({xx, yy});
                        ans[xx][yy] = '+';
                        vis[xx][yy] = 1;
                    }
                }
            }
        }
        swap(q, nq);
    }

    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            cout << ans[i][j];
        }
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
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}