# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
const ll md = 1e9 + 7;
const int xn = 2e5 + 10;
const int xm = 1e3 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const ll inf = 1e18+ 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
 
 
int qq, n, k, cnt[xn][26], ans;
string a, abc = "abcdefghijklmnopqrstuvwxyz";
 
 
int main(){
	fast_io;
	
	cin >> qq;
	while (qq --){
		for (int i = 0; i <= n; i ++) for (int j = 0; j < 26; j ++) cnt[i][j] = 0;
		ans = 0;
		cin >> n >> k >> a;
		for (int i = 0; i < k; i ++){
			for (int j = 0; j < 26; j ++){
				for (int p = i; p < n; p += k){
					if (a[p] != abc[j]) cnt[i][j] ++;
				}
			}
		}
		for (int i = 0; i < k; i ++){
			if (k - i - 1 < i) break;
			int mn = 1e9;
			for (int j = 0; j < 26; j ++){
				int s = cnt[i][j];
				if (k - i - 1 != i) s += cnt[k - i - 1][j];
				mn = min(mn, s);
			}
			ans += mn;
		}
		cout << ans << endl;
	}
	
	
	return 0;
}