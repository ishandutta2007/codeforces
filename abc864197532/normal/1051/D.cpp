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
const int mod = 998244353, x = 864197532, N = 300087, logN = 18, K = 350;

int main () {
	int n, k;
	cin >> n >> k;
	lli dp[n][k + 1][4];
	fop (i,0,n) fop (j,0,k + 1) fop (ii,0,4) dp[i][j][ii] = 0;
	dp[0][1][0] = 1;
	dp[0][2][1] = 1;
	dp[0][2][2] = 1;
	dp[0][1][3] = 1;
	fop (i,1,n) {
		fop (j,0,k + 1) {
			dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + (j >= 1 ? dp[i - 1][j - 1][3] : 0)) % mod;
			dp[i][j][1] = ((j >= 1 ? dp[i - 1][j - 1][0] : 0) + dp[i - 1][j][1] + (j >= 2 ? dp[i - 1][j - 2][2] : 0) + (j >= 1 ? dp[i - 1][j - 1][3] : 0)) % mod;
			dp[i][j][2] = ((j >= 1 ? dp[i - 1][j - 1][0] : 0) + (j >= 2 ? dp[i - 1][j - 2][1] : 0) + dp[i - 1][j][2] + (j >= 1 ? dp[i - 1][j - 1][3] : 0)) % mod;
			dp[i][j][3] = ((j >= 1 ? dp[i - 1][j - 1][0] : 0) + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j][3]) % mod;
		}
	}
	cout << (dp[n - 1][k][0] + dp[n - 1][k][1] + dp[n - 1][k][2] + dp[n - 1][k][3]) % mod << endl; 
}