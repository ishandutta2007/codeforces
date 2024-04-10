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
# define lc                                              id << 1
# define rc                                              lc | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const int TM = 3;
const ll INF = 1e18 + 10;
const int mod[2] = {998244353, 1000696969};
const ll base = 257;

int n, k, g, pw[2][xn], inv[2][xn], Inv[2], hs[2][xn];
string s, t;
map <pii, int> mp;
set <int> st;

pii get(int l, int r){
	pii res;
	res.A = (ll(hs[0][r]) - ll(hs[0][l - 1]) + ll(mod[0])) % mod[0] * ll(inv[0][l - 1]) % mod[0];
	res.B = (ll(hs[1][r]) - ll(hs[1][l - 1]) + ll(mod[1])) % mod[1] * ll(inv[1][l - 1]) % mod[1];
	return res;
}

int main(){
	InTheNameOfGod;
	
	for (int i = 0; i < 2; ++ i){
		pw[i][0] = inv[i][0] = 1;
		Inv[i] = power(base, mod[i] - 2, mod[i]);
		for (int j = 1; j < xn; ++ j){
			pw[i][j] = ll(pw[i][j - 1]) * base % mod[i];
			inv[i][j] = ll(inv[i][j - 1]) * ll(Inv[i]) % mod[i];
		}
	}
	cin >> n >> k >> s >> g;
	s = '.' + s;
	for (int i = 1; i <= k; ++ i)
		s += s[i];
	for (int j = 0; j < 2; ++ j)
		for (int i = 1; i <= (n + 1) * k; ++ i)
			hs[j][i] = (ll(hs[j][i - 1]) + ll(s[i]) * ll(pw[j][i]) % mod[j]) % mod[j];
	for (int i = 1; i <= g; ++ i){
		cin >> t, t = '.' + t;
		pii res = {0, 0};
		for (int j = 1; j <= k; ++ j){
			res.A = (ll(res.A) + ll(t[j]) * ll(pw[0][j]) % mod[0]) % mod[0];
			res.B = (ll(res.B) + ll(t[j]) * ll(pw[1][j]) % mod[1]) % mod[1];
		}
		mp[res] = i;
	}
	for (int i = 1; i <= k; ++ i){
		st.clear();
		for (int j = 1; j <= n; ++ j){
			int l = (j - 1) * k + i, r = j * k + i - 1;
			if (mp[get(l, r)])
				st.insert(mp[get(l, r)]);
		}
		if (SZ(st) < n)
			continue;
		cout << "YES" << endl;
		for (int j = 1; j <= n; ++ j){
			int l = (j - 1) * k + i, r = j * k + i - 1;
			cout << mp[get(l, r)] << sep;
		}
		cout << endl;
		return 0;
	}
	cout << "NO" << endl;
	
	return 0;
}