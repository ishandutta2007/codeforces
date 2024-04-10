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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll qq, n, W, sum;
pll a[xn];
vector <int> ans;

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n >> W;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i].A, a[i].B = i;
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);
		sum = 0, ans.clear();
		for (int i = 1; i <= n; ++ i){
			if (a[i].A > W)
				continue;
			sum += a[i].A;
			if (sum > W)
				break;
			ans.push_back(a[i].B);
		}
		if (!SZ(ans) || sum + sum < W){
			cout << - 1 << endl;
			continue;
		}
		cout << SZ(ans) << endl;
		for (int x : ans)
			cout << x << sep;
		cout << endl;
	}
	
	return 0;
}