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

int n, a[xn], qq, ans, cnt[xn], last, ted;
vector <pii> vec;
bool flag[xn];

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], cnt[i] = 0;
		last = 0, ans = 0;
		vec.clear();
		for (int i = 1; i < n; ++ i){
			if (a[i] == a[i + 1]){
				vec.push_back({last + 1, i});
				last = i;
				++ ans;
			}
		}
		vec.push_back({last + 1, n});
		for (pii x : vec){
			++ cnt[a[x.A]];
			++ cnt[a[x.B]];
		}
		last = 0;
		for (int i = 1; i <= n; ++ i)
			if (cnt[i] * 2 > ans * 2 + 4)
				last = i;
		if (!last){
			cout << ans << endl;
			continue;
		}
		ted = 0;
		for (int i = 1; i < n; ++ i)
			ted += (a[i] != last && a[i + 1] != last && a[i] != a[i + 1]);
		while (cnt[last] * 2 > ans * 2 + 4){
			if (!ted){
				ans = - 1;
				break;
			}
			-- ted;
			//++ cnt[last];
			++ ans;
		}
		cout << ans << endl;
	}
			
	return 0;
}