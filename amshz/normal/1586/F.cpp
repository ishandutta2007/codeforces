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
 
int n, m, a[xn][xn], mx;
 
void solve(int l, int r, int k, int c = 1){
	if (r <= l + 1)
		return;
	mx = max(mx, c);
	int ptr = l;
	while (ptr < r){
		int t = (r - ptr + k - 1) / k;
		for (int i = l; i < ptr; ++ i)
			for (int j = ptr; j < ptr + t; ++ j)
				a[i][j] = c;
		solve(ptr, ptr + t, m, c + 1);
		ptr += t, -- k;
	}
}
 
int main(){
	fast_io;
 
	cin >> n >> m;
	solve(1, n + 1, m);
	cout << mx << endl;
	for (int i = 1; i <= n; ++ i)
		for (int j = i + 1; j <= n; ++ j)
			cout << a[i][j] << sep;
	cout << endl;
 
	return 0;
}