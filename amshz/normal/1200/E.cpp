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
 
const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod[3] = {998244353, 1000000007, 1000000009};
const int TM = 3;
const int base = 257;

int m, inv[3][xn], part[3][xn], n, pw[3][xn], Inv[3], prt[3][xn], q;
string ans, s;

void add(char c){
	ans += c, ++ n;
	for (int i = 0; i < TM; ++ i)
		part[i][n] = (ll(part[i][n - 1]) + ll(pw[i][n]) * ll(c) % mod[i]) % mod[i];
}
int get1(int l, int r, int id){ return ll(ll(part[id][r]) - ll(part[id][l - 1]) + ll(mod[id])) * ll(inv[id][l - 1]) % mod[id];}
int get2(int l, int r, int id){ return ll(ll(prt[id][r]) - ll(prt[id][l - 1]) + ll(mod[id])) * ll(inv[id][l - 1]) % mod[id];}
bool check(int l1, int r1, int l2, int r2){
	bool flag = true;
	for (int i = 0; i < 3; ++ i)
		flag &= get1(l1, r1, i) == get2(l2, r2, i);
	return flag;
}

int main(){
	InTheNameOfGod;
	
	for (int i = 0; i < TM; ++ i)
		pw[i][0] = inv[i][0] = 1, Inv[i] = power(base, mod[i] - 2, mod[i]);
	for (int i = 0; i < TM; ++ i){
		for (int j = 1; j < xn; ++ j){
			pw[i][j] = ll(pw[i][j - 1]) * ll(base) % mod[i];
			inv[i][j] = ll(inv[i][j - 1]) * ll(Inv[i]) % mod[i];
		}
	}
	cin >> q;
	while (q --){
		cin >> s, m = SZ(s);
		s = '.' + s;
		for (int j = 0; j < TM; ++ j)
			for (int i = 1; i <= m; ++ i)
				prt[j][i] = (ll(prt[j][i - 1]) + ll(pw[j][i]) * ll(s[i]) % mod[j]) % mod[j];
		int last = 0;
		for (int i = 1; i <= min(n, m); ++ i)
			if (check(n - i + 1, n, 1, i))
				last = i;
		for (int i = last + 1; i <= m; ++ i)
			add(s[i]);
	}
	cout << ans << endl;
	
	return 0;
}