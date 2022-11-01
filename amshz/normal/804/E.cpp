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

const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, a[xn], p[xn];

void add(int x, int y){
	swap(p[a[x]], p[a[y]]);
	swap(a[x], a[y]);
	cout << x << sep << y << endl;
}
void solve(int l, int r){
	if (l == r)
		return;
	if (p[l] != l){
		for (int i = l + 1; i <= r; ++ i)
			if (i != p[l])
				add(l, i);
		add(l, p[l]);
		solve(l + 1, r);
		return;
	}
	if (p[r] != r){
		for (int i = l; i < r; ++ i)
			if (i != p[r])
				add(i, r);
		add(p[r], r);
		solve(l, r - 1);
		return;
	}
	for (int i = l + 1; i < r - 1; ++ i)
		add(l, i);
	for (int i = r - 1; i > l + 1; -- i)
		add(i, r);
	add(l, r - 1), add(l + 1, r), add(l, r);
	solve(l + 1, r - 1);
}

int main(){
	fast_io;

	cin >> n;
	if (n % 4 == 2 || n % 4 == 3)
		kill("NO");
	cout << "YES" << endl;
	for (int i = 1; i <= n; ++ i)
		a[i] = p[i] = i;
	solve(1, n);
	for (int i = 1; i <= n; ++ i)
		if (a[i] != i)
			kill("FUCK");

	return 0;
}