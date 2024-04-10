#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	if (n == 2)
		cout << 1 << '\n';
	else if (n == 4)
		cout << 3 << '\n';
	else {
		n /= 2;
		int ans = 1;
		for (int i = 0; i < n; i++) {
			ans = (ans * (2 * n - i)) / (i + 1);
		}
		ans /= 2;
		for (int i = 1; i < n; i++) {
			ans = ans * i * i;
		}
		cout << ans << '\n';
	}

	return 0;
}