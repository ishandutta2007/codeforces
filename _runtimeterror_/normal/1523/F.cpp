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

const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif


const int N = 14, M = 102;
ll F[1 << N][M+2], G[1 << N][M];

ll pre[N][1 << N], pre2[M][1 << N];

int _runtimeTerror_()
{
    int n, m;
    cin >> n >> m;
    vector<int> xa(n), ya(n);
    for(int i=0;i<n;++i) {
        cin >> xa[i] >> ya[i];
    }
    vector<array<int,3>> quest(m);
    for(int i=0;i<m;++i) {
        cin >> quest[i][1] >> quest[i][2] >> quest[i][0];
    }
    sort(all(quest));
    for(int i=0;i<n;++i) {
        pre[i][0] = INF;
        for(int j=1;j<(1<<n);++j) {
            int last = log2(j & -j);
            pre[i][j] = abs(xa[i] - xa[last]) + abs(ya[i] - ya[last]);
            amin(pre[i][j], pre[i][j^(1 << last)]);
        }
    }
    for(int i=0;i<m;++i) {
        pre2[i][0] = INF;
        for(int j=1;j<(1<<n);++j) {
            int last = log2(j & -j);
            pre2[i][j] = abs(quest[i][1] - xa[last]) + abs(quest[i][2] - ya[last]);
            amin(pre2[i][j], pre2[i][j^(1 << last)]);
        }
    }
    for(int i=0;i<(1<<n);++i) {
        for(int j=0;j<m;++j) {
            F[i][j] = INF;
            G[i][j] = -INF;
        }
    }
    for(int i=0;i<n;++i) {
        F[1 << i][0] = 0;
    }
    for(int i=0;i<m;++i) {
        G[0][i] = 1;
    }
    ll ans = 0;
    for(int i=0;i<(1 << n);++i) {
        for(int j=0;j<m;++j) {
            for(int k=0;k<m;++k) {
                if(F[i][j] + pre2[k][i] <= quest[k][0]) {
                    amax(G[i][k], j + 1);
                }
                if(k > j && quest[j][0] + min(pre2[k][i], 1ll*abs(quest[j][2] - quest[k][2]) + abs(quest[j][1] - quest[k][1])) <= quest[k][0]) {
                    amax(G[i][k], G[i][j] + 1);
                }
            }
            for(int k=0;k<n;++k) {
                if((i & (1 << k)) == 0) {
                    amin(F[i ^ (1 << k)][j], F[i][j] + pre[k][i]);
                    if(G[i][j] >= 0 and G[i][j] <= m) {
                        amin(F[i ^ (1 << k)][G[i][j]], quest[j][0] + min(pre[k][i], 1ll*abs(quest[j][1] - xa[k]) + abs(quest[j][2] - ya[k])));
                    }
                }
            }
            amax(ans, G[i][j]);
        }
    }
    cout << ans << "\n";
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