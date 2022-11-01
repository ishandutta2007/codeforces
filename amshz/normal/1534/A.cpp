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

const int xn = 50 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, m;
string S[xn];
bool f[2][2];

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		cin >> n >> m;
		memset(f, 0, sizeof f);
		for (int i = 1; i <= n; ++ i){
			cin >> S[i], S[i] = '.' + S[i];
			for (int j = 1; j <= m; ++ j){
				if (S[i][j] == 'R')
					f[(i + j) % 2][0] = true;
				else if (S[i][j] == 'W')
					f[(i + j) % 2][1] = true;
			}
		}
		if (f[0][0] && f[0][1] || f[1][0] && f[1][1] || f[0][0] && f[1][0] || f[1][1] && f[0][1]){
			cout << "NO" << endl;
			continue;
		}
		if (f[0][0])
			f[1][1] = true;
		else if (f[0][1])
			f[1][0] = true;
		else if (f[1][0])
			f[0][1] = true;
		else if (f[1][1])
			f[0][0] = true;
		if (!f[0][0] && !f[0][1] && !f[1][0] && !f[1][1])
			f[0][0] = f[1][1] = true;
		cout << "YES" << endl;
		for (int i = 1; i <= n; ++ i){
			for (int j = 1; j <= m; ++ j){
				if (f[(i + j) % 2][0])
					cout << 'R';
				else
					cout << 'W';
			}
			cout << endl;
		}
	}

	return 0;
}