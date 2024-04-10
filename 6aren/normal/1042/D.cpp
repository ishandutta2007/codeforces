#include <bits/stdc++.h>

using namespace std;

long long n, sum[200005], u, t, ans = 0, le[200005], ri[200005];

void merge(long long *t, int p, int q, int r) {
	for (int i = 0; i < q - p; i++) {
		le[i] = t[i + p];
	}
	for (int i = 0; i < r - q + 1; i++) {
		ri[i] = t[i + q];
	}
	int u = 0, v = 0;
	le[q - p] = 1e15 + 1;
	ri[r - q + 1] = 1e15 + 1;
	for (int i = p; i <= r; i++) {
		if (le[u] <= ri[v]) {
			t[i] = le[u];
			u++;
		} else {
			t[i] = ri[v];
			v++;
		}
	}
	return;
}

long long calc(int l, int r) {
	if (l == r) {
		return 0;
	}
	long long res = 0, mid = (l + r) / 2;
	long long left = calc(l, mid), right = calc(mid + 1, r);
	int u = l, v = mid + 1;
	while (u <= mid && v <= r) {
		if (sum[v] - sum[u] < t) {
			res += mid - u + 1;
			v++; 
		} else {
			u++;
		}
	}
	merge(sum, l, mid + 1, r);
	return res + left + right;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> u;
		sum[i] = sum[i - 1] + u;
		if (sum[i] < t) {
			ans++;
		}
	}
	cout << ans + calc(1, n) << endl;
	return 0;
}