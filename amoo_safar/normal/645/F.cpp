#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e6 + 10;
const ll INF = (ll) LONG_LONG_MAX / 100;
const ld EPS = (ld) 1e-8;
const ll P = 104107;

ll mul(ll a, ll b){
	return (a * b) % MOD;
}
ll mod(ll x){
	return ((x % MOD) + MOD) % MOD;
}
ll pw(ll b, ll p){
	if(p == 0) return 1;
	if(p & 1) return mul(b, pw(b, p - 1));
	return pw(mul(b, b), p / 2);
}
ll inv(ll x){
	return pw(x, MOD - 2);
}

ll sd[MAXN];
ll C[MAXN];
ll cnt[MAXN];
ll f[MAXN], in[MAXN];
vector<ll> D[MAXN];

ll ans = 0, k;


ll nCr(ll n, ll r){
	if(r > n) return 0;
	return mul(mul(in[r], in[n - r]), f[n]);
}

ll calc(ll x){
	return mul(C[x], nCr(cnt[x], k));
}

void change(ll i, ll del){
	ans -= calc(i);
	cnt[i] ++;
	ans += calc(i);
	ans = mod(ans);
}

void add(ll x){
	for(auto d : D[x]){
		change(d, 1);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	in[0] = 1;
	for(int i = 1; i < MAXN; i++) f[i] = mul(f[i - 1], i), in[i] = inv(f[i]);
	for(int i = 1; i < MAXN; i++) C[i] = i;
	for(int i = 1; i < MAXN; i++) for(int j = i + i; j < MAXN; j+=i) C[j] -= C[i];
	for(int i = 1; i < MAXN; i++) for(int j = i; j < MAXN; j+=i) D[j].pb(i);

	//debug(nCr(5,2));
	//debug(f[5]);
	ll n, q;
	cin >> n >> k >> q;
	ll v;
	for(int i = 0; i< n; i++) {
		cin >> v;
		add(v);
		//cout << ans << '\n';
	}
	for(int i = 0; i< q; i++){
		cin >> v;
		add(v);
		cout << ans << '\n';
	}
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