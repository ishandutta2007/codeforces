// khodaya khodet komak kon
// Nightcall - London Grammer
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

const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, par[xn], dp[xn];
pii mx[xn][2];

int main(){
	InTheNameOfGod;

	cin >> n;
	for (int i = 2; i <= n + 1; ++ i){
		cin >> par[i];
		int v = i;
		dp[v] = 1;
		while (par[v]){
			int u = v;
			v = par[v];
			bool flag = true;
			for (int j = 0; j < 2; ++ j){
				if (mx[v][j].B == u){
					mx[v][j].A = dp[u];
					if (mx[v][0] < mx[v][1])
						swap(mx[v][0], mx[v][1]);
					flag = false;
				}
			}
			if (flag){
				pii x = {dp[u], u};
				for (int j = 0; j < 2; ++ j)
					if (mx[v][j] < x)
						swap(x, mx[v][j]);
			}
			int res = mx[v][0].A;
			if (mx[v][1].B)
				res = max(res, mx[v][1].A + min(1, v - 1));
			if (dp[v] < res)
				dp[v] = res;
			else
				break;
		}
		cout << dp[1] << sep;
	}
	cout << endl;

	return 0;
}