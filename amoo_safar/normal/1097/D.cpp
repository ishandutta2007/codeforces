#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 2e5 + 10;
const ll INF = (ll) 2242545357980376863;
const ld EPS = (ld) 1e-8;

const ll LOG = 60;
const ll K = 10010;
ll INV[LOG];

ll pw(ll b, ll p){
	if(p == 0) return 1;
	b %= MOD;
	if(p % 2 == 1) return (b * pw(b, p - 1)) % MOD;
	return pw(b * b, p / 2);
}

ll inv(ll x){
	return INV[x];
}

ll dp[K][LOG];
ll ps[LOG + 10];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i = 0;i < LOG; i++) INV[i] = pw(i, MOD - 2);
	/*C[0][0] = 1;
	for(int i = 1;i<LOG;i++){
		C[i][0] = 1;
		for(int j = 1; j <LOG; j++){
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			C[i][j] %= MOD;
		}
	}
	dp[0][0] = 1;
	for(int i =1;i < K; i++){
		ps[0] = 0;
		for(int j = 1;j<=LOG;j++)ps[j] = ps[j - 1] + dp[i-1][j-1];
		for(int j = 0;j<LOG;j++){
			dp[i][j] = ps[j + 1];
			dp[i][j] %= MOD;
		}
	}*/
		
	ll n, k;
	cin >> n >> k;
	//n = 1000000000000000ll;
	//k = 10000;
	ll d = 2;
	ll ans = 1;
	ll cnt;
	ll all, nw;
	while(d * d <= n){
		cnt = 0;
		while(n % d == 0){
			n/=d;
			cnt ++;
		}
		if(cnt == 0) {
			d++;
			continue;
		}
		debug(d);
		memset(dp, 0, sizeof dp);
		dp[0][cnt] = 1;
		//debug(inv(cnt));
		for(int i = 0;i<k;i++){
			for(int j = 0; j < LOG; j++){
				ll xx = (dp[i][j] * inv(j + 1));
				xx %= MOD;
				//if(xx!=0) debug(xx);
				for(int l = 0;l <= j;l++){
					dp[i+1][l] += xx;
					dp[i+1][l] %= MOD;
				}
			}
		}
		//debug(inv(4));
		//debug(dp[k][1]); debug(dp[k][0]);
		nw = 0;
		ll s = 0;
		for(int i = 0; i <= cnt; i++){
			nw = nw + ( pw(d, i) * (dp[k][i])  ); 
			nw %= MOD;
		}
		//debug(d);
		//debug(nw);
		ans *= nw;
		//debug(ans);
		ans %= MOD;
		d++;
	}
	if(n != 1){
		d = n;
		cnt = 1;
		
		memset(dp, 0, sizeof dp);
		dp[0][cnt] = 1;
		//debug(inv(cnt));
		for(int i = 0;i<k;i++){
			for(int j = 0; j < LOG; j++){
				ll xx = (dp[i][j] * inv(j + 1));
				xx %= MOD;
				//if(xx!=0) debug(xx);
				for(int l = 0;l <= j;l++){
					dp[i+1][l] += xx;
					dp[i+1][l] %= MOD;
				}
			}
		}
		//debug(inv(4));
		//debug(dp[k][1]); debug(dp[k][0]);
		nw = 0;
		ll s = 0;
		for(int i = 0; i <= cnt; i++){
			nw = nw + ( pw(d, i) * (dp[k][i])  ); 
			nw %= MOD;
		}
		//debug(d);
		//debug(nw);
		ans *= nw;
		//debug(ans);
		ans %= MOD;
	}
	
	cout << (((ans%MOD)+MOD)%MOD);
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