#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) //cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

ll MOD = (ll) 10399;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) LONG_LONG_MAX / 100;
const ld EPS = (ld) 1e-8;
const ll P = 104107;

ll mul(ll a, ll b){
	return (a * b) % MOD;
}

ll pw(ll b, ll p){
	if(p == 0) return 1;
	if(p & 1) return mul(b, pw(b, p - 1));
	return pw(mul(b, b), p / 2);
}
ll inv(ll x){
	return pw(x, MOD - 2);
}

ll dp[1010][55][55];

ll f(str s){
	ll n = s.size();
	debug(s);
	//ll t = 0;
	for(int i = 1; i <= n; i++){
		ll fl = 1;
		for(int j = 0; j + i < n; j++){
			if(s[j] != s[i + j]) fl = 0;
		}
		if(fl == 1) return n - i;
	}
}

ll d1[55][28];
ll d2[55][28];

ll lc(str s, str t){
	ll n = s.size();
	ll m = t.size();
	for(int i = 0; i <= m; i++){
		ll fl = 1;
		for(int j = i; j<m;j++){
			if(s[j - i] != t[j]) fl = 0;
		}
		if(fl == 1) return m - i;
	}
	return 0;
}


ll calc(str s, ll ind, char c){
	str r = "";
	for(int i = 0; i < ind; i++) r += s[i];
	r += c;
	return lc(s, r);
}

int main(){
	//cerr << (lc("amoo", "bam"));
	str a, s ,t;

	cin >> a >> s >> t;
	ll ns = f(s);
	ll nt = f(t);
	
	for(int i = 0; i < s.size(); i++) for(int j = 0; j < 26; j++) d1[i][j] = calc(s, i, 'a' + j);
	for(int i = 0; i < t.size(); i++) for(int j = 0; j < 26; j++) d2[i][j] = calc(t, i, 'a' + j);
	
	ll l = a.size(); a = '!' + a;
	ll n = s.size(); s = '!' + s;
	ll m = t.size(); t = '!' + t;
	
	for(int i = 0; i < 1010; i++) for(int j = 0; j < 55; j++) for(int j2 = 0; j2 < 55; j2++) dp[i][j][j2] = -INF;
	debug(ns);
	//debug("S");
	//cerr << d2[0]['a'-'a'] << '\n';
	dp[0][0][0] = 0;
	char nx;
	ll del;
	ll nj, nk;
	for(int i = 0; i < l; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				nx = a[i + 1];
				for(int al = 0; al < 26; al ++){
					if(a[i + 1] == '*') nx = ('a' + al);
					else nx = a[i + 1];
					nj = d1[j][nx - 'a'];
					nk = d2[k][nx - 'a'];
					
					del = 0;
					if(nj == n) del ++, nj = ns;
					if(nk == m) del --, nk = nt;
					dp[i + 1][nj][nk] = max(dp[i][j][k] + del, dp[i + 1][nj][nk]);
				}
			}
		}
		//debug(i);
	}
	//debug(dp[2][0][0]);
	ll ans = -INF;
	for(int j = 0; j < 55; j++) for(int j2 = 0; j2 < 55; j2++) ans = max(ans, dp[l][j][j2]);
	cout << ans;
	return 0;
}


/*

                                 ____              ,----..               ,----..
   ,---,                       ,'  , `.           /   /   \             /   /   \
  '  .' \                   ,-+-,.' _ |          /   .     :           /   .     :
 /  ;    '.              ,-+-. ;   , ||         .   /   ;.  \         .   /   ;.  \
:  :       \            ,--.'|'   |  ;|        .   ;   /  ` ;        .   ;   /  ` ;
:  |   /\   \          |   |  ,', |  ':        ;   |  ; \ ; |        ;   |  ; \ ; |
|  :  ' ;.   :         |   | /  | |  ||        |   :  | ; | '        |   :  | ; | '
|  |  ;/  \   \        '   | :  | :  |,        .   |  ' ' ' :        .   |  ' ' ' :
'  :  | \  \ ,'        ;   . |  ; |--'         '   ;  \; /  |        '   ;  \; /  |
|  |  '  '--'          |   : |  | ,             \   \  ',  /          \   \  ',  /
|  :  :                |   : '  |/               ;   :    /            ;   :    /
|  | ,'                ;   | |`-'                 \   \ .'              \   \ .'
`--''                  |   ;/                      `---`                 `---`
                       '---'

*/