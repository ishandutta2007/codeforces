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
const int mod = 1e9 + 7, x = 864197532, N = 2000, logN = 17, K = 350;

vector <lli> a, pre;
int n, r;
lli k;

bool ask (lli x) {
	lli all = 0, dq_all = 0;
	deque <pll> dq;
	fop (i,0,n) {
		while (dq.size() && dq.front().X == i) dq_all -= dq.front().Y, dq.pop_front();
		lli cur = pre[min(i + r + 1, n)] - pre[max(i - r, 0)];
		if (cur + dq_all < x) {
			dq.push_back({i + 2 * r + 1, x - cur - dq_all});
			all += x - cur - dq_all;
			dq_all += x - cur - dq_all;
		}
		if (all > k) return false;
	}
	return true;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> r >> k;
    a.resize(n);
    pre.resize(n + 1, 0);
    fop (i,0,n) cin >> a[i], pre[i + 1] = pre[i] + a[i];
	lli l = 0, b = 1ll << 61;
	while (b - l > 1) {
		lli mid = l + b >> 1;
		if (ask(mid)) l = mid;
		else b = mid;
	}
	cout << l << endl;
}