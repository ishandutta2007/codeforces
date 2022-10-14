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
const int mod = 1e9 + 7, x = 864197532, N = 500007;

lli ask (int g, int h, int r) {
	lli dp[g + 1];
	fop (i,0,g + 1) dp[i] = i == 0 ? 1 : 0;
	lli ans = 0;
	fop (j,1,h + 1) {
		FOP (i,g + 1,0) {
			if (i >= j) {
				(dp[i] += dp[i - j]) %= mod;
			}
		}
	}
	fop (i,0,g + 1) if (h * (h + 1) / 2 - i <= r) (ans += dp[i]) %= mod;
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int g, r, h = 1;
	cin >> g >> r;
	while ((h + 1) * (h + 2) / 2 <= g + r) h++;
	lli ans1 = ask(g, h, r), ans2 = ask(r, h, g);
	cout << ans1 << endl;
}