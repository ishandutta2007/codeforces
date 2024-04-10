#include <bits/stdc++.h>

using namespace std;

int n, m, a[200005];

long long sum = 0;

bool cmp(int x, int y) {
	return x > y;
}

bool check(int k) {
	long long res = 0;
	for (int i = 0; i < k; i++) {
		for (int j = i; j < n; j += k) {
			res += max(0, a[j] - j / k);
		}
	}
	return (res >= m);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum < m) {
		return cout << -1, 0;
	}
	sort(a, a + n, cmp);
	int l = 1, r = n;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	for (int i = l; i <= r; i++) {
		if (check(i)) {
			return cout << i, 0;
		}
	}
	return 0;
}