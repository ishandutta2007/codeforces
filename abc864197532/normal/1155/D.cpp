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
const int mod = 1e9 + 7, x = 864197532, N = 500001, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
    l[i] + x * (sum[j] - sum[i]) + r[j + 1]
    (l[i] - x * sum[i]) + (r[j + 1] + x * sum[j])
    */
    int n, x;
    cin >> n >> x;
    vector <lli> a(n), l(n + 1, 0), r(n + 1, 0), pre(n + 1, 0);
    fop (i,0,n) cin >> a[i];
    fop (i,0,n) {
    	pre[i + 1] = pre[i] + a[i];
	}
	lli now = 0;
	fop (i,0,n + 1) {
		now = min(now, pre[i]);
		l[i] = max(0ll, pre[i] - now);
	}
	now = pre[n];
	FOP (i,n + 1,0) {
		now = max(now, pre[i]);
		r[i] = max(0ll, now - pre[i - 1]);
	}
	lli ans = 0, cur = 0;
	fop (i,1,n + 1) {
		ans = max(ans, cur + (i + 1 < n + 1 ? r[i + 1] : 0) + x * pre[i]);
		ans = max(ans, l[i]);
		cur = max(cur, l[i] - x * pre[i]);
	}
	cout << ans << endl;
}