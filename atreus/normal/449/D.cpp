#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 5e6 + 10;

int n, f[maxn], dp[maxn][3], a[maxn];
int maxA;

void find_fs () {
	for (int i = 1; i <= n; i++)
		dp[a[i]][0] ++;
	for (int k = 1; k <= 20; k++){
		bool p = k % 2;
		for (int j = 0; j <= maxA; j++){
			if (j & (1 << (k - 1)))
				dp[j][p] = dp[j][1 - p];
			else
				dp[j][p] = dp[j][1 - p] + dp[j + (1 << (k - 1))][1 - p];
		}
	}
	for (int i = 0; i <= maxA; i++)
		f[i] = dp[i][0];
}

ll pw[maxn];

bool cntmod2(int mask) {
	int cnt = 0;
	while (mask) {
		mask -= mask & -mask;
		cnt ++;
	}
	return cnt & 1;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxA = max (maxA, a[i]);
	}
	find_fs();
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		pw[i] = pw[i - 1] * 2 % mod;
	
	ll ans = 0;
	
	for (int i = 0; i < (1 << 20); i++) {
		if (cntmod2(i))
			ans -= pw[f[i]];
		else
			ans += pw[f[i]];

		if (ans >= mod)
			ans -= mod;
		if (ans < 0)
			ans += mod;
	}
	cout << ans << endl;
}