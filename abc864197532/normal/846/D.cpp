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
const double eps = 1e-11;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector <pair <int, pii>> Q(q);
	fop (i,0,q) cin >> Q[i].Y.X >> Q[i].Y.Y >> Q[i].X;
	auto check = [&](int t) {
		int is[n][m];
		fop (i,0,n) fop (j,0,m) is[i][j] = 0;
		bool flag[n][m];
		fop (i,0,n) fop (j,0,m) flag[i][j] = false;
		fop (i,0,q) if (Q[i].X <= t) {
			is[Q[i].Y.X - 1][Q[i].Y.Y - 1]++;
		}
		fop (i,0,n) {
			int now = 0;
			fop (j,0,k) now += is[i][j];
			if (now == k) flag[i][0] = true;
			fop (j,k,m) {
				now -= is[i][j - k];
				now += is[i][j];
				flag[i][j - k + 1] = (now == k);
			}
		}
		fop (i,0,m) {
			int now = 0;
			bool is = false;
			fop (j,0,k) now += flag[j][i];
			is = (now == k);
			fop (j,k,n) {
				now -= flag[j - k][i];
				now += flag[j][i];
				if (now == k) is = true;
			}
			if (is) return true;
		}
		return false;
	}; 
	int l = -1, r = 1e9 + 87;
	while (r - l > 1) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid;
	}
	if (r == int(1e9 + 87)) r = -1;
	cout << r << endl;
}