#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxT = 2501;
const int MxN = 51;
const int mod = (int) 1e9 + 7;

vector<int> a[3];
ll dp1[MxN + 2][MxT + 2];
ll dp2[MxN + 2][MxN + 2][MxT + 2];
ll dp3[MxN + 2][MxN + 2][MxN + 2][3];

ll f3(const int i, const int j, const int k) {
	return i + j + k <= 1 ? 1 : accumulate(dp3[i][j][k], dp3[i][j][k] + 3, 0LL) % mod;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	for (int i = 0; i <= MxN; ++i)
		for (int j = 0; i + j <= MxN; ++j)
			for (int k = 0; i + j + k <= MxN; ++k) {
				for (int g = 0; g < 3; ++g) {
					ll &res = dp3[i][j][k][g];
					if (g == 0) {
						if (!i)
							continue;
						if (i + j + k <= 1)
							res = 1;
						else
							res = 1LL * i * (dp3[i - 1][j][k][1] + dp3[i - 1][j][k][2]) % mod;
					} else if (g == 1) {
						if (!j)
							continue;
						if (i + j + k <= 1)
							res = 1;
						else
							res = 1LL * j * (dp3[i][j - 1][k][0] + dp3[i][j - 1][k][2]) % mod;
					} else if (g == 2) {
						if (!k)
							continue;
						if (i + j + k <= 1)
							res = 1;
						else
							res = 1LL * k * (dp3[i][j][k - 1][0] + dp3[i][j][k - 1][1]) % mod;
					} else
						assert(false);
				}
			}

	int N, T;
	cin >> N >> T;
	for (int i = 0; i < N; ++i) {
		int t, g;
		cin >> t >> g;
		a[g - 1].push_back(t);
	}

	dp1[0][0] = dp2[0][0][0] = 1;
	for (const int x : a[0]) {
		for (int i = MxN; i >= 1; --i)
			for (int t = T; t >= x; --t)
				(dp1[i][t] += dp1[i - 1][t - x]) %= mod;
	}

	for (const int x : a[1])
		for (int i = MxN; i >= 1; --i)
			for (int j = MxN; j >= 0; --j)
				for (int t = T; t >= x; --t)
					(dp2[i][j][t] += dp2[i - 1][j][t - x]) %= mod;
	for (const int x : a[2]) // change
		for (int i = MxN; i >= 0; --i) // change
			for (int j = MxN; j >= 1; --j) // change
				for (int t = T; t >= x; --t)
					(dp2[i][j][t] += dp2[i][j - 1][t - x]) %= mod; // change

	DBG(dp1[2][2])
	DBG(dp2[0][1][1])

	ll ans = 0;
	for (int i = 0; i <= (int) a[0].size(); ++i)
		for (int j = 0; j <= (int) a[1].size(); ++j)
			for (int k = 0; k <= (int) a[2].size(); ++k) {
				ll cnt = 0;
				for (int t = 0; t <= T; ++t)
					(cnt += dp1[i][t] * dp2[j][k][T - t]) %= mod;

				ans += f3(i, j, k) * cnt;
				ans %= mod;
			}
	cout << ans;
	return 0;
}