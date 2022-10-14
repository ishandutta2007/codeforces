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
const int mod = 998244353, x = 864197532, N = 5000, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void solve() {
	int n, m;
	cin >> n >> m; 
	vector <lli> aa;
	fop (i,0,n) {
		string s;
		cin >> s;
		lli tmp = 0, c = 0;
		while (s.size()) {
			tmp += (1ll << c) * (s.back() - '0');
			c++;
			s.pop_back();
		}
		aa.pb(tmp);
	}
	sort(all(aa));
	int k = ((1ll << m) - n) & 1;
	auto check = [&](lli a) {
		if (a >= (1ll << m) or a < 0) return false;
		lli less = 0, bigg = 0;
		fop (i,0,n) {
			if (aa[i] < a) less++;
			else if (aa[i] > a) bigg++;
			else return false;
		}
		bigg = (1ll << m) - a - bigg - 1;
		less = a - less;
		if (bigg - less == !k) return true;
		return false;
	};
	lli now = (1ll << m - 1) + 500;
	while (now >= (1ll << m - 1) - 500) {
		if (check(now)) {
			break;
		}
		now--;
	}
	FOP (i,m,0) {
		if (now & (1ll << i)) cout << 1;
		else cout << 0;
	}
	cout << '\n';
}

int main () {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) solve();
}