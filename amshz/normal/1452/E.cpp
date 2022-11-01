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
 
const int xn = 2e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, k, ans;
pii a[xn], part[xn][xn];

bool cmp(pii i, pii j){ return i.A + i.B < j.A + j.B;}
int calc(pii x, pii y){
	return max(0, min(x.B, y.B) - max(x.A, y.A) + 1);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++ i)
		cin >> a[i].A >> a[i].B;
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i + k - 1 <= n; ++ i){
		for (int j = 1; j <= m; ++ j)
			part[i][j].A = part[i][j - 1].A + calc({i, i + k - 1}, a[j]);
		for (int j = m; j >= 1; -- j)
			part[i][j].B = part[i][j + 1].B + calc({i, i + k - 1}, a[j]);
	}
	for (int i = 1; i + k - 1 <= n; ++ i){
		for (int j = i; j + k - 1 <= n; ++ j){
			int x = i + i + k - 1, y = j + j + k - 1;
			int l = 0, r = m + 1, mid;
			while (r - l > 1){
				mid = l + r >> 1;
				int z = a[mid].A + a[mid].B;
				if (abs(x - z) <= abs(y - z)) l = mid;
				else r = mid;
			}
			ans = max(ans, part[i][l].A + part[j][l + 1].B);
		}
	}
	cout << ans << endl;
	
	return 0;
}