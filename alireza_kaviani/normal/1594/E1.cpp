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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll poww(ll x , ll y){
	ll ans = 1;
	for( ; y ; y >>= 1 , x = x * x % MOD)	if(y & 1){
		//cout << x << sep << y << endl;
		ans = ans * x % MOD;
	}
	return ans;
}

ll k;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> k;
	ll ans = poww(4 , (1ll << k) - 2);
	cout << ans * 6 % MOD << endl;

    return 0;
}
/*

*/