#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

pair<int, int> a[(int) 1e5 + 2];
int dp[(int) 1e5 + 2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	memset(dp, -1, sizeof dp);

	sort(a, a + n);
	for (int i = n - 1; i >= 0; --i) {
		int &res = dp[a[i].second] = 0;

		for(int j = a[i].second % a[i].first; j <= n; j += a[i].first) {

			if(dp[j] == 0 && j != a[i].second) {
				res = 1;
				break;
			}
		}
	}

	for(int i = 1; i <= n; ++i)
		cout << (dp[i] ? 'A' : 'B');
	return 0;
}