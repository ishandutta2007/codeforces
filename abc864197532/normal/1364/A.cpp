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
#define ld long double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100000, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int a[n], pre[n + 1];
		pre[0] = 0;
		fop (i,0,n) {
			cin >> a[i];
			a[i] %= x;
			pre[i + 1] = (pre[i] + a[i]) % x;
		}
		int now = 0, now2 = 1 << 30;
		int ans = -1;
		fop (i,1,n + 1) {
			if (pre[i] == 0) {
				ans = max(ans, i - now2);
			} else {
				if (now2 == 1 << 30) now2 = i;
				ans = max(ans, i);
			}
		}
		cout << ans << endl;
	}
}