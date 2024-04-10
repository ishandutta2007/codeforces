#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int maxn = 1e6 + 42;

int cnt[maxn];

int dp[maxn][7][7];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		//cerr << cnt[i] << ' ';
		for(int z1 = 0; z1 <= 6 && z1 <= (i > 1 ? cnt[i - 2] : 0); z1++) {
			for(int z2 = 0; z2 <= 6 && z2 <= cnt[i - 1]; z2++) {
				for(int z3 = 0; z3 <= 6 && z3 <= cnt[i]; z3++) {
					int has = dp[i - 1][z1][z2] + (cnt[i] - z3) / 3;
					dp[i][z2][z3] = max(dp[i][z2][z3], has);
					ans = max(ans, dp[i][z2][z3]);
					if(z1 >= 1 && z2 >= 1 && z3 >= 1) {
						dp[i][z2 - 1][z3 - 1] = max(dp[i][z2 - 1][z3 - 1], has + 1);
						ans = max(ans, dp[i][z2 - 1][z3 - 1]);
					}
					if(z1 >= 2 && z2 >= 2 && z3 >= 2) {
						dp[i][z2 - 2][z3 - 2] = max(dp[i][z2 - 2][z3 - 2], has + 2);
						ans = max(ans, dp[i][z2 - 2][z3 - 2]);
					}
				}
			}
		}
	}
	//cerr << endl;
	cout << ans << endl;
    return 0;
}