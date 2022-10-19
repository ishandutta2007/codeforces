#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 3e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

ll poww(ll x , ll y){
	ll ans = 1;
	for(; y; y >>= 1 , x = x * x % MOD){
		if(y & 1){
			ans = ans * x % MOD;
		}
	}
	return ans;
}

ll n , ans , bad = 1 , cntb , cntw , flag1 = 1 , flag2 = 1 , fact[MAXN] , inv[MAXN];
string s[MAXN];

ll C(ll n , ll r){
	if(r > n || r < 0)	return 0;
	return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	fact[0] = 1;
	for(int i = 1 ; i < MAXN ; i++)	fact[i] = fact[i - 1] * i % MOD;
	inv[MAXN - 1] = poww(fact[MAXN - 1] , MOD - 2);
	for(int i = MAXN - 2 ; i >= 0 ; i--)	inv[i] = inv[i + 1] * (i + 1) % MOD;
		
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> s[i];
		for(int j = 0 ; j < 2 ; j++){
			if(s[i][j] == 'W')	cntw++;
			if(s[i][j] == 'B')	cntb++;
		}
	}
	if(cntw > n || cntb > n){
		return cout << 0 << endl , 0;
	}
	ans = C(2 * n - cntw - cntb , n - cntw);
	for(int i = 0 ; i < n ; i++){
		if(s[i] == "??"){
			bad = bad * 2 % MOD;
		}
		else if(s[i][0] == s[i][1]){
			bad = 0;
		}
		if(s[i][0] == 'B' || s[i][1] == 'W')	flag1 = 0;
		if(s[i][0] == 'W' || s[i][1] == 'B')	flag2 = 0;
	}
	if(bad == 0){
		cout << ans << endl;
		return 0;
	}
	bad = (bad + MOD - flag1 - flag2) % MOD;
	ans = (ans + MOD - bad) % MOD;
	cout << ans << endl;

    return 0;
}
/*

*/