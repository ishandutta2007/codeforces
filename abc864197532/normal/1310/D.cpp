#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second

auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

int main () {
    int n, k;
    cin >> n >> k;
    int dist[n][n];
    fop (i,0,n) {
        fop (j,0,n) {
            cin >> dist[i][j];
        }
    }
    int t = 0;
    int color[n];
    lli ans = 1ll << 60;
    while (t < 5000) {
        fop (i,0,n) {
            int tt = uniform_int_distribution<int>(1, n)(rng);
            color[i] = tt & 1;
        }
        lli dp[n][k];
        fop (j,0,k+1) {
            fop (i,0,n) {
                if (j) {
                    dp[i][j] = 1ll << 60;
                    fop (l,0,n) {
                        if (color[i] + color[l] == 1) {
                            dp[i][j] = min(dp[i][j], dp[l][j-1] + dist[l][i]);
                        }
                    }
                } else {
                    if (i) dp[i][j] = 1ll << 60;
                    else dp[i][j] = 0;
                }
            }
        }
        ans = min(ans, dp[0][k]);
        t++;
    }
    cout << ans << endl;
}