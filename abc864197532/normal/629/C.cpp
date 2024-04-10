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
const int mod = 1e9 + 7, x = 864197532, N = 2087, logN = 17, K = 350;

lli dp[N][N];

lli solve(int a, int b) {
	if (b > 2000) return 0;
	if (b < 0) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	return dp[a][b] = (solve(a - 1, b + 1) + solve(a - 1, b - 1)) % mod;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fop (i,0,N) fop (j,0,N) dp[i][j] = -1;
    fop (j,0,2) fop (i,0,N) dp[j][i] = (i == j ? 1 : 0);
    int n, m;
    string s;
    cin >> n >> m >> s;
    int all = 0, pre_min = 0;
    fop (i,0,m) {
    	all += (s[i] == ')' ? -1 : 1);
    	pre_min = min(pre_min, all);
	}
	int now = -pre_min;
	lli ans = 0;
	while (now + all <= n - m) {
		fop (i,0,n - m + 1) {
			ans = (ans + (solve(i, now) * solve(n - m - i, now + all) % mod)) % mod;
		}
		now++;
	}
	cout << ans << endl;
}