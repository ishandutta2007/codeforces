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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 18, K = 350;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <pair <pii, int>> a[n];
	vector <pii> exam(m);
	fop (i,0,m) {
		int u, v, x;
		cin >> u >> v >> x; u--; v--;
		a[u].pb(mp(mp(v, x), i));
		exam[i] = {v, x};
	}
	set <pair <pii, int>> now;
	vector <int> ans;
	bool is = true;
	fop (i,0,n) {
		for (auto A : a[i]) {
			now.insert(mp(mp(A.X.X, A.X.Y), A.Y));
		}
		bool iss = true;
		fop (j,0,m) {
			if (exam[j].X == i) {
				if (exam[j].Y) {
					is = false;
				} else {
					ans.pb(m + 1);
				}
				iss = false;
			}
		}
		if (!is) break;
		if (!iss) continue;
		if (now.size()) {
			ans.pb(now.begin()->Y + 1);
			exam[now.begin()->Y].Y--;
			if (now.begin()->X.Y == 1) {
				now.erase(now.begin());
			} else {
				auto A = *now.begin();
				now.erase(now.begin());
				now.insert({mp(mp(A.X.X, A.X.Y - 1), A.Y)});
			}
		} else {
			ans.pb(0);
		}
	}
	if (is) {
		printv(ans);
	} else {
		cout << -1 << endl;
	}
}