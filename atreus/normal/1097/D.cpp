#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxk = 1e4 + 100;
const int mod = 1e9 + 7;

int dp[51][51][maxk], par[51][51][maxk];

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a, b / 2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		ret = 1ll * ret * a % mod;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	for (int i = 1; i <= 50; i++){
		for (int j = 1; j <= i; j++){
			if (i == j){
				dp[i][j][0] = 1;
			}
			par[i][j][0] = par[i - 1][j][0] + dp[i][j][0];
		}
	}
	for (int i = 1; i <= 50; i++){
		ll pw = power(i, mod - 2);
		for (int j = 1; j <= i; j++){
			for (int x = 1; x <= k; x++){
				dp[i][j][x] = 1ll * (par[i][j][x - 1] - par[j - 1][j][x - 1] + mod) * pw % mod;
				par[i][j][x] = 1ll * (dp[i][j][x] + par[i - 1][j][x]) % mod;
			}
		}
	}
	int answer = 1;
	for (ll i = 2; i * i <= n; i++){
		if (n % i == 0){
			int cnt = 0;
			ll p = i;
			while (n % i == 0){
				cnt ++;
				n /= i;
			}
			cnt ++;
			int tmp = 0, pw = 1;
			for (int j = 1; j <= cnt; j++){
				tmp = 1ll * (tmp + 1ll * dp[cnt][j][k] * pw) % mod;
				pw = 1ll * pw * i % mod;
			}
			answer = 1ll * answer * tmp % mod;
		}
	}
	if (n != 1){
		int cnt = 2;
		int tmp = 0, pw = 1;
		for (int i = 1; i <= cnt; i++){
			tmp = 1ll * (tmp + 1ll * dp[cnt][i][k] * pw) % mod;
			pw = 1ll * pw * n % mod;
		}
		answer = 1ll * answer * tmp % mod;
	}
	cout << answer << endl;
}