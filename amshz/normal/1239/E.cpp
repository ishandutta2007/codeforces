// khodaya khodet komak kon
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
 
const int xn = 25 + 10;
const int xm = 5e4 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, a[2][xn], b[xn + xn], sum;
ll knap[xn][xm * xn];

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n; ++ i)
		cin >> a[0][i], b[i] = a[0][i], sum += a[0][i];
	for (int i = 0; i < n; ++ i)
		cin >> a[1][i], b[i + n] = a[1][i], sum += a[1][i];
	sort(b, b + n + n);
	for (int i = 0; i < xn; ++ i)
		for (int j = 0; j < xn * xm; ++ j)
			knap[i][j] = - 1;
	knap[0][0] = 0;
	for (int i = 2; i < n + n; ++ i)
		for (int t = n - 1; t > 0; -- t)
			for (int j = b[i]; j < xm * xn; ++ j)
				if (knap[t - 1][j - b[i]] != - 1)
					knap[t][j] = knap[t - 1][j - b[i]] + (1LL << i);
	a[0][0] = b[0], a[1][n - 1] = b[1];
	sum -= b[0] + b[1];
	for (int i = sum / 2; i >= 0; -- i){
		if (knap[n - 1][i] == - 1)
			continue;
		int pt1 = 1, pt2 = n - 2;
		for (int j = 2; j < n + n; ++ j){
			if ((knap[n - 1][i] & (1LL << j)))
				a[0][pt1 ++] = b[j];
			else
				a[1][pt2 --] = b[j];
		}
		break;
	}
	for (int i = 0; i < n; ++ i)
		cout << a[0][i] << sep;
	cout << endl;
	for (int i = 0; i < n; ++ i)
		cout << a[1][i] << sep;
	cout << endl;
	
	return 0;
}