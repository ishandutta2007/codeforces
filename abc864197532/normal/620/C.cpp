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
	int n, tmp;
	cin >> n;
	int pre = 0;
	vector <pii> ans;
	map <int, int> m1;
	fop (i,0,n) {
		cin >> tmp;
		m1[tmp]++;
		if (m1[tmp] > 1) {
			ans.eb(pre, i);
			pre = i + 1;
			m1.clear();
		}
	}
	if (ans.empty()) {
		cout << -1 << endl;
	} else {
		ans.back().Y = n - 1;
		cout << ans.size() << endl;
		for (pii A : ans) {
			cout << A.X + 1 << ' ' << A.Y + 1 << endl;
		}
	}
}