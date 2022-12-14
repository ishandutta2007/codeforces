#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll maxn = 2e5 + 10;
const ll mod = 1e9 + 7;

ll dp[40][40];

int main(){
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t --){
		ll d, m;
		cin >> d >> m;
		ll answer = 0;
		for (ll i = 0; i <= 29; i++){
			dp[1][i] = min((1ll << i), d - (1ll << i) + 1) % m;
			if (dp[1][i] < 0)
				dp[1][i] = 0;
			answer = (answer + dp[1][i]) % m;
		}
		for (ll i = 2; i <= 30; i++){
			for (ll j = i - 1; j <= 29; j++){
				dp[i][j] = 0;
				ll t = min((1ll << j), d - (1ll << j) + 1);
				if (t < 0)
					continue;
				for (ll k = 0; k < j; k++)
					dp[i][j] = (dp[i][j] + 1ll * dp[i-1][k] * t % m) % m;
				answer = (answer + dp[i][j]) % m;
			}
		}
		cout << answer << '\n';
	}
}