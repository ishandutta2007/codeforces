#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 1e5 + 9;
const int MxI = 60;
ll a[MxN + 9];
int dp[2][MxN + 9];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		a[i] = a[n-1] - a[i];

	for (int i = MxI; i >= 0; --i) {
		sort(a, a + n, [&i](const ll x, const ll y) {
			const ll mask = (1LL << i) - 1;
			return (x&mask) < (y&mask);
		});

		array<ll, 3> cnt;
		cnt.fill(0);
		for (int j = 0; j < n; ++j)
			++cnt[a[j] & (1LL << i) ? 1 : 0];

		for (int j = 0; j <= n; ++j) {
			int &res = dp[i & 1][j];
			if (i == MxI)
				res = j;
			else {
				const int cost1 = cnt[1];
				const int cost2 = cnt[0] + cnt[2];
				const int res1 = cost1 + dp[~i & 1][cnt[2]];
				const int res2 = cost2 + dp[~i & 1][cnt[1] + cnt[2]];
				res = min(res1, res2);
			}

			if (j < n) {
				--cnt[a[n - 1 - j] & (1LL << i) ? 1 : 0];
				++cnt[a[n - 1 - j] & (1LL << i) ? 2 : 1];
				for (int x : cnt)
					assert(x >= 0);
			}
		}
	}

	cout << dp[0][0];

	return 0;
}