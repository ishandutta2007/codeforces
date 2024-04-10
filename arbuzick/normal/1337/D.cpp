#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int nr, ng, nb;
		cin >> nr >> ng >> nb;
		vector<int> r(nr), g(ng), b(nb);
		for (int j = 0; j < nr; ++j)
			cin >> r[j];
		for (int j = 0; j < ng; ++j)
			cin >> g[j];
		for (int j = 0; j < nb; ++j)
			cin >> b[j];
		sort(r.begin(), r.end());
		sort(g.begin(), g.end());
		sort(b.begin(), b.end());
		int indr = 0, indg = 0, indb = 0;
		int ans = 1e18 * 18;
		ans = min(ans, (r[indr] - g[indg]) * (r[indr] - g[indg]) + (b[indb] - g[indg]) * (b[indb] - g[indg]) + (r[indr] - b[indb]) * (r[indr] - b[indb]));
		while (true) {
			int ans1 = 1e18 * 18, ans2 = 1e18 * 18, ans3 = 1e18 * 18;
			if (indr + 1 < nr) {
				ans1 = (r[indr + 1] - g[indg]) * (r[indr + 1] - g[indg]) + (b[indb] - g[indg]) * (b[indb] - g[indg]) + (r[indr + 1] - b[indb]) * (r[indr + 1] - b[indb]);
			}
			if (indg + 1 < ng) {
				ans2 = (r[indr] - g[indg + 1]) * (r[indr] - g[indg + 1]) + (b[indb] - g[indg + 1]) * (b[indb] - g[indg + 1]) + (r[indr] - b[indb]) * (r[indr] - b[indb]);
			}
			if (indb + 1 < nb) {
				ans3 = (r[indr] - g[indg]) * (r[indr] - g[indg]) + (b[indb + 1] - g[indg]) * (b[indb + 1] - g[indg]) + (r[indr] - b[indb + 1]) * (r[indr] - b[indb + 1]);
			}
			if (ans1 <= ans2 && ans1 <= ans3&&indr + 1 < nr) {
				indr += 1;
				ans = min(ans, ans1);
			}
			else if (ans2 <= ans1 && ans2 <= ans3&&indg + 1 < ng) {
				indg += 1;
				ans = min(ans, ans2);
			}
			else if (indb + 1 < nb) {
				indb += 1;
				ans = min(ans, ans3);
			}
			else {
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}