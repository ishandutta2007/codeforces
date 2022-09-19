// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 40;

ll mul(ll a, ll b){
	a %= Mod; b %= Mod;
	return (a * b) % Mod;
}

ll dp[Log][Log][2];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll k;
	cin >> k;
	k ++;

	int fl = 0;
	for(int i = Log - 1; i >= 0; i--){
		if(fl){
			dp[0][i][1] = 1;
		} else if(k >> i & 1){
			fl = 1;
			dp[0][i][0] = 1;
		}
	}
	for(int i = 0; i < Log - 1; i++){
		for(int j = Log - 1; j > 0; j--){
			for(int b = 0; b < 2; b ++){
				int bt = k >> (j - 1) & 1;
				// Right Down
				if(b == 1 || bt == 1){
					(dp[i + 1][j - 1][b] += mul(dp[i][j][b], 1)) %= Mod;
				}
				// Right
				for(int nb = 0; nb < 2; nb ++){
					if(b == 0 && nb > bt) continue;
					(dp[i][j - 1][b | (nb < bt)] += mul(dp[i][j][b], 1ll << i) ) %= Mod;
				}
			}
		}
	}
	ll ans = 1;
	for(int i = 0; i < Log; i++) ans += dp[i][0][1];
	cout << ans % Mod << '\n';
	return 0;
}