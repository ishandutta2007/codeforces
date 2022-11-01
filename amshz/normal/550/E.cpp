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

int n, a[xn];

int main(){
	fast_io;

	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	if (a[n])
		kill("NO");
	if (n == 1){
		cout << "YES" << endl << 0 << endl;
		return 0;
	}
	if (n == 2){
		if (a[1]){
			cout << "YES" << endl << "1->0" << endl;
			return 0;
		}
		kill("NO");
	}
	if (a[n - 1]){
		cout << "YES" << endl;
		for (int i = 1; i < n; ++ i)
			cout << a[i] << "->";
		cout << 0;
		return 0;
	}
	if (!a[n - 2]){
		cout << "YES" << endl;
		for (int i = 1; i < n - 2; ++ i)
			cout << a[i] << "->";
		cout << "(0->0)->0";
		return 0;
	}
	int ptr = n - 3;
	while (ptr && a[ptr])
		-- ptr;
	if (!ptr)
		kill("NO");
	cout << "YES" << endl;
	for (int i = 1; i < ptr; ++ i)
		cout << a[i] << "->";
	cout << "(0->(";
	for (int i = ptr + 1; i < n - 1; ++ i)
		cout << a[i] << "->";
	cout << "0))->0";

	return 0;
}