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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	lli n, m, k;
	cin >> n >> m >> k;
	auto ask = [&](lli a) {
		lli now = 0;
		fop (i,1,n+1) {
			now += min(a / i, 1ll * m);
		}
		return now;
	};
	lli l = 0, r = 1ll << 44;
	while (r - l > 1) {
		lli mid = l + r >> 1;
		if (ask(mid) >= k) r = mid;
		else l = mid;
	}
	cout << r << endl;
}