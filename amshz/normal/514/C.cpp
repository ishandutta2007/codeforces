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

const ll md = 101111111111;
const int xn = 6e5 + 10;
const int xm = 1e2 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD[4] = {1000000009, 1000000007, 987654319, 999999937};
const int TM = 3;
const int BASE = 257;

ll n, m, pw[TM][xn], res, inv[TM][xn], Inv[TM], sz;
set <int> st[xn];
string s;
bool flag;

void build(){
	for (int i = 0; i < TM; ++ i){
		pw[i][0] = inv[i][0] = 1;
		Inv[i] = power(BASE, MOD[i] - 2, MOD[i]);
	}
	for (int i = 0; i < TM; ++ i){
		for (int j = 1; j < xn; ++ j){
			pw[i][j] = ll(pw[i][j - 1]) * ll(BASE) % MOD[i];
			inv[i][j] = ll(inv[i][j - 1]) * ll(Inv[i]) % MOD[i];
		}
	}
}

int main(){
    InTheNameOfGod;
    
    build();
    cin >> n >> m;
    while (n --){
    	cin >> s;
    	sz = SZ(s);
    	s = '.' + s;
    	res = 0;
    	for (int i = 0; i < TM; ++ i) for (int j = 1; j <= sz; ++ j) res = (res + ll(pw[i][j]) * ll(s[j] - 'a' + 1) % MOD[i]) % md;
    	st[sz].insert(res);
	}
	while (m --){
		cin >> s;
		sz = SZ(s);
		s = '.' + s;
		flag = false;
		res = 0;
    	for (int i = 0; i < TM; ++ i) for (int j = 1; j <= sz; ++ j) res = (res + ll(pw[i][j]) * ll(s[j] - 'a' + 1) % MOD[i]) % md;
    	for (int j = 1; j <= sz; ++ j){
    		for (int i = 0; i < TM; ++ i) res = (res - ll(pw[i][j]) * ll(s[j] - 'a' + 1) % MOD[i] + md) % md;
    		for (int k = 0; k < 3; ++ k){
    			if (k == s[j] - 'a') continue;
    			for (int i = 0; i < TM; ++ i) res = (res + ll(pw[i][j]) * ll(k + 1) % MOD[i] + md) % md;
    			flag |= (st[sz].find(res) != st[sz].end());
    			for (int i = 0; i < TM; ++ i) res = (res - ll(pw[i][j]) * ll(k + 1) % MOD[i] + md) % md;
			}
			for (int i = 0; i < TM; ++ i) res = (res + ll(pw[i][j]) * ll(s[j] - 'a' + 1) % MOD[i] + md) % md;
		}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
    return 0;
}