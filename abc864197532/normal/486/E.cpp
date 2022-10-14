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
const int mod = 998244353, x = 864197532, N = 100087, logN = 17;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n);
	fop (i,0,n) cin >> a[i];
	int dp1[n], dp2[n];
	vector <int> lis;
	fop (i,0,n) {
		if (lis.empty() || lis.back() < a[i]) {
			lis.pb(a[i]);
			dp1[i] = lis.size();
		} else {
			auto it = lower_bound(all(lis), a[i]);
			dp1[i] = it - lis.begin() + 1;
			*it = a[i];
		}
	}
	reverse(all(a));
	deque <int> dq; 
	fop (i,0,n) {
		if (dq.empty() || a[i] < dq.front()) {
			dq.push_front(a[i]);
			dp2[n - 1 - i] = dq.size();
		} else {
			auto it = --upper_bound(all(dq), a[i]);
			dp2[n - 1 - i] = dq.end() - it;
			*it = a[i];
		}
	}
	reverse(all(a));
	vector <int> cnt(N, 0), ans(n, 0);
	fop (i,0,n) {
		if (dp1[i] + dp2[i] - 1 != lis.size()) {
			ans[i] = 1;
		} else {
			cnt[dp1[i]]++;
		}
	}
	fop (i,0,n) if (ans[i] == 0) {
		if (cnt[dp1[i]] > 1) ans[i] = 2;
		else ans[i] = 3;
	}
	fop (i,0,n) cout << ans[i];
	cout << endl;
}