#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
using namespace std;

#define ll long long
#define SZ(x) (int)(x.size())
#define ALL(x) (x.begin(),x.end())
#define pb push_back

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<": "<<#__VA_ARGS__<<": ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T && x, S &&...y) {cerr<<x<<", "; _do(y...);}
#define IOS()
#else
#define IOS() ios::sync_with_stdio(0), cin.tie(0)
#define bug(...)
#define endl '\n'
#endif // BALBIT

const int maxn = 1e5+5;

int a[maxn], oa[maxn], ma[maxn];
double dp[maxn][110];
ll C[110][6];

double CC(int A, int B) {
    double re = 1;
    for (int i = 0; i<B; ++i) re *= (double)(A - i);
    for (int i = 2; i<=B; ++i) re /= i;
    return re;
}

signed main(){
    IOS();
    int n; cin>>n;
    double ans = 0;
    for (int i = 0; i<n; ++i) {
        cin>>a[i]; oa[i] = a[i]; ma[i] = a[i];
        dp[i][a[i]] = 1;
        if (a[i] == 0) ++ans;
    }
    for (int i = 0; i<110; ++i) {
        for (int j = 0; j<=min(i,5); ++j) {
            C[i][j] = 1;
            for (int k = 0; k<j; ++k) C[i][j] *= (ll)(i-k);
            for (int k = 1; k<=j; ++k) C[i][j] /= (ll)(k);
        }
    }
    bug(C[5][3]);
    int q; cin>>q;
    cout<<fixed<<setprecision(10);
    while (q--) {
        int u, v, k; cin>>u>>v>>k;
        --u; --v;
        if (dp[u][0] != 1){
            ans -= dp[u][0];
            ma[u] -= k; if (ma[u] < 0) ma[u] = 0;
    //        memcpy(tmp, dp[u], sizeof dp[u]);
            for (int x = ma[u]; x<=oa[u]; ++x) {
                if (k > a[u]-x) {
                    dp[u][x] = 0; continue;
                }
                dp[u][x] = dp[u][x+0] * C[x+0][0]  * CC(a[u] - (x+0),k-0);
                for (int m = 1; m<=k &&  a[u] - x-m >= k-m; ++m) {
                    dp[u][x] += dp[u][x+m] * C[x+m][m]  * CC(a[u] - (x+m),k-m);
                }
                dp[u][x] /= CC(a[u],k);
            }
            ans += dp[u][0];
        }
        a[u] -= k; a[v] += k;
        cout<<ans<<endl;
    }
}