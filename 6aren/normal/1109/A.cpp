#include <bits/stdc++.h>

using namespace std;

int n, pref = 0, cnt[2][1500000];

long long res = 0;

int main() {
	cin >> n;
	cnt[0][0]++;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		pref ^= u;
		cnt[i % 2][pref]++;
	}
	for (int i = 0; i < 1500000; i++) {
		for (int j = 0; j < 2; j++) {
			res += 1LL * (cnt[j][i] - 1) * cnt[j][i] / 2;
		}
	}
	cout << res << endl;
	return 0;
}