#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int, int> > vp;
	if (N == 1) {
		vp.emplace_back(0, 0);
		vp.emplace_back(1, 0);
		vp.emplace_back(2, 0);
		vp.emplace_back(0, 1);
		vp.emplace_back(0, 2);
		vp.emplace_back(2, 1);
		vp.emplace_back(1, 2);
		vp.emplace_back(2, 2);
		vp.emplace_back(2, 3);
		vp.emplace_back(2, 4);
		vp.emplace_back(3, 2);
		vp.emplace_back(4, 2);
		vp.emplace_back(4, 3);
		vp.emplace_back(3, 4);
		vp.emplace_back(4, 4);
	} else {
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < 5; k++) {
				vp.emplace_back(2 * i + 2, k);
			}
		}

		for (int i = 0; i < N - 1; i++) {
			if (i % 2 == 0) {
				vp.emplace_back(2 * i + 3, 0);
				vp.emplace_back(2 * i + 3, 4);
			}
			vp.emplace_back(2 * i + 3, 2);
		}
		if (N % 2 == 0) {
			vp.emplace_back(1, 2);
			for (int k = 0; k < 5; k++) {
				vp.emplace_back(0, 2 + k);
			}
			vp.emplace_back(2 * N + 1, 2);
			for (int k = 0; k < 5; k++) {
				vp.emplace_back(2 * N + 2, 2 + k);
			}
			for (int k = 1; k <= 2 * N + 1; k++) {
				vp.emplace_back(k, 6);
			}
		} else {
			vp.emplace_back(1, 2);
			for (int k = 0; k < 5; k++) {
				vp.emplace_back(0, 2 + k);
			}
			for (int k = 1; k <= 2 * N; k++) {
				vp.emplace_back(k, 6);
			}
			vp.emplace_back(2 * N, 5);
			vp.emplace_back(2 * N + 1, 0);
			vp.emplace_back(2 * N + 2, 0);
			vp.emplace_back(2 * N + 1, 2);
			vp.emplace_back(2 * N + 2, 2);
			vp.emplace_back(2 * N + 2, 1);
		}
	}
	cout << vp.size() << endl;
	for (int i = 0; i < vp.size(); i++) {
		cout << vp[i].first << " " << vp[i].second << endl;
	}
	return 0;
}