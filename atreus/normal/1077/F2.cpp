#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 5e3 + 10;
ll dp[maxn][maxn], a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n, k, x;
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	memset (dp, -1, sizeof dp);
	dp[0][0] = 0;
	deque <int> deq;
	for (int j = 1; j <= x; j++) {
		if (j == 1) {
			deq.push_back (0);
		}
		for (int i = 1; i <= n; i++) {
			while (!deq.empty() and i - deq.front() > k) {
				deq.pop_front();
			}
			if (!deq.empty())
				dp[j][i] = dp[j - 1][deq.front()] + a[i];
			if (dp[j - 1][i] != -1) {
				while (!deq.empty() and dp[j - 1][deq.back()] <= dp[j - 1][i]) {
					deq.pop_back();
				}
				deq.push_back (i);
			}
//			cout << j << " " << i << " -> " << dp[j][i] << endl;
		}

		while (!deq.empty()) {
			deq.pop_front();
		}
	}
	ll ans = -1;
	for (int i = 1; i <= n; i++)
		if (n - i + 1 <= k)
			ans = max (ans, dp[x][i]);
	cout << ans << endl;
}