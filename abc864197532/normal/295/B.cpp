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
const int mod = 1000007, x = 864197532, N = 50000;
const double eps = 1e-6, Pi = 3.1415926535;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n;
	cin >> n;
	int dist[n][n];
	fop (i,0,n) fop (j,0,n) {
		cin >> dist[i][j];
	}
	int now[n][n];
	fop (i,0,n) fop (j,0,n) now[i][j] = i == j ? 0 : (1 << 29);
	vector <lli> ans(n, 0);
	vector <int> del(n);
	fop (i,0,n) cin >> del[i];
	reverse(all(del));
	vector <bool> able(n, false);
	fop (v,0,n) {
		int k = del[v] - 1;
		// i - j - k / k - j - i
		fop (i,0,n) fop (j,0,n) if (able[i] and able[j]) {
			now[i][k] = min(now[i][k], now[i][j] + dist[j][k]);
			now[k][i] = min(now[k][i], dist[k][j] + now[j][i]);
		}
		// i - k - j / j - k - i
		fop (i,0,n) fop (j,0,n) if (able[i] and able[j]) {
			now[i][j] = min(now[i][j], now[i][k] + now[k][j]);
			now[j][i] = min(now[j][i], now[j][k] + now[k][i]);
		}
		able[k] = true;
		fop (i,0,n) fop (j,0,n) if (able[i] and able[j]) {
			ans[v] += now[i][j];
		}
	}
	reverse(all(ans));
	fop (i,0,n) cout << ans[i] << " \n"[i == n - 1];
}