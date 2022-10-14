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

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    lli a, b, q;
    cin >> a >> b >> q;
    while (q--) {
    	int l, t, m;
    	cin >> l >> t >> m;
    	if (t < a + b * (l - 1)) {
    		cout << -1 << endl;
    		continue;
		}
    	auto ask = [&](lli x) {
    		lli big = a + b * (l + x - 1), all = a * (x + 1) + b * (l - 1) * (x + 1) + b * x * (x + 1) / 2;
    		return max((all + m - 1) / m, big) <= t;
		};
		lli a = 0, b = 1ll << 25;
		while (b - a > 1) {
			lli mid = a + b >> 1;
			if (ask(mid)) a = mid;
			else b = mid;
		}
		cout << l + a << endl;
	}
}