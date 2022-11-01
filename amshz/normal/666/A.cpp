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
 
const int xn = 1e4 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n;
string s, last[2][xn], s1, s2;
set <string> st;
bool dp[2][xn];

int main(){
	InTheNameOfGod;
	
	cin >> s;
	n = SZ(s);
	dp[0][n] = dp[1][n] = true;
	for (int i = n - 1; i >= 0; -- i){
		for (int j = i; j < min(n, i + 2); ++ j)
			last[0][i] += s[j];
		for (int j = i; j < min(n, i + 3); ++ j)
			last[1][i]+= s[j];
		if (SZ(last[0][i]) == 2){
			if (dp[0][i + 2] && last[0][i] != last[0][i + 2])
				dp[0][i] = true;
			if (dp[1][i + 2])
				dp[0][i] = true;
		}
		if (SZ(last[1][i]) == 3){
			if (dp[0][i + 3])
				dp[1][i] = true;
			if (dp[1][i + 3] && last[1][i] != last[1][i + 3])
				dp[1][i] = true;
		}
		if (i > 4){
			if (dp[0][i])
				st.insert(last[0][i]);
			if (dp[1][i])
				st.insert(last[1][i]);
		}
	}
	cout << SZ(st) << endl;
	for (string x : st)
		cout << x << endl;
			
	return 0;
}