#include <bits/stdc++.h>
#define bit(n, k) ((n >> k) & 1)
typedef long long ll;
using namespace std;

const int maxn = 1e6 + 10;
const ll inf = 1e18;

int a[maxn];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int k = 0;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		k = gcd(k, x);
	}
	ll answer = -inf;
	for (int W = 0; W < 2; W++) {
		ll sum = 0;
		for (int i = 1; i <= k; i++) {
			int mnm = 1e9 + 1, cnt = 0;
			for (int j = i; j <= n; j += k) {
				if (a[j] < 0)
					cnt ^= 1;
				mnm = min(mnm, abs(a[j]));
				sum += abs(a[j]);
			}
			if (cnt)
				sum -= 2LL * mnm;
		}
		answer = max(answer, sum);

		for (int j = 1; j <= k; j++)
			a[j] *= -1;
	}
	cout << answer << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
	}
}