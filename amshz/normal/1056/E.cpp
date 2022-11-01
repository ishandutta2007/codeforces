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
typedef pair <ld, ld>                                  pll;
 
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

//const ll md = 1e9 + 7;//998244353;
const int xn = 2e6 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int Md[3] = {1000000007, 987654319, 1000000009};
const int TM = 3;
const int Base = 257;

int n, m, Pw[3][xn], Inv[3][xn], PH[3][xn], INV[3], a, b, ptr, ans, last[2][3];
string s, t;

ll get(int l, int r, int dx) { return ll((PH[dx][r] - PH[dx][l - 1] + Md[dx]) % Md[dx]) * ll(Inv[dx][l - 1]) % Md[dx];}
bool Check(int l, int r, int f){
	bool flg = true;
	if (last[f][0] != -1)
		for (int i = 0; i < TM; ++ i)
			flg &= last[f][i] == get(l, r, i);
	for (int i = 0; i < TM; ++ i)
		last[f][i] = get(l, r, i);
	return flg;
}

int main(){
    InTheNameOfGod;
    
    cin >> s >> t;
    n = SZ(s), m = SZ(t);
    for (int i = 0; i < TM; ++ i){
    	Pw[i][0] = Inv[i][0] = 1;
    	INV[i] = power(Base, Md[i] - 2, Md[i]);
	}
	t = '.' + t;
	for (int i = 0; i < TM; ++ i){
		for (int j = 1; j <= m; ++ j){
			Pw[i][j] = ll(Pw[i][j - 1]) * Base % Md[i];
			Inv[i][j] = ll(Inv[i][j - 1]) * ll(INV[i]) % Md[i];
			PH[i][j] = (PH[i][j - 1] + ll(Pw[i][j]) * ll(t[j] - 'a' + 1) % Md[i]) % Md[i];
		}
	}
	for (int i = 0; i < n; ++ i)	a += s[i] - '0', b += '1' - s[i];
	for (ll i = 1; i <= m; ++ i){
		if (m - i * a <= 0 || (m - i * a) % b)	continue;
		ll j = (m - i * a) / b;
		bool flag = true;
		ptr = 1;
		memset(last, -1, sizeof last);
		for (int k = 0; k < n; ++ k){
			if (s[k] == '0') flag &= Check(ptr, ptr + j - 1, 0), ptr += j;
			else flag &= Check(ptr, ptr + i - 1, 1), ptr += i;
			if (!flag)	break;
		}
		ans += flag;
		for (int k = 0; k < TM; ++ k)	flag &= last[0][k] == last[1][k];
		ans -= flag;
	}
	cout << ans << endl;
	
    
    return 0;
}