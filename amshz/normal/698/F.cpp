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

const int xn = 1e6 + 10;
const int xm = - 20 + 10;
int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, fact[xn], a[xn], cnt[xn], cn[xn], b[xn], ans = 1;
pii c[xn];

void add(int x, int y){
	if (n / x != n / y){
		cout << 0 << endl;
		exit(0);
	}
	if (!c[x].A)
		c[x].A = y, -- cn[n / x];
	if (!c[y].B)
		c[y].B = x;
	if (c[x].A != y || c[y].B != x){
		cout << 0 << endl;
		exit(0);
	}
}

int main(){
	fast_io;

	cin >> n, sq = sqrt(n) + 1;
	fact[0] = cnt[1] = 1;
	for (int i = 1; i <= n; ++ i)
		fact[i] = 1ll * fact[i - 1] * i % mod;
	fill(a + 1, a + n + 1, 1);
	for (int i = 2; i <= n; ++ i){
		if (a[i] == 1){
			++ cn[n / i];
			for (int j = i; j <= n; j += i)
				a[j] *= i, b[j] = i;
			if (n < i + i)
				a[i] = 1;
		}
		++ cnt[a[i]];
	}
	for (int i = 1; i <= n; ++ i){
		int x;
		cin >> x;
		if (!x)
			continue;
		if (a[x] != a[i]){
			if (a[i] == 1 || a[x] == 1)
				kill(0);
			if (sq <= b[x] && sq <= b[i] && a[x / b[x]] == a[i / b[i]])
				add(b[x], b[i]);
			else
				kill(0);
		}
		else if (a[i] != 1)
			if (sq <= b[i])
				add(b[i], b[i]);
		-- cnt[a[i]];
	}
	cn[1] = 0;
	for (int i = 1; i <= n; ++ i){
		ans = 1ll * ans * fact[cnt[i]] % mod;
		ans = 1ll * ans * fact[cn[i]] % mod;
	}
	cout << ans << endl;

	return 0;
}