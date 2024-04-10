#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;

int cnt(unsigned long long l) {
	int ans = 0;
	while (l > 0) {
		if (l % 2 == 1) {
			ans++;
		}
		l /= 2;
	}
	return ans;
}

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	long long n, p;
	cin >> n >> p;
	for (int k = 0; k < 63; k++) {
		long long res = n - k * p;
		if (res <= 0) {
			continue;
		}
		if (k >= cnt(res) && k <= res) {
			cout << k;
			return 0;
		}
	}
	cout << -1;
	return 0;
}