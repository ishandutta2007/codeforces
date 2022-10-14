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
const int mod = 998244353, x = 864197532, N = 300000, logN = 17;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n), v(n);
	fop (i,0,n) cin >> a[i], v[i] = a[i];
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	vector <int> pos[v.size()];
	fop (i,0,n) a[i] = lower_bound(all(v), a[i]) - v.begin(), pos[a[i]].pb(i);
	int ans = 0;
	fop (i,0,v.size()) {
		int j = i + 1;
		while (j < v.size() && pos[j - 1].back() < pos[j][0]) j++;
		ans = max(ans, j - i);
		i = j - 1;
	}
	cout << v.size() - ans << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}