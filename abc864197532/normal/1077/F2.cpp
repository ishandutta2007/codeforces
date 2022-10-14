#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 200000, logN = 18, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    int a[n];
    fop (i,0,n) cin >> a[i];
    if (n / k > x) {
    	cout << -1 << endl;
    	return 0;
	}
    lli dp[n + 1][x + 1];
    fop (i,0,x + 1) dp[0][i] = (i ? -1ll << 60 : 0);
    fop (i,0,n + 1) dp[i][0] = 0;
	deque <int> dq[x + 1];
	dq[0].pb(0);
    fop (i,1,n + 1) {
        fop (j,1,x + 1) {
    		while (dq[j - 1].size() && dq[j - 1].front() < i - k) dq[j - 1].pop_front();
    		if (dq[j - 1].size()) dp[i][j] = dp[dq[j - 1].front()][j - 1] + a[i - 1];
    		else dp[i][j] = -1ll << 60;
        }
        fop (j,1,x + 1) {
    		while (dq[j].size() && dp[dq[j].back()][j] <= dp[i][j]) dq[j].pop_back();
    		dq[j].pb(i);
        }
	}
	lli ans = 0;
	fop (i,n - k + 1,n + 1) ans = max(ans, dp[i][x]);
	cout << ans << endl;
}