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

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, m, k, a[xn], ps[xn];

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n >> m >> k;
		for (int i = 1; i <= k; ++ i)
			cin >> a[i];
		fill(ps, ps + k + 2, 0);
		int mx = 0;
		for (int i = k; 1 <= i; -- i)
			mx = max(mx, a[i]), ++ ps[mx];
		for (int i = k; 1 <= i; -- i)
			ps[i] += ps[i + 1];
		bool flag = true;
		for (int i = 1; i <= k; ++ i)
			flag &= (ps[a[i]] - k + a[i] <= n * m - 3);
		if (flag)
			cout << "YA" << endl;
		else
			cout << "TIDAK" << endl;
	}

	return 0;
}