#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
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
const int mod = 1e9 + 7, x = 864197532, N = 1000087, logN = 17;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	lli x, y;
	cin >> n >> m >> x >> k >> y;
	vector <int> a(n), pos(n), b(m), on(n, 0);
	fop (i,0,n) {
		cin >> a[i], a[i]--;
		pos[a[i]] = i;
	}
	vector <int> pos_b;
	bool is = true;
	fop (i,0,m) {
		cin >> b[i], b[i]--;
		on[pos[b[i]]] = 1;
		if (pos_b.size() && pos_b.back() > pos[b[i]]) is = false;
		pos_b.pb(pos[b[i]]);
	}
	if (!is) {
		cout << -1 << endl;
		return 0;
	}
	vector <pii> v;
	if (!on[0]) {
		v.eb(-1, -1);
	}
	fop (i,0,n) {
		if (on[i]) v.eb(a[i], -1);
		else {
			if (v.back().Y == -1) v.eb(a[i], 1);
			else v.back().Y++, v.back().X = max(v.back().X, a[i]);
		}
	}
	if (v.back().Y != -1) v.eb(-1, -1);
	lli ans = 0;
	for (int i = 1; i + 1 < v.size(); i++) if (v[i].Y != -1) {
		if (v[i + 1].X > v[i].X || v[i - 1].X > v[i].X) {
			if (y * k < x) ans += y * v[i].Y;
			else ans += x * (v[i].Y / k) + y * (v[i].Y % k);
		} else {
			if (v[i].Y < k) is = false;
			else {
				if (y * k < x) ans += y * (v[i].Y - k) + x;
				else ans += x * (v[i].Y / k) + y * (v[i].Y % k);
			}
		}
	}
	cout << (is ? ans : -1) << endl;
}