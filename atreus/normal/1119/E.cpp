#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 3e5 + 10;

ll a[maxn], dp[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++){
		if (dp[i - 1] * 2 <= a[i]){
			a[i] -= 2 * dp[i - 1];
			dp[i] = a[i] % 3;
			continue;
		}
		dp[i] = dp[i - 1] - (a[i] / 2) + (a[i] & 1);
	}
	cout << (sum - dp[n]) / 3 << endl;
}