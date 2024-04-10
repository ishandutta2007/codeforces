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
const int mod = 1e9 + 9, x = 864197532, N = 200087, logN = 18, K = 350;

int main () {
	int n, m;
	cin >> n;
	vector <lli> a(n);
	fop (i,0,n) cin >> a[i];
	cin >> m;
	vector <lli> b(m);
	fop (i,0,m) cin >> b[i];
	lli cur1 = accumulate(all(a), 0ll), al = accumulate(all(b), 0ll) + cur1;
	vector <pair <lli, pii>> m1;
	map <lli, pii> m2;
	fop (i,0,m) {
		fop (j,i + 1,m) {
			m2[b[i] + b[j]] = mp(i, j);
		}
	}
	for (auto A : m2) m1.pb(A);
	lli ans = abs(al - cur1 * 2);
	pii tmp = {-1, -1}, tmp2 = {-1, -1};
	fop (i,0,n) {
		fop (j,i + 1,n) {
			lli all2 = cur1 - a[i] - a[j];
			int p = lower_bound(all(m1), mp(al / 2 - all2, mp(-1, -1))) - m1.begin();
			fop (ii,max(p - 2, 0), min(p + 3, int(m1.size()))) {
				if (ans > abs(al - (all2 + m1[ii].X) * 2)) {
					ans = abs(al - (all2 + m1[ii].X) * 2);
					tmp = {i, j};
					tmp2 = m1[ii].Y;
				}
			}
		}
	}
	fop (i,0,n) {
		fop (j,0,m) {
			lli all2 = cur1 - a[i] + b[j];
			if (ans > abs(al - all2 * 2)) {
				ans = abs(al - all2 * 2);
				tmp = {i, j};
				tmp2 = {-1, -1};
			}
		}
	}
	cout << ans << endl;
	if (tmp.X == -1) {
		cout << 0 << endl;
	} else if (tmp2.X == -1) {
		cout << "1\n";
		cout << tmp.X + 1 << ' ' << tmp.Y + 1 << endl;
	} else {
		cout << "2\n";
		cout << tmp.X + 1 << ' ' << tmp2.X + 1 << endl;
		cout << tmp.Y + 1 << ' ' << tmp2.Y + 1 << endl;
	}
}