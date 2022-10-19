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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , s , ans , A[MAXN] , inv[MAXN];

ll Calc(ll S , ll n){
	if(S < n)	return 0;
	//cout << S << sep << n << endl;
	S--; n--; ll res = 1;
	for(int i = 0 ; i < n ; i++){
		res = res * ((S - i) % MOD) % MOD * inv[i + 1] % MOD;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	inv[0] = inv[1] = 1;
	for(int i = 2 ; i < MAXN ; i++){
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	}

	cin >> n >> s;
	for(int i = 0 ; i < n ; i++)	cin >> A[i];
	for(int i = 0 ; i < (1 << n) ; i++){
		ll S = s + n;
		for(int j = 0 ; j < n ; j++){
			if(i & (1 << j)){
				S -= A[j] + 1;
			}
		}
		//cout << Calc(S , n) << endl;
		if(__builtin_popcount(i) % 2 == 0){
			ans += Calc(S , n);
		}
		else{
			ans -= Calc(S , n);
		}
	}
	ans = (ans % MOD + MOD) % MOD;
	cout << ans << endl;

	return 0;
}
/*

*/