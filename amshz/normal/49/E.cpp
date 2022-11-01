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

const int xn = 51;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n[2], q, pd[xn][xn];
bool dp[2][xn][xn][xn], adj[xn][xn][xn];
string S[2];

int main(){
	fast_io;

	for (int i = 0; i < 2; ++ i){
		cin >> S[i];
		n[i] = SZ(S[i]);
		S[i] = '.' + S[i];
	}
	cin >> q;
	while (q --){
		string SS;
		cin >> SS;
		adj[SS[3] - 'a'][SS[4] - 'a'][SS[0] - 'a'] = true;
	}
	for (int f = 0; f < 2; ++ f){
		for (int i = 1; i <= n[f]; ++ i)
			dp[f][i][i][S[f][i] - 'a'] = true;
		for (int t = 1; t < n[f]; ++ t){
			for (int l = 1; l + t <= n[f]; ++ l){
				int r = l + t;
				for (int mid = l; mid < r; ++ mid)
					for (int c1 = 0; c1 < 26; ++ c1)
						for (int c2 = 0; c2 < 26; ++ c2)
							for (int c3 = 0; c3 < 26; ++ c3)
								if (adj[c1][c2][c3])
									dp[f][l][r][c3] |= (dp[f][l][mid][c1] & dp[f][mid + 1][r][c2]);
			}
		}
	}
	for (int i = 0; i < xn; ++ i)
		for (int j = 0; j < xn; ++ j)
			pd[i][j] = inf;
	pd[0][0] = 0;
	for (int i = 1; i <= n[0]; ++ i)
		for (int j = 1; j <= n[1]; ++ j)
			for (int ii = 0; ii < i; ++ ii)
				for (int jj = 0; jj < j; ++ jj)
					for (int c = 0; c < 26; ++ c)
						if (dp[0][ii + 1][i][c] && dp[1][jj + 1][j][c])
							pd[i][j] = min(pd[i][j], pd[ii][jj] + 1);
	if (pd[n[0]][n[1]] == inf)
		cout << - 1 << endl;
	else
		cout << pd[n[0]][n[1]] << endl;

	return 0;
}