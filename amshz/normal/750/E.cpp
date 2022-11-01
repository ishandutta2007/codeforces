//khodaya khodet komak kon
# include <bits/stdc++.h>

/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;

# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;


int n, q, dp[2][xn][5][5], ans[xn], ps[10][xn];
string S;
vector <pii> query[xn];

int getps(int l, int r, int id){
	return ps[id][r] - ps[id][l - 1];
}
void solve(int id, int l, int r){
	if (r - l < 4)
		return;
	int mid = l + r >> 1;
	for (int i = 0; i < 5; ++ i)
		for (int j = 0; j < 5; ++ j)
			dp[0][mid][i][j] = inf;
	for (int i = 0; i < 5; ++ i)
		dp[0][mid][i][i] = 0;
	for (int p = mid - 1; p >= l; -- p){
		for (int i = 0; i < 5; ++ i)
			for (int j = 0; j < 5; ++ j)
				dp[0][p][i][j] = dp[0][p + 1][i][j];
		if (S[p - 1] == '2')
			for (int i = 0; i < 5; ++ i)
				dp[0][p][0][i] = min(dp[0][p + 1][0][i] + 1, dp[0][p + 1][1][i]);
		else if (S[p - 1] == '0')
			for (int i = 1; i < 5; ++ i)
				dp[0][p][1][i] = min(dp[0][p + 1][1][i] + 1, dp[0][p + 1][2][i]);
		else if (S[p - 1] == '1')
			for (int i = 2; i < 5; ++ i)
				dp[0][p][2][i] = min(dp[0][p + 1][2][i] + 1, dp[0][p + 1][3][i]);
		else if (S[p - 1] == '7')
			for (int i = 3; i < 5; ++ i)
				dp[0][p][3][i] = min(dp[0][p + 1][3][i] + 1, dp[0][p + 1][4][i]);
		else if (S[p - 1] == '6')
			for (int i = 0; i < 5; ++ i)
				++ dp[0][p][3][i], ++ dp[0][p][4][i];
	}
	for (int i = 0; i < 5; ++ i)
		for (int j = 0; j < 5; ++ j)
			dp[1][mid - 1][i][j] = inf;
	for (int i = 0; i < 5; ++ i)
		dp[1][mid - 1][i][i] = 0;
	for (int p = mid; p < r; ++ p){
		for (int i = 0; i < 5; ++ i)
			for (int j = 0; j < 5; ++ j)
				dp[1][p][i][j] = dp[1][p - 1][i][j];
		if (S[p - 1] == '2'){
			for (int i = 0; i < 2; ++ i)
				dp[1][p][i][1] = min(dp[1][p - 1][i][1], dp[1][p - 1][i][0]);
			for (int i = 0; i < 1; ++ i)
				++ dp[1][p][i][0];
		}
		else if (S[p - 1] == '0'){
			for (int i = 0; i < 3; ++ i)
				dp[1][p][i][2] = min(dp[1][p - 1][i][2], dp[1][p - 1][i][1]);
			for (int i = 0; i < 2; ++ i)
				++ dp[1][p][i][1];
		}
		else if (S[p - 1] == '1'){
			for (int i = 0; i < 4; ++ i)
				dp[1][p][i][3] = min(dp[1][p - 1][i][3], dp[1][p - 1][i][2]);
			for (int i = 0; i < 3; ++ i)
				++ dp[1][p][i][2];
		}
		else if (S[p - 1] == '7'){
			for (int i = 0; i < 5; ++ i)
				dp[1][p][i][4] = min(dp[1][p - 1][i][4], dp[1][p - 1][i][3]);
			for (int i = 0; i < 4; ++ i)
				++ dp[1][p][i][3];
		}
		else if (S[p - 1] == '6')
			for (int i = 0; i < 5; ++ i)
				++ dp[1][p][i][4], ++ dp[1][p][i][3];
		for (pii x : query[p]){
			if (x.A < mid && x.A >= l){
				ans[x.B] = inf;
				for (int i = 0; i < 5; ++ i)
					ans[x.B] = min(ans[x.B], dp[0][x.A][0][i] + dp[1][p][i][4]);
				if (ans[x.B] > n)
					ans[x.B] = - 1;
			}
		}
	}
	solve(lc, l, mid), solve(rc, mid, r);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> q >> S;
	for (int i = 0; i < q; ++ i){
		int l, r;
		cin >> l >> r;
		if (r - l + 1 < 4)
			ans[i] = - 1;
		else
			query[r].push_back({l, i});
	}
	for (int j = 0; j < 10; ++ j)
		for (int i = 1; i <= n; ++ i)
			ps[j][i] = ps[j][i - 1] + (S[i - 1] - '0' == j);
	solve(1, 1, n + 1);
	for (int i = 0; i < q; ++ i)
		cout << ans[i] << endl;

	return 0;
}