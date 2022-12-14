/**
 *    author:  Atreus
 *    created: 18.01.2019 17:05:25
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2000 + 10;

int n, k;
int a[maxn], dp[maxn];

bool check(int x){
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= n; i++){
		if (abs(a[i] - a[i - 1]) <= x)
			dp[i] = dp[i - 1];
		else
			dp[i] = i - 1;

		for (int j = i - 1; j >= 1; j--){
			if (abs(a[i] - a[j]) <= 1ll * (i - j) * x){
				dp[i] = min(dp[i], dp[j] + (i - j - 1));
			}
		}
	}
	int ret = n;
	for (int i = 1; i <= n; i++)
		ret = min(ret, dp[i] + (n - i));
	return ret <= k;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll lo = -1, hi = 2 * 1000 * 1000 * 1000;
	while (hi - lo > 1){
		ll mid = (lo + hi) >> 1;
		if (check(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << endl;
}