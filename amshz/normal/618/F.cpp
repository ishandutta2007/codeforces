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
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, c[xn], ptr;
pll a[xn], part[xn], ans[2];
vector <pii> vec[xn];
bool flag;

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].A, part[i].A = part[i - 1].A + a[i].A;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].B, part[i].B = part[i - 1].B + a[i].B;
	if (part[n].A > part[n].B){
		for (int i = 1; i <= n; ++ i){
			swap(a[i].A, a[i].B);
			swap(part[i].A, part[i].B);
		}
		flag = true;
	}
	for (int i = 0; i <= n; ++ i){
		while (part[ptr].B < part[i].A)
			++ ptr;
		vec[part[ptr].B - part[i].A].push_back({i, ptr});
	}
	for (int i = 0; i < n; ++ i){
		if (SZ(vec[i]) < 2)
			continue;
		ans[0] = vec[i][0];
		ans[1] = vec[i][1];
		break;
	}
	if (flag){
		swap(ans[0].A, ans[0].B);
		swap(ans[1].A, ans[1].B);
	}
	cout << ans[1].A - ans[0].A << endl;
	for (int i = ans[0].A + 1; i <= ans[1].A; ++ i)
		cout << i << sep;
	cout << endl;
	cout << ans[1].B - ans[0].B << endl;
	for (int i = ans[0].B + 1; i <= ans[1].B; ++ i)
		cout << i << sep;
	cout << endl;
	
	return 0;
}