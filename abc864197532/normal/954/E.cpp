#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 27, logN = 18, K = 350;

int main () {
	int n, t;
	lli cur = 0;
	cin >> n >> t;
	vector <pii> pos, neg;
	lli poss = 0, negg = 0;
	vector <int> x(n), y(n);
	fop (i,0,n) cin >> x[i];
	fop (i,0,n) cin >> y[i];
	fop (i,0,n) {
		if (y[i] > t) pos.eb(y[i] - t, x[i]), poss += 1ll * (y[i] - t) * x[i];
		else if (y[i] == t) cur += x[i];
		else neg.eb(t - y[i], x[i]), negg += 1ll * (t - y[i]) * x[i];
	}
	ld ans = cur;
	sort(all(neg));
	sort(all(pos));
	lli all1 = min(poss, negg), all2 = all1;
	for (pii A : pos) {
		if (all1 >= 1ll * A.X * A.Y) {
			ans += A.Y;
			all1 -= 1ll * A.X * A.Y;
		} else {
			ans += (long double)all1 / A.X;
			break;
		}
	}
	for (pii A : neg) {
		if (all2 >= 1ll * A.X * A.Y) {
			ans += A.Y;
			all2 -= 1ll * A.X * A.Y;
		} else {
			ans += (long double)all2 / A.X;
			break;
		}
	}
	cout << fixed << setprecision(9) << ans << endl;
}