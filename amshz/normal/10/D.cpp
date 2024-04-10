//khodaya khodet komak kon
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
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 5e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, m, a[xn], b[xn], dp[xn][xn];
int lst[xn], par[xn][xn];
pii res;
vector <int> ans;

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; ++ i)
		cin >> b[i];
	a[0] = - 1;
	for (int i = 1; i <= n; ++ i)
		dp[0][i] = m + 1;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= i; ++ j){
			dp[i][j] = m + 1;
			lst[m] = lst[m + 1] = m + 1;
			for (int k = m - 1; 0 <= k; -- k){
				lst[k] = lst[k + 1];
				if (b[k + 1] == a[i])
					lst[k] = k + 1;
			}
			for (int k = 0; k < i; ++ k)
				if (a[k] < a[i] && lst[dp[k][j - 1]] < dp[i][j])
					dp[i][j] = lst[dp[k][j - 1]], par[i][j] = k;
		}
		for (int j = i + 1; j <= n; ++ j)
			dp[i][j] = m + 1;
	}
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= i; ++ j)
			if (dp[i][j] <= m && res.B < j)
				res = {i, j};
	cout << res.B << endl;
	while (res.B){
		ans.push_back(a[res.A]);
		res.A = par[res.A][res.B];
		-- res.B;
	}
	reverse(all(ans));
	for (int x : ans)
		cout << x << sep;
	cout << endl;

	return 0;
}