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
//# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = - 20 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e7 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, sum, ans = inf;

int check(int x){
	cout << "? " << x << endl;
	int y;
	cin >> y;
	return y;
}

int main(){
	//fast_io;

	cin >> n;
	int lb = 0, rb = inf;
	while (1 < rb - lb){
		int md = lb + rb >> 1;
		if (check(md) == 1)
			rb = md;
		else
			lb = md;
	}
	sum = rb - n + 1;
	for (int i = 1; i <= n; ++ i){
		for (int j = sum + n - i; j < sum + n; ++ j){
			if (j % i)
				continue;
			if (check(j / i) == i)
				ans = min(ans, j);
		}
	}
	cout << "! " << ans << endl;

	return 0;
}