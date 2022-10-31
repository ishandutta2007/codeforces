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
typedef pair <ll, ll>                                    pll;
typedef pair <pii, int>                                  ppi;
typedef pair <pll, ll >                                  ppl;
typedef pair <int, pii>                                  pip;
typedef pair <ll , pll>                                  plp;
typedef pair <pii, pii>                                  ppp;
typedef pair <pll, pll>                                  PPP;
 
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
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m, ind, L, d, q, in2, p[xn];
pii a[xn];
bool f;

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].A, a[i].B = i;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i)
		p[a[i].B] = i;
	while (m --){
		cin >> ind >> L, ind = p[ind];
		int l = ind, r = n + 1;
		while (r - l > 1){
			int mid = l + r >> 1;
			if (a[mid].A - a[ind].A <= L)
				l = mid;
			else
				r = mid;
		}
		L -= a[l].A - a[ind].A, ind = l;
		q = 50, f = true;
		while (q --){
			if (!f){
				int l = ind, r = n + 1;
				while (r - l > 1){
					int mid = l + r >> 1;
					if (a[mid].A - a[ind].A <= L)
						l = mid;
					else
						r = mid;
				}
				in2 = l;
			}
			else{
				int l = 0, r = ind;
				while (r - l > 1){
					int mid = l + r >> 1;
					if (a[ind].A - a[mid].A <= L)
						r = mid;
					else
						l = mid;
				}
				in2 = r;
			}
			if (ind == in2){
				f ^= 1;
				continue;
			}
			if ((L / abs(a[ind].A - a[in2].A)) % 2)
				f ^= 1, L %= abs(a[ind].A - a[in2].A), ind = in2;
			else
				L %= abs(a[ind].A - a[in2].A);
		}
		cout << a[ind].B << endl;
	}
		
	return 0;
}