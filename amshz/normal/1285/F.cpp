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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m, c[xn], d[xn], lstbit[xn];
ll ans, res;
pii a[xn];
bool f[xn], p[xn], b[xn], fl[xn];
vector <int> vec[xn], pbs[xn];

void add(int x){
	m = SZ(vec[x]), c[0] = 1;
	for (int mask = 0; mask < (1 << m); ++ mask){
		if (mask)
			c[mask] = c[mask - (1 << lstbit[mask])] * vec[x][lstbit[mask]];
		++ d[c[mask]];
	}
}
ll check(int x){
	m = SZ(vec[x]), c[0] = 1, res = 0;
	for (int mask = 0; mask < (1 << m); ++ mask){
		if (mask)
			c[mask] = c[mask - (1 << lstbit[mask])] * vec[x][lstbit[mask]];
		if (fl[mask])
			res -= d[c[mask]];
		else
			res += d[c[mask]];
	}
	return res;
}

int main(){
	fast_io;

	for (int i = 0; i < xn; ++ i)
		for (int j = 0; j < 20; ++ j)
			if ((i & (1 << j)))
				lstbit[i] = j, fl[i] ^= 1;
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		int x; cin >> x; f[x] = true;
	}
	for (int i = 1; i < xn; ++ i)
		for (int j = i; j < xn; j += i)
			f[i] |= f[j];
	for (int i = 2; i < xn; ++ i)
		if (!p[i])
			for (int j = i; j < xn; j += i)
				p[j] = true, vec[j].push_back(i);
	for (int i = 1; i < xn; ++ i)
		if (f[i])
			a[i] = {1, xn}, pbs[(xn + 1) / 2].push_back(i);
	for (int j = 0; j < 17; ++ j){
		memset(d, 0, sizeof d);
		for (int i = xn - 1; i >= 1; -- i){
			if (f[i])
				add(i);
			for (int x : pbs[i])
				b[x] = 0 < check(x);
			pbs[i].clear();
		}
		for (int i = 1; i < xn; ++ i){
			if (!f[i] || a[i].A + 1 == a[i].B)
				continue;
			if (b[i])
				a[i].A = (a[i].A + a[i].B) / 2;
			else
				a[i].B = (a[i].A + a[i].B) / 2;
			if (a[i].B - a[i].A > 1)
				pbs[(a[i].A + a[i].B) / 2].push_back(i);
		}
	}
	for (int i = 1; i < xn; ++ i)
		if (f[i])
			ans = max(ans, 1ll * i * a[i].A);
	cout << ans << endl;

	return 0;
}