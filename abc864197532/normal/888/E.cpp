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
const int mod = 998244353, x = 864197532, N = 200087, logN = 17, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	lli a[n];
	fop (i,0,n) cin >> a[i], a[i] %= m;
	vector <lli> vl, vr;
	int mid = n / 2;
	fop (s,0,1 << mid) {
		lli all = 0;
		fop (i,0,mid) if (s & (1 << i)) (all += a[i]) %= m;
		vl.pb(all);
	}
	fop (s,0,1 << n - mid) {
		lli all = 0;
		fop (i,0,n - mid) if (s & (1 << i)) (all += a[mid + i]) %= m;
		vr.pb(all);
	}
	sort(all(vr));
	vr.resize(unique(all(vr)) - vr.begin());
	lli ans = 0;
	for (lli i : vl) {
		lli aa = m - i;
		auto it = lower_bound(all(vr), aa);
		if (it == vr.begin()) continue;
		ans = max((i + *--it) % m, ans);
	}
	cout << ans << endl;
}