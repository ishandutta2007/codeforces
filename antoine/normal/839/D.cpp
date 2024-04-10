#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1000000007;
const int MaxN = 200000 + 9;
const int MaxV = 1000000 + 9;

ll pre[MaxN + 1];
ll occ[MaxV + 1];
ll dp[MaxV + 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++occ[x];
	}

	for (int i = 1; i <= n; ++i) {
		static ll p2_im1 = 1;
		pre[i] = (p2_im1 * i) % mod;
		p2_im1 = (p2_im1 * 2LL) % mod;
	}

	ll ans = 0;
	for (int i = MaxV; i > 1; --i) {
		int cnt = 0;
		for (int j = i; j <= MaxV; j += i)
			cnt += occ[j];

		dp[i] = pre[cnt];
		for (int j = i + i; j <= MaxV; j += i)
			(dp[i] -= dp[j]) %= mod;

		(ans += dp[i] * i) %= mod;
	}

	ans = ((ans % mod) + mod) % mod;
	cout << ans;
	return 0;
}