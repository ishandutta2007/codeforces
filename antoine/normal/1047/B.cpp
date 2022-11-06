#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		int x, y;
		cin >> x >> y;
		ans = max(ans, x+  y);
	}
	cout << ans;;
	return 0;
}