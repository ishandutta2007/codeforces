#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 200 * 1000 + 5, M = 22;

int cnt[M];

int get(int x, int y) {
	return (x >> y) & 1;
}

int main() {
	ios :: sync_with_stdio(false);
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < M; j++) {
			if (get(x, j)) {
				cnt[j]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		long long x = 0;
		for (int j = 0; j < M; j++) {
			if (cnt[j] >= i) {
				x += (1 << j);
			}
		}
		ans += 1ll * x * x;
	}
	cout << ans;
	return 0;
}