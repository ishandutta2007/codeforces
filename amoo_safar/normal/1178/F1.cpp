#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 998244353LL;
const int Maxn = 5e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}
ll bin_pow(ll b, ll p){
	ll res = 1;
	for(ll j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw)) if(p & j) res = mul(res, pw); 
	return res;
}
ll inv(ll x){
	return bin_pow(x, Mod - 2);
}
ll f[Maxn], iv[Maxn];
//ll nCr(ll n, ll r)

ll wh[Maxn], p[Maxn], mk[Maxn];
ll mn[Maxn][Maxn];
ll dp[Maxn][Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		wh[p[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		mn[i][i] = i;
		for(int j = i + 1; j <= n; j++){
			if(p[j] < p[mn[i][j - 1]]) mn[i][j] = j;
			else mn[i][j] = mn[i][j - 1];
		}
	}
	for(int i = 1; i <= n + 1; i++) dp[i][i - 1] = 1;
	for(int l = 1; l <= n; l++){
		for(int i = 1; i <= n; i++){
			int j = i + l - 1;
			if(j > n) continue;
			if(l == 1){
				dp[i][j] = 1;
				continue;
			}
			ll le = 0, ri = 0;
			ll idx = mn[i][j];
			for(int c = i; c <= idx; c++){
				le += mul(dp[i][c - 1], dp[c][idx - 1]);
			}
			le %= Mod;
			
			for(int c = idx; c <= j; c++){
				ri += mul(dp[idx + 1][c], dp[c + 1][j]);
			}
			ri %= Mod;
			//if(i == 1 and j == n) cerr << idx << " " << ri << " " << le << '\n';
			dp[i][j] = mul(le, ri);
		}
	}
	cout << dp[1][n];
	/*ll ans = 1;
	for(int i = n; i >= 1; i--){
		ll w = wh[i];
		ll pre = 1, po = w - 1;
		while((0 < po) && (po <= n)){
			if(mk[po]) po --, pre ++;
			else break;
		}
		ans = mul(ans, pre);
		pre = 1, po = w + 1;
		while((0 < po) && (po <= n)){
			if(mk[po]) po ++, pre ++;
			else break;
		}
		ans = mul(ans, pre);
		mk[i] = 1;
	}
	cout << ans;*/
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