#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	if (n > m) {
		swap(n, m);
	}
	int ans = (n * m + 1) / 2;
	if (n == 1) {
		ans = max(ans, n * m);
	}
	if (n == 2) {
		ans = max(ans, m / 4 * 4 + min(m % 4, 2) * 2);
	}
	cout << ans << endl;
    return 0;
}