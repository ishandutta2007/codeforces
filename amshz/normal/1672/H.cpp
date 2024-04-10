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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, q, ps[2][xn];
string S;

int main(){
	fast_io;

	cin >> n >> q;
	cin >> S;
	S = '.' + S;
	for (int j = 0; j < 2; ++ j){
		for (int i = 2; i <= n; ++ i){
			ps[j][i] = ps[j][i - 1];
			if (S[i] == S[i - 1] && S[i] - '0' == j)
				++ ps[j][i];
		}
	}
	while (q --){
		int l, r;
		cin >> l >> r;
		int x = ps[0][r] - ps[0][l];
		int y = ps[1][r] - ps[1][l];
		cout << max(x, y) + 1 << endl;
	}

	return 0;
}