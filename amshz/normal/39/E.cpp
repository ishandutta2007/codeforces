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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = 30 + 3;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int a, b, n;
bool dp[xn][xm];

int main(){
	InTheNameOfGod;

	cin >> a >> b >> n;
	for (int i = xn - 2; i >= 1; -- i){
		for (int j = xm - 2; j >= 1; -- j){
			ll res = 1;
			for (int k = 0; k < j; ++ k)
				res = min(ll(n), res * i);
			if (n <= res)
				dp[i][j] = true;
			else if (j == 1 && n <= 1ll * i * i)
				dp[i][j] = (n - i - 1) % 2;
			else
				dp[i][j] = (!dp[i + 1][j] | !dp[i][j + 1]);
		}
	}
	if (a == 1){
		for (int i = b; i + 2 < xm; i += 2){
			if (!dp[2][i])
				kill("Masha");
			if (!dp[2][i + 1])
				kill("Stas");
		}
		kill("Missing");
	}
	if (dp[a][b])
		cout << "Masha" << endl;
	else
		cout << "Stas" << endl;

	return 0;
}