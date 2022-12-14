#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> pii;
const int mod = 998244353;

ll power(ll a, ll b){
	if (b == 0)
		return 1;
	ll ret = power(a, b / 2);
	ret = ret * ret % mod;
	if (b & 1)
		ret = ret * a % mod;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = m * power(m - 1, k) % mod;
	for (int i = k + 1; i <= n - 1; i++){
		ans = ans * i % mod;
	}
	for (int i = 1; i <= n - k - 1; i++){
		ans = ans * power(i, mod - 2) % mod;
	}
	cout << ans << endl;
}