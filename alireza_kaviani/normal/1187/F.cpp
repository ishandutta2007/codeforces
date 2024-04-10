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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll poww(ll x , ll y){
	ll ans = 1;
	for( ; y ; y >>= 1 , x = x * x % MOD)	if(y & 1)	ans = ans * x % MOD;
	return ans;
}

ll n , S1 , S2 , L[MAXN] , R[MAXN] , P[MAXN] , inv[MAXN];

ll common(int x , int y){
	ll l = 0 , r = MOD;
	for(int i = x ; i <= y ; i++){
		l = max(l , L[i]);
		r = min(r , R[i]);
	}
	return max(0ll , r - l + 1);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++)	cin >> L[i];
	for(int i = 1 ; i <= n ; i++)	cin >> R[i];
	for(int i = 1 ; i <= n ; i++){
		inv[i] = poww(R[i] - L[i] + 1 , MOD - 2);
//		cout << i << sep << inv[i] << endl;
	}
	for(int i = 1 ; i < n ; i++){
		P[i] = common(i , i + 1) * inv[i] % MOD * inv[i + 1] % MOD;
		S1 += P[i];
		S2 += P[i];
//		cout << i << sep << P[i] << endl;
	}
	S1 %= MOD;
	S2 %= MOD;
	for(int i = 1 ; i < n ; i++){
		ll cur = (S1 + MOD * 3 - P[i - 1] - P[i] - P[i + 1]) * P[i] % MOD;
		S2 += cur;
		S2 += 2 * common(i , i + 2) * inv[i] % MOD * inv[i + 1] % MOD * inv[i + 2] % MOD;
	}
	S2 %= MOD;
	S1 = (MOD - n - n) * S1 % MOD;
	cout << (n * n + S2 + S1) % MOD << endl;

    return 0;
}
/*

*/