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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;
 
int qq, n, ptr, cnt[2][xn], dp[xn], ans, num[xn];
map <int, int> mp;
vector <int> compress, vec[xn];
 
int main(){
    InTheNameOfGod;
    
    cin >> qq;
    while (qq --){
    	cin >> n;
    	for (int i = 0; i < n; ++ i) cin >> num[i];
    	compress.clear(), mp.clear();
    	for (int i = 0; i < n; ++ i) compress.push_back(num[i]);
    	ptr = 0;
    	Sort(compress);
    	for (int i = 0; i < n; ++ i){
    		if (!i || compress[i] != compress[i - 1]){
    			mp[compress[i]] = ptr ++;
			}
		}
		for (int i = 0; i < ptr; ++ i) cnt[0][i] = cnt[1][i] = 0, vec[i].clear();
		if (ptr == 1){
			cout << 0 << endl;
			continue;
		}
		for (int i = 0; i < n; ++ i) vec[mp[num[i]]].push_back(i);
		for (int i = 1; i < ptr; ++ i){
			for (int x : vec[i - 1]){
				if (x < vec[i].front()) ++ cnt[0][i];
			}
		}
		for (int i = 0; i < ptr - 1; ++ i){
			for (int x : vec[i + 1]){
				if (x > vec[i].back()) ++ cnt[1][i];
			}
		}
		dp[0] = SZ(vec[0]);
		ans = dp[0] + cnt[1][0];
		for (int i = 1; i < ptr; ++ i){
			dp[i] = SZ(vec[i]);
			if (cnt[0][i] == SZ(vec[i - 1])) dp[i] += dp[i - 1];
			else dp[i] += cnt[0][i];
			ans = max(ans, dp[i] + cnt[1][i]);
		}
		for (int i = 1; i < ptr; ++ i){
			for (int j = 0; j < SZ(vec[i]); ++ j){
				int x = vec[i][j];
				int l = - 1, r = SZ(vec[i - 1]);
				while (r - l > 1){
					int mid = l + r >> 1;
					if (vec[i - 1][mid] < x) l = mid;
					else r = mid;
				}
				ans = max(ans, SZ(vec[i]) - j + r);
			}
		}
		cout << n - ans << endl;
	}
	
    return 0;
}