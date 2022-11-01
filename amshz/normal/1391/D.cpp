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
 
const int xn = 1e6 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;

int n, m, ans = inf, res, tot, mn;
string s[xn], t[xn];

void solve1(){
	for (int flag = 0; flag < 2; ++ flag){
		res = 0;
		for (int i = 0; i < m; ++ i){
			if (i % 2 == flag) res += (s[0][i] == s[1][i]);
			else res += (s[0][i] != s[1][i]);
		}
		ans = min(ans, res);
	}
	cout << ans << endl;
}
void solve2(){
	for (int i = 0; i < 2; ++ i){
		for (int j = 0; j < 2; ++ j){
			res = 0;
			for (int k = 0; k < m; ++ k){
				mn = inf;
				for (int mask = 0; mask < 8; ++ mask){
					bool fl1 = (mask & 1) > 0;
					bool fl2 = (mask & 2) > 0;
					bool fl3 = (mask & 4) > 0;
					fl1 ^= fl2;
					fl2 ^= fl3;
					tot = 0;
					tot += fl1 != (s[0][k] - '0');
					tot += fl2 != (s[1][k] - '0');
					tot += fl3 != (s[2][k] - '0');
					if (fl1 ^ fl2 == (k % 2) ^ i || fl2 ^ fl3 == (k % 2) ^ j) continue;
					mn = min(mn, tot);
				}
				res += mn;
			}
			ans = min(ans, res);
		}
	}
	cout << ans << endl;
}
void solve(){
	for (int i = 0; i < 2; ++ i){
		res = 0;
		for (int j = 0; j < m; ++ j) res += ((s[0][j] - '0') % 2 == i);
		ans = min(ans, res);
	}
	cout << ans << endl;
}
 
int main(){
    InTheNameOfGod;
    
    cin >> n >> m;
    for (int i = 0; i < n; ++ i) cin >> s[i];
    if (n > 3 && m > 3) kill(- 1);
    if (n == 1 || m == 1) kill(0);
    if (n == 1){
    	solve();
    	return 0;
	}
    if (n == 2){
    	solve1();
    	return 0;
	}
	if (n == 3){
		solve2();
		return 0;
	}
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j)
			t[j] += s[i][j];
	for (int i = 0; i < m; ++ i) s[i] = t[i];
	swap(n, m);
	if (n == 1){
		solve();
		return 0;
	}
	if (n == 2){
		solve1();
		return 0;
	}
	if (n == 3){
		solve2();
		return 0;
	}
    return 0;
}