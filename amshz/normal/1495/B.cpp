//khodaya khodet komak kon
# include <bits/stdc++.h>

/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/

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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, a[xn], b[4][xn], ps[2][xn], ans;
bool flag;

bool check(int x, int y){
	if (x == y || y < 1 || y > n)
		return true;
	if (x < y){
		if (x - b[0][x] > max(y - b[1][y], b[3][y] - y))
			return true;
		if (b[2][x] < y)
			return max(x - b[0][x], b[2][x] - x) > max(y - b[1][y], b[3][y] - y);
		if (x % 2 != y % 2)
			return false;
		return b[2][x] - x > b[3][y] - y;
	}
	if (b[2][x] - x > max(y - b[1][y], b[3][y] - y))
		return true;
	if (b[0][x] > y)
		return max(x - b[0][x], b[2][x] - x) > max(y - b[1][y], b[3][y] - y);
	if (x % 2 != y % 2)
		return false;
	return x - b[0][x] > y - b[1][y];
}

int main(){
	InTheNameOfGod;

	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		b[0][i] = b[1][i] = i;
		if (i - 1 && a[i - 1] < a[i])
			b[0][i] = b[0][i - 1];
		if (i - 1 && a[i - 1] > a[i])
			b[1][i] = b[1][i - 1];
	}
	for (int i = n; i >= 1; -- i){
		b[2][i] = b[3][i] = i;
		if (i < n && a[i + 1] < a[i])
			b[2][i] = b[2][i + 1];
		if (i < n && a[i + 1] > a[i])
			b[3][i] = b[3][i + 1];
	}
	for (int i = 1; i <= n; ++ i)
		ps[0][i] = max(ps[0][i - 1], max(i - b[1][i], b[3][i] - i));
	for (int i = n; i >= 1; -- i)
		ps[1][i] = max(ps[1][i + 1], max(i - b[1][i], b[3][i] - i));
	for (int i = 1; i <= n; ++ i){
		flag = true;
		int l = b[0][i], r = b[2][i];
		int mx = max(i - l, r - i);
		flag &= (mx > ps[0][l - 1]);
		flag &= (mx > ps[1][r + 1]);
		flag &= check(i, l);
		flag &= check(i, l + 1);
		flag &= check(i, r);
		flag &= check(i, r - 1);
		ans += flag;
	}
	cout << ans << endl;

	return 0;
}