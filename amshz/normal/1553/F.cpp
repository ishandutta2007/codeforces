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

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

ll n, a[xn], fen[2][xn], ans, sum;

void mofen(int id, int pos, ll val){
	for (pos += 5; pos < xn; pos += pos & - pos)
		fen[id][pos] += val;
}
ll gefen(int id, int pos){
	ll res = 0;
	for (pos += 5; pos > 0; pos -= pos & - pos)
		res += fen[id][pos];
	return res;
}

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		ans += (i - 1) * a[i] - gefen(1, a[i]) + sum;
		for (int j = a[i]; j < xn; j += a[i]){
			ans -= (gefen(0, xn - 10) - gefen(0, j - 1)) * a[i];
			mofen(1, j, a[i]);
		}
		mofen(0, a[i], 1);
		sum += a[i];
		cout << ans << sep;
	}
	cout << endl;

	return 0;
}