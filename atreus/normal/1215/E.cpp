#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 4e5 + 10;

int a[maxn];
ll inv[21][21];
ll cost[20][(1 << 20) + 5], dp[(1 << 20) + 5];

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		a[i] --;
	}
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			if (i == j)
				continue;
			int now = 0;
			for (int x = 0; x < n; x++){
				if (a[x] == i)
					inv[i][j] += now;
				if (a[x] == j)
					now ++;
			}
		}
	}
	for (int i = 0; i < 20; i++){
		for (int mask = 1; mask < (1 << 20); mask++){
			int k = log2(mask & -mask);
			cost[i][mask] = cost[i][mask - (1 << k)] + inv[i][k];
		}
	}
	memset(dp, 63, sizeof dp);
	dp[0] = 0;
	for (int mask = 1; mask < (1 << 20); mask++){
		for (int i = 0; i < 20; i++){
			if (mask & (1 << i)){
				ll notmask = (((1 << 20) - 1) ^ mask);
				dp[mask] = min(dp[mask], dp[mask - (1 << i)] + cost[i][notmask]);
			}
		}
	}
	cout << dp[(1 << 20) - 1] << endl;
}