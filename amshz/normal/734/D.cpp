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

const int xn = 5e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 9;//998244353;
const int base = 257;

ll n, b[xn];
pll a[xn];
char c[xn];
bool flag;

void solve(ll dx, ll dy){
	ll mn = INF;
	for (int i = 1; i <= n; ++ i){
		b[i] = - 1;
		if (!dx && a[0].A - a[i].A)
			continue;
		if (!dy && a[0].B - a[i].B)
			continue;
		ll x = a[0].A - a[i].A;
		if (dx)
			x /= dx;
		ll y = a[0].B - a[i].B;
		if (dy)
			y /= dy;
		if (x < 0 || y < 0)
			continue;
		if (x - y && dx && dy)
			continue;
		b[i] = max(x, y);
		mn = min(mn, b[i]);
	}
	if (mn == inf)
		return;
	for (int i = 1; i <= n; ++ i){
		if (mn - b[i])
			continue;
		if (!dx || !dy){
			if (c[i] == 'B')
				continue;
		}
		else{
			if (c[i] == 'R')
				continue;
		}
		flag = true;
	}
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 0; i <= n; ++ i){
		if (i)
			cin >> c[i];
		cin >> a[i].A >> a[i].B;
	}
	for (int i = - 1; i < 2; ++ i)
		for (int j = - 1; j < 2; ++ j)
			solve(i, j);
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}