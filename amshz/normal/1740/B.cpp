// khodaya khodet komak kon
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

int power(int a, ll b, int md){
	int res = 1;
	while (b){
		if ((b & 1))
			res = 1ll * res * a % md;
		a = 1ll * a * a % md;
		b >>= 1;
	}
	return res;
}

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n;
pii a[xn];
ll ans;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n, ans = 0;
		for (int i = 1; i <= n; ++ i){
			cin >> a[i].A >> a[i].B;
			if (a[i].A < a[i].B)
				swap(a[i].A, a[i].B);
			ans += 2ll * (a[i].A + a[i].B);
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i < n; ++ i)
			ans -= 2ll * a[i].A;
		cout << ans << endl;
	}

	return 0;
}