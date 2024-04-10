#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1026;
const int mod = 998244353;

long double dp[2][26*maxn];
long double eps = 2e-7;

int main(){
	ios_base::sync_with_stdio(false);
	int k, q;
	cin >> k >> q;
	dp[0][0] = 1;
	for (int j = 1; j <= k; j++){
		int p = j&1;
		for (int i = 1; i <= 26000; i++)
			dp[p][i] = dp[p][i-1] * j/k + dp[1-p][i-1] * (k-j+1)/k;
		dp[0][0] = 0;
	}
	while (q --){
		long double p;
		cin >> p;
		int ans = -1;
		for (int i = 1; i <= 26000; i++)
			if (dp[k&1][i] >= 1.*(p-eps)/2000){
				ans = i;
				break;
			}
		cout << ans << '\n';
	}
}