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
const int mod = 998244353;
const int base = 257;

int n;

int main(){
	fast_io;

	cin >> n;
	if (n == 1 || n == 2){
		cout << "YES" << endl;
		for (int i = 1; i <= n; ++ i)
			cout << i << endl;
		return 0;
	}
	if (n == 4){
		cout << "YES\n1\n3\n2\n4\n";
		return 0;
	}
	for (int i = 2; i < n; ++ i)
		if (n % i == 0)
			kill("NO");
	cout << "YES" << endl;
	cout << 1 << endl;
	for (int i = 1; i + 1 < n; ++ i)
		cout << power(i, n - 2, n) + 1 << endl;
	cout << n << endl;

	return 0;
}