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
const int mod = 1e9 + 7, x = 864197532, N = 520, logN = 17, K = 350;

int dp[N][N];
string t;
int n;

int solve(int i, int j) {
	if (~dp[i][j]) return dp[i][j];
	int cur = solve(i + 1, j) + 1;
	/*
	1 4
	1 2 + 3 4
	*/
	fop (k,i + 1,j) if (t[i] == t[k]) {
		cur = min(cur, solve(i + 1, k) + solve(k, j));
	}
	//cout << i << ' ' << j << ' ' << cur << endl;
	return dp[i][j] = cur;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fop (i,0,N) fop (j,0,N) {
    	if (i == j) dp[i][j] = 0;
    	else if (i + 1 == j) dp[i][j] = 1;
    	else if (i + 2 == j) dp[i][j] = 2;
    	else dp[i][j] = -1;
	}
    string s;
    cin >> n >> s;
    s += '@';
    fop (i,0,n) {
    	if (s[i] != s[i + 1]) t += s[i];
	}
	n = t.length();
	cout << solve(0, n) << endl;
}