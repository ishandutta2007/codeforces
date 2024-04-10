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
const int mod = 1e9 + 7, x = 864197532, N = 50, logN = 17, K = 350;

int dp[N][N][4][2];

int solve(int a, int b, int k, int t) {
	if (a == 0 && b == 0) return (k == t + 1 ? true : false);
	if (dp[a][b][k][t] != -1) return dp[a][b][k][t];
	if (a >= 1 && !solve(a - 1, b, k ^ (t + 1), t ^ 1)) return dp[a][b][k][t] = true;
	if (b >= 1 && !solve(a, b - 1, k, t ^ 1)) return dp[a][b][k][t] = true;
	return dp[a][b][k][t] = false;
}

void solve() {
	int n, xorr = 0;
	cin >> n;
	vector <int> v(n);
	fop (i,0,n) cin >> v[i], xorr ^= v[i];
	if (xorr == 0) {
		cout << "DRAW\n";
		return;
	}
	vector <int> cnt(30, 0);
	fop (i,0,n) {
		fop (j,0,30) if (v[i] & (1 << j)) cnt[j]++;
	}
	bool is = false;
	FOP (i,30,0) if (xorr & (1 << i)) {
		is = solve(cnt[i] % 4, (n - cnt[i]) % 4, 0, 0);
		break;
	}
	cout << (is ? "WIN\n" : "LOSE\n");
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fop (i,0,N) fop (j,0,N) fop (k,0,4) fop (ii,0,2) dp[i][j][k][ii] = -1;
    int t;
    cin >> t;
    while (t--) {
    	solve();
	}
}