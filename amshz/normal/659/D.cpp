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

const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 9;//998244353;
const int base = 257;

int n, ans, col[xn];
pii a[xn];
bool flag;

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n + 1; ++ i)
		cin >> a[i].A >> a[i].B;
	flag = (a[1].A < a[n].A);
	for (int i = 1; i <= n; ++ i){
		if (a[i].B < a[i + 1].B)
			col[i] = 0;
		else if (a[i].A < a[i + 1].A)
			col[i] = 1;
		else if (a[i + 1].B < a[i].B)
			col[i] = 2;
		else
			col[i] = 3;
	}
	for (int i = 2; i <= n; ++ i){
		if (flag && (col[i - 1] + 1) % 4 != col[i])
			++ ans;
		if (!flag && (col[i - 1] - 1 + 4) % 4 != col[i])
			++ ans;
	}
	cout << ans << endl;

	return 0;
}