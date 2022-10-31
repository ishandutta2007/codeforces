#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int X;
	cin >> X;
	while (X--) {
		int N, T, A, B;
		cin >> N >> T >> A >> B;
		vector<pair<int, int> > t(N);
		int E = 0;
		int H = 0;
		for (int i = 0; i < N; i++) {
			cin >> t[i].second;
			if (t[i].second == 0)
				E++;
			else
				H++;
		}
		for (int i = 0; i < N; i++) {
			cin >> t[i].first;
		}
		sort(t.begin(), t.end());
		t.emplace_back(T + 1, 3);
		int tot = 0;
		int res = 0;
		for (int i = -1; i < N; i++) {
			if (i >= 0) {
				if (t[i].second == 0) {
					tot += A;
					E--;
				} else {
					tot += B;
					H--;
				}
			}
			if (i == -1 || i == N - 1 || t[i].first < t[i + 1].first) {
				int ti = t[i + 1].first - 1;
				if (tot <= ti) {
					int rest = ti - tot;
					int ans = i + 1;
					int a = min(E, rest / A);
					ans += a;
					rest -= A * a;
					a = min(H, rest / B);
					ans += a;
					res = max(res, ans);
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}