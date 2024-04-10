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
 
const int xn = 1e3 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;

int qq, n, num[xn], cnt[xn];
vector <int> vec, ans;

void solve(){
	for (int i = 0; i < n; ++ i){
		if (num[i] != i){
			ans.push_back(i + 1);
			-- cnt[num[i]];
			num[i] = n;
			++ cnt[n];
			return;
		}
	}
}
 
int main(){
    InTheNameOfGod;
    
    cin >> qq;
    while (qq --){
    	cin >> n;
    	for (int i = 0; i <= n; ++ i) cnt[i] = 0;
    	for (int i = 0; i < n; ++ i) cin >> num[i], ++ cnt[num[i]];
    	ans.clear();
    	for (int i = 0; i < n + n; ++ i){
    		int mex = n;
    		for (int j = 0; j < n; ++ j){
    			if (!cnt[j]){
    				mex = j;
    				break;
				}
			}
			if (mex == n){
				bool flag = true;
				for (int i = 0; i < n; ++ i) flag &= num[i] == i;
				if (flag) break;
				solve();
				continue;
			}
			ans.push_back(mex + 1);
			-- cnt[num[mex]];
			++ cnt[mex];
			num[mex] = mex;
		}
		cout << SZ(ans) << endl;
		for (int x : ans) cout << x << sep;
		cout << endl;
	}
	
    return 0;
}