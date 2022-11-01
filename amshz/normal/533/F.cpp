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
const int xm = 26 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod[3] = {1000000007, 1000000009, 998244353};
const ll MOD = 1111118111111;
const int base = 2;

int n, m, a[3][xm], b[3][xm];
int pw[3][xn], inv[xm];
string s, t;
bool mark[xm];
vector <int> ans;

bool check(int x, int y){
	bool f = true;
	for (int i = 0; i < 3; ++ i)
		f &= a[i][x] == b[i][y];
	return f;
}

int main(){
	InTheNameOfGod;
	
	for (int i = 0; i < 3; ++ i)
		pw[i][0] = 1, inv[i] = power(2, mod[i] - 2, mod[i]);
	for (int j = 0; j < 3; ++ j)
		for (int i = 1; i < xn; ++ i)
			pw[j][i] = pw[j][i - 1] * 2LL % mod[j];
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; ++ i){
		for (int j = 0; j < 3; ++ j){
			b[j][t[i] - 'a'] = (b[j][t[i] - 'a'] + pw[j][i]) % mod[j];
			a[j][s[i] - 'a'] = (a[j][s[i] - 'a'] + pw[j][i]) % mod[j];
		}
	}
	bool flag = true;
	for (int i = 0; i < 26; ++ i){
		mark[i] = true;
		for (int j = 0; j < 3; ++ j)
			mark[i] &= !a[j][i];
	}
	for (int i = 0; i < 26; ++ i){
		if (mark[i]) continue;
		for (int j = 0; j < 26; ++ j){
			if (!check(i, j)) continue;
			flag &= check(j, i);
			mark[i] = mark[j] = true;
			break;
		}
		flag &= mark[i];
	}
	if (flag)
		ans.push_back(1);
	for (int i = m; i < n; ++ i){
		for (int j = 0; j < 3; ++ j){
			a[j][s[i - m] - 'a'] = (a[j][s[i - m] - 'a'] - 1 + mod[j]) % mod[j];
			for (int k = 0; k < 26; ++ k)
				a[j][k] = ll(a[j][k]) * ll(inv[j]) % mod[j];
			a[j][s[i] - 'a'] = (a[j][s[i] - 'a'] + pw[j][m - 1]) % mod[j];
		}
		bool flag = true;
		for (int i = 0; i < 26; ++ i){
			mark[i] = true;
			for (int j = 0; j < 3; ++ j)
				mark[i] &= !a[j][i];
		}
		for (int i = 0; i < 26; ++ i){
			if (mark[i]) continue;
			for (int j = 0; j < 26; ++ j){
				if (!check(i, j)) continue;
				flag &= check(j, i);
				mark[i] = mark[j] = true;
				break;
			}
			flag &= mark[i];
		}
		if (flag)
			ans.push_back(i - m + 2);
	}
	cout << SZ(ans) << endl;
	for (int x : ans)
		cout << x << sep;
	cout << endl;
	
	return 0;
}