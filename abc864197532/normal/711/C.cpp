#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int x = 864197532, N = 1000001, logN = 17;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector <int> color(n);
	fop (i,0,n) cin >> color[i], color[i]--;
	vector <vector <int>> cost(n, vector <int>(m));
	fop (i,0,n) fop (j,0,m) cin >> cost[i][j];
	lli dp[n][m][k + 1];
	fop (i,0,n) fop (j,0,m) fop (_,0,k + 1) dp[i][j][_] = 1ll << 60;
	fop (i,0,m) dp[0][i][1] = (color[0] == -1 ? cost[0][i] : (color[0] == i ? 0 : 1ll << 60));
	fop (i,1,n) {
	    fop (_,1,k + 1) {
            if (color[i] == -1) {
                fop (j,0,m) {
                    dp[i][j][_] = min(dp[i][j][_], dp[i - 1][j][_] + cost[i][j]);
                    fop (ii,0,m) if (ii != j) {
                        dp[i][j][_] = min(dp[i][j][_], dp[i - 1][ii][_ - 1] + cost[i][j]);
                    }
                }
            } else {
                fop (j,0,m) {
                    if (color[i] == j) {
                        dp[i][j][_] = dp[i - 1][j][_];
                        fop (ii,0,m) if (ii != j) {
                            dp[i][j][_] = min(dp[i][j][_], dp[i - 1][ii][_ - 1]);
                        }
                    } else {
                        dp[i][j][_] = 1ll << 60;
                    }
                }
            }
	    }
	}
	lli ans = 1ll << 60;
	fop (i,0,m) ans = min(ans, dp[n - 1][i][k]);
	if (ans == 1ll << 60) ans = -1;
	cout << ans << endl;
}