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
 
const int xn = 1e6 + 10;
const int xm = 3e5 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod[2] = {1000000007, 998244353};
const int base = 257;

int qq, n, q, a[xm], b[xm], m, last, ans, sum, cnt;
bool p[xn];
pll hsh[xn], pw[xn];
vector <pii> vec;

int main(){
	InTheNameOfGod;
	
	pw[0] = {1, 1};
	for (ll i = 1; i < xn; ++ i){
		pw[i].A = pw[i - 1].A * 2LL % mod[0];
		pw[i].B = pw[i - 1].B * 2LL % mod[1];
	}
	for (int i = 2; i < xn; ++ i){
		if (p[i])
			continue;
		for (int j = i; j < xn; j += i){
			int x = j, y = 0;
			while (x % i == 0)
				x /= i, ++ y;
			if (y % 2){
				hsh[j].A = (hsh[j].A + pw[i].A) % mod[0];
				hsh[j].B = (hsh[j].B + pw[i].B) % mod[1];
			}
			if (j > i)
				p[j] = true;
		}
	}
	cin >> qq;
	while (qq --){
		cin >> n;
		vec.clear();
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], vec.push_back(hsh[a[i]]);
		sort(all(vec)), m = last = ans = sum = cnt = 0;
		for (int i = 0; i < SZ(vec); ++ i){
			if (!vec[i].A && !vec[i].B)
				++ cnt;
			if (i && vec[i] != vec[i - 1])
				b[m ++] = last, last = 0;
			++ last;
		}
		b[m ++] = last;
		for (int i = 0; i < m; ++ i){
			ans = max(ans, b[i]);
			if (b[i] % 2 == 0)
				sum += b[i];
		}
		if (cnt % 2)
			sum += cnt;
		cin >> q;
		while (q --){
			ll w;
			cin >> w;
			if (!w)
				cout << ans << endl;
			else
				cout << max(ans, sum) << endl;
		}
	}
	
	return 0;
}