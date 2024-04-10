// khodaya khodet komak kon
// Maybe on the Moon
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

const int xn = 5e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, a[xn][xn];

int main(){
	InTheNameOfGod;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i][i];
	for (int i = 1; i <= n; ++ i){
		int ind = - 1;
		for (int j = i; j <= n; ++ j)
			if (ind == - 1 || a[j][j - i + 1] < a[ind][ind - i + 1])
				ind = j;
		for (int j = i; j < ind; ++ j)
			a[j + 1][j - i + 1] = a[j][j - i + 1];
		for (int j = ind + 1; j <= n; ++ j)
			a[j][j - i] = a[j][j - i + 1];
	}
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= i; ++ j)
			cout << a[i][j] << sep;
		cout << endl;
	}

	return 0;
}