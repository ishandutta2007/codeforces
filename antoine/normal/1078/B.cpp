#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = (int)1e9 + 7;
const int MaxS = (int) 1e4 + 4;
ll dp[MaxS + 9][109];
ll C[109][109];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for(int i = 0; i <= 100; ++i){
		C[i][0] = C[i][i] = 1;
		for(int j = i - 1; j > 0; --j)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}

	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> occ;
	for (auto &&x : a) {
		cin >> x;
		++occ[x];
	}

	dp[0][0] = 1;
	for (const int &x : a)
		for (int s = MaxS; s >= x; --s)
			for (int k = n; k >= 1; --k)
				(dp[s][k] += dp[s - x][k - 1]) %= mod;

	int ans = 0;

if(occ.size() == 2)
ans = n;

	for (const pair<int, int> &p : occ) {
		for (int c = 1; c <= p.second; ++c) {
			const int sum = p.first * c;
			ll diff = dp[sum][c] - C[p.second][c];
			if(diff%mod == 0)
				ans = max(ans, c);
		}
	}
	cout << ans;
	return 0;
}