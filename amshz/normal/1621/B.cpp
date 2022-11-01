//khodaya khodet komak kon
# include <bits/stdc++.h>

using namespace std;

typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <ll, ll>                                  pii;
typedef pair <pii, ll>                                  ppi;
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
const int mod = 998244353;
const int base = 257;

int qq, n;
ppi L, R, T;
ppi a[xn];

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		L.A.A = inf;
		R.A.A = 0;
		T.A.A = 0;
		for (int i = 1; i <= n; ++ i){
			cin >> a[i].A.A >> a[i].A.B >> a[i].B;
			if (a[i].A.B - a[i].A.A + 1 > T.A.A)
				T = {{a[i].A.B - a[i].A.A + 1, a[i].B}, i};
			if (a[i].A.B - a[i].A.A + 1 == T.A.A && a[i].B < T.A.B)
				T = {{a[i].A.B - a[i].A.A + 1, a[i].B}, i};
			if (a[i].A.A < L.A.A)
				L = {{a[i].A.A, a[i].B}, i};
			if (a[i].A.A == L.A.A && a[i].B < L.A.B)
				L = {{a[i].A.A, a[i].B}, i};
			if (a[i].A.B > R.A.A)
				R = {{a[i].A.B, a[i].B}, i};
			if (a[i].A.B == R.A.A && a[i].B < R.A.B)
				R = {{a[i].A.B, a[i].B}, i};
			ll ans = INF;
			if (T.A.A == R.A.A - L.A.A + 1)
				ans = min(ans, T.A.B);
			ans = min(ans, R.A.B + L.A.B);
			cout << ans << endl;
		}
	}

	return 0;
}