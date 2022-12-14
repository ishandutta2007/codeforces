#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
const int maxn = 3e5 + 10;
const int mod = 1e9 + 7;

ll dp[maxn];
int cnt[maxn];

ll power(ll a, ll b){
	if (b == 0)
		return 1;
	ll ret = power(a, b / 2);
	if (b & 1)
		return ret * ret % mod * a % mod;
	return ret * ret % mod;
}

ll Choose(int r, int n){
	if (r > n)
		return 0;
	ll ret = 1;
	for (int i = n; i > n - r; i--)
		ret = ret * i % mod;
	for (int i = 1; i <= r; i++)
		ret = ret * power(i, mod - 2) % mod;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	int max_number = 0;
	for (int i = 1; i <= n; i++){
		int a;
		cin >> a;
		max_number = max(max_number, a);
		cnt[a] ++;
	}
	for (int i = 1; i <= max_number; i++){
		for (int j = i + i; j <= max_number; j += i){
			cnt[i] += cnt[j];
		}
	}
	for (int i = 1; i <= 10; i++){
		memset(dp, 0, sizeof dp);
		for (int j = max_number; j >= 1; j--){
			dp[j] = Choose(i, cnt[j]);
			for (int k = j + j; k <= max_number; k += j){
				dp[j] = (dp[j] - dp[k] + mod) % mod;
			}
		}
		if (dp[1] != 0){
			return cout << i << endl, 0;
		}
	}
	cout << -1 << endl;
}