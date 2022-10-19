#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, k, A, B, a[N];

int cntInside(int l, int r) {
	return (upper_bound(a + 1, a + k + 1, r) - lower_bound(a + 1, a + k + 1, l));
}

long long calc(int l, int r) {
	int mid = (l + r) / 2;
	int cnt = cntInside(l, r);
	if (cnt == 0) return A;
	else {
		if (l == r) return B * cnt;
		return min(1LL * B * cnt * (r - l + 1), calc(l, mid) + calc(mid + 1, r));
	}
}

int main() {
	cin >> n >> k >> A >> B;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + k + 1);
	int o = 1;
	for (int i = 1; i <= n; i++) {
		o *= 2;
	}
	cout << calc(1, o);
	return 0;
}