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
	int x, y, z, x0, y0, z0, a[6];
	cin >> x >> y >> z >> x0 >> y0 >> z0;
	fop (i,0,6) cin >> a[i];
	int ans = 0;
	if (y < 0) {
		ans += a[0];
	}
	if (y > y0) {
		ans += a[1];
	}
	if (z < 0) {
		ans += a[2];
	}
	if (z > z0) {
		ans += a[3];
	}
	if (x < 0) {
		ans += a[4];
	}
	if (x > x0) {
		ans += a[5];
	}
	cout << ans << endl;
}