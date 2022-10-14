#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
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
//const int mod = 998244353, x = 864197532, N = 500001, logN = 17;

lli dp[501][501];
int mod; 

lli solve(int a, int b) {
	if (dp[a][b] != -1) return dp[a][b];
	lli ans = 0;
	if (a >= 2) {
		ans = (ans + solve(a - 2, b + 2) * (a * (a - 1) / 2) % mod) % mod;
	}
	if (a && b) {
		ans = (ans + solve(a - 1, b) * a * b % mod) % mod;
	}
	if (b >= 2) {
		ans = (ans + solve(a, b - 2) * (b * (b - 1) / 2) % mod) % mod;
	}
	return dp[a][b] = ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fop (i,0,501) fop (j,0,501) dp[i][j] = -1;
    int n, m;
    cin >> n >> m >> mod;
    dp[0][0] = 1;
    string s;
    vector <int> cnt(n, 2);
    fop (i,0,m) {
    	cin >> s;
    	fop (i,0,n) {
    		cnt[i] -= (s[i] == '1');
		}
	}
	int a[3] = {0, 0, 0};
	fop (i,0,n) a[cnt[i]]++;
	cout << solve(a[2], a[1]) << endl;
}