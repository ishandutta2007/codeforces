#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e5 + 10;
const ll SQ = 320;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , k , dp[SQ][MAXN] , ans[MAXN] , inv[MAXN];
string s;

void build(){
	fill(ans , ans + MAXN , 0);
	ans[n] = 1; int cur = 1;
	for(int i = n + 1 ; i < MAXN ; i++){
		cur = 25ll * cur * (i - 1) % MOD * inv[i - n] % MOD;
		ans[i] = (26ll * ans[i - 1] + cur) % MOD;
	}	
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	dp[0][0] = 1; inv[1] = 1;
	for(int i = 2 ; i < MAXN ; i++)	inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	for(int i = 1 ; i < MAXN ; i++)	dp[0][i] = 26ll * dp[0][i - 1] % MOD;
	for(int i = 1 ; i < SQ ; i++){
		for(int j = 1 ; j < MAXN ; j++){
			dp[i][j] = (25ll * dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
		}
	}
	cin >> q >> s; n = SZ(s);
	if(n >= SQ)	build();
	while(q--){
		int t , k;
		cin >> t;
		if(t == 1){
			cin >> s; n = SZ(s);
			if(n >= SQ)	build();
		}
		if(t == 2){
			cin >> k;
			if(n < SQ)	cout << dp[n][k] << endl;
			else	cout << ans[k] << endl;
		}
	}

    return 0;
}
/*

*/