// khodaya khodet komak kon
// Toxicity
# include <bits/stdc++.h>

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

const int xn = 4e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, k, a[xn][xn], dp[xn][xn], b[xn][xn];

void solve(int l, int r, int ql, int qr, int t){
	if (r <= l || qr <= ql)
		return;
	int mid = l + r >> 1, ind = - 1;
	dp[t][mid] = inf;
	for (int i = ql; i < qr && i <= mid; ++ i)
		if (dp[t - 1][i - 1] + b[i][mid] < dp[t][mid])
			dp[t][mid] = dp[t - 1][i - 1] + b[i][mid], ind = i;
	solve(l, mid, ql, ind + 1, t);
	solve(mid + 1, r, ind, qr, t);
}

int main(){
	InTheNameOfGod;

	scanf("%d %d", &n, &k);
	getchar();
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= n; ++ j){
			a[i][j] = (getchar() - '0');
			getchar();
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = i; j <= n; ++ j)
			b[i][j] = a[j][j] - a[i - 1][j] - a[j][i - 1] + a[i - 1][i - 1];
	for (int i = 0; i <= n; ++ i)
		dp[1][i] = b[1][i];
	for (int i = 2; i <= k; ++ i)
		solve(1, n + 1, 1, n + 1, i);
	cout << dp[k][n] / 2 << endl;

	return 0;
}