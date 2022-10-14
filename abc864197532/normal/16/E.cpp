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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	double pos[n][n];
	fop (i,0,n) fop (j,0,n) cin >> pos[i][j];
	double dp[1 << n];
	fop (i,0,1 << n) dp[i] = 0;
	dp[(1 << n) - 1] = 1;
	FOP (s,(1 << n),0) {
		int c = __builtin_popcount(s);
		c = c * (c - 1) / 2;
		fop (i,0,n) if (s & (1 << i)) {
			fop (j,i + 1,n) if (s & (1 << j)) {
				dp[s ^ (1 << i)] += (dp[s] * pos[j][i]) / c;
				dp[s ^ (1 << j)] += (dp[s] * pos[i][j]) / c;
			}
		}
	}
	fop (i,0,n) cout << fixed << setprecision(8) << dp[1 << i] << " \n"[i == n - 1];
}