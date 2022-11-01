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

const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int qq, n, a[xn], b[xn];

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i];
		for (int i = 1; i <= n; ++ i)
			cin >> b[i];
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; ++ i)
			a[i] += a[i - 1], b[i] += b[i - 1];
		for (int i = n + 1; i <= n + n; ++ i)
			a[i] = a[i - 1] + 100;
		for (int i = 0; i <= n; ++ i){
			int cnt = (n + i) - ((n + i) / 4);
			int x = b[n] - b[max(0, n - cnt)];
			int y = a[n + i] - a[n + i - cnt];
			if (x <= y){
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}