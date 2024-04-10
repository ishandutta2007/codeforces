#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
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
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 501, logN = 20, K = 350;

void solve () {
	int n;
	cin >> n;
	vector <pii> a(n), v;
	int cur = 0;
	int pp = -1;
	vector <int> cnt(N, 0);
	fop (i,0,n) cin >> a[i].X, cnt[a[i].X]++, a[i].Y = cnt[a[i].X];
	v = a;
	sort(all(v));
	fop (i,0,n) {
		if (pp == -1 && cnt[a[i].X] > 1) pp = a[i].X;
		fop (j,i + 1,n) {
			if (a[i].X > a[j].X) cur++;
		}
	}
	if (cur & 1) {
		if (pp == -1) {
			cout << -1 << endl;
			return;
		}
		fop (i,0,n) fop (j,i + 1,n) {
			if (a[i].X == pp && a[j].X == pp) {
				swap(a[i], a[j]);
				i = n - 1;
				j = n - 1;
			}
		}
	}
	/*
	1 2
	OX
	O X
	X  
	1 3
	O X
	X 
	*/
	vector <int> ans;
	auto move_to = [&](int i, int b) {
		while (b - i > 1) {
			ans.pb(b - 2);
			b -= 2;
			tie(a[b], a[b + 1], a[b + 2]) = mt(a[b + 2], a[b], a[b + 1]);
		}
		if (b != i) {
			if (i + 2 < n) {
				ans.pb(i);
				ans.pb(i);
				tie(a[i], a[i + 1], a[i + 2]) = mt(a[i + 1], a[i + 2], a[i]);
			} else {
				ans.pb(i - 1);
				ans.pb(i - 1);
				tie(a[i - 1], a[i], a[i + 1]) = mt(a[i], a[i + 1], a[i - 1]);
			}
		}
	};
	fop (i,0,n - 2) {
		int p = min_element(a.begin() + i, a.end()) - a.begin(); 
		//cout << i << ' ' << p << endl; 
		move_to(i, p);
	}
	cout << ans.size() << endl;
	for (int i : ans) cout << i + 1 << ' ';
	cout << endl; 
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	/*
	a b c a > c, b > c
	c a b c > a, c > b
	3 3 6 => 0
	6 3 3 => 2
	3 6 3 => 1
	*/
}