#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 3;

bool dp[30][(1 << 14)][30];
int cnt[(1 << 14)], deg[(1 << 14)];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a;
	int c = 0;
	bool fail = 0;
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if (x == 2)
			fail = 1;
		if (x == 1)
			c ++;
		else
			a.push_back(x);
	}
	if (n == 1){
		if (c == 1)
			return cout << "YES\n", 0;
		return cout << "NO\n", 0;
	}
	sort(a.begin(), a.end());
	if (c < (n + 1) / 2 or fail)
		return cout << "NO\n", 0;
	int m = n - c;
	for (int mask = 0; mask < (1 << m); mask++){
		for (int i = 0; i < m; i++){
			if (mask & (1 << i)){
				deg[mask] = deg[mask ^ (1 << i)] + a[i];
				cnt[mask] = cnt[mask ^ (1 << i)] + 1;
			}
		}
	}
	dp[0][0][c] = 1;
	for (int i = 0; i < m; i++){
		for (int mask = 0; mask < (1 << i); mask++){
			for (int j = 0; j <= c; j++){
				if (dp[i][mask][j] == 0)
					continue;
				for (int submask = mask; submask; submask = (submask - 1) & mask){
					if (deg[submask] > a[i] - 1 or deg[submask] + j < a[i] - 1)
						continue;
					int t = a[i] - 1 - deg[submask];
					if (cnt[submask] + t > 1)
						dp[i + 1][(mask ^ submask) | (1 << i)][j - t] = 1;
				}
				if (j >= a[i] - 1)
					dp[i + 1][mask | (1 << i)][j - a[i] + 1] = 1;
			}
		}
	}
	cout << (dp[m][(1 << (m - 1))][0] == 1 ? "YES\n" : "NO\n");
}