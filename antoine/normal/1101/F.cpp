#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Truck {
	int s, f, c;
};

int n, m;
const int MaxN = 409;
int a[MaxN + 9];
vector<Truck> trucks[MaxN + 9];
int dp[MaxN + 1][MaxN + 1][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 0; i < m; ++i) {
		int s, f, c, r;
		cin >> s >> f >> c >> r;
		trucks[r].push_back( { s, f, c });
	}

	ll ans = 0;

	for (int r = 0; r <= n; ++r) {
		for (int i = n; i >= 1; --i)
			for (int j = n; j >= 1; --j) {
				int &res = dp[i][j][r & 1] = a[j] - a[i];
				if (r != 0) {
					int lo = i;
					int hi = j - 1;
					while (lo < hi) {
						int mid = (lo + hi + 1) >> 1;
						if (a[mid] - a[i] < dp[mid][j][~r & 1])
							lo = mid;
						else
							hi = mid - 1;
					}
					for (const int k : { lo, lo + 1 })
						res = min(res, max(a[k] - a[i], dp[k][j][~r & 1]));
				}
			}

		for (const Truck &t : trucks[r])
			ans = max(ans, 1LL * dp[t.s][t.f][r & 1] * t.c);
	}

	cout << ans << '\n';

	return 0;
}