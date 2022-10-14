#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto x : a) cout << x << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100087, logN = 17;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n][m];
	vector <bool> row(n, false), col(m, false);
	fop (i,0,n) fop (j,0,m) cin >> a[i][j];
	fop (i,0,n) {
		int aa = 0;
		fop (j,0,m) aa += a[i][j];
		if (aa == m) row[i] = true;
	}
	fop (i,0,m) {
		int aa = 0;
		fop (j,0,n) aa += a[j][i];
		if (aa == n) col[i] = true;
	}
	int ans[n][m];
	fop (i,0,n) fop (j,0,m) {
		if (row[i] && col[j]) {
			ans[i][j] = true;
		} else {
			ans[i][j] = false;
		}
	}
	fop (i,0,n) fop (j,0,m) {
		bool aa = 0;
		fop (k,0,m) aa |= ans[i][k];
		fop (k,0,n) aa |= ans[k][j];
		if (aa != a[i][j]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	fop (i,0,n) printv(ans[i]);
}