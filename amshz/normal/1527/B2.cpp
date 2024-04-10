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

const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, dp[xn][xn][2], ps[xn][xn][2], cnt[3];
string S;

int main(){
	InTheNameOfGod;

	for (int i = 0; i < xn; ++ i){
		for (int j = 0; j < xn; ++ j){
			for (int k = 0; k < 2; ++ k){
				if (i + j + k == 0)
					continue;
				dp[i][j][k] = inf;
				if (i && j + 1 < xn)
					dp[i][j][k] = min(dp[i][j][k], - (dp[i - 1][j + 1][k] - 1));
				if (j)
					dp[i][j][k] = min(dp[i][j][k], - (dp[i][j - 1][k] - 1));
				if (k)
					dp[i][j][k] = min(dp[i][j][k], - (dp[i][j][k - 1] - 1));
				ps[i][j][k] = dp[i][j][k];
				if (j)
					dp[i][j][k] = min(dp[i][j][k], - ps[i][j][k]);
			}
		}
	}
	cin >> qq;
	while (qq --){
		cin >> n >> S;
		cnt[0] = cnt[1] = cnt[2] = 0;
		for (int i = 0; i < n; ++ i){
			if (n - i - 1 <= i)
				break;
			++ cnt[2 - S[i] + '0' - S[n - i - 1] + '0'];
		}
		cnt[0] = 0;
		if (n % 2)
			cnt[0] += 1 - S[n / 2] + '0';
		if (dp[cnt[2]][cnt[1]][cnt[0]] < 0)
			cout << "ALICE" << endl;
		else if (dp[cnt[2]][cnt[1]][cnt[0]] > 0)
			cout << "BOB" << endl;
		else
			cout << "DRAW" << endl;
	}

	return 0;
}