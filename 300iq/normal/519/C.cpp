#include <bits/stdc++.h>
#define int long long
#define m_p make_pair
using namespace std;

main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int cur = i;
		int ln = n - i;
		int lm = m - 2 * i;
		if (lm >= 0) {
			cur += min(lm, ln / 2);
			ans = max(ans, cur);
		}
	}
	cout << ans << endl;
}