#include<bits/stdc++.h>

using namespace std;

const int N = 300005;

int n, m, a[N], b[N];

int calc(int x, int y, int z) {
	if (x + z >= m) {
		int t = (x + z) % m;
		if (t >= y) return y;
		return max(x, y);
	}
	int t = x + z;
	if (t >= y) return max(y, x);
	return -1;
}

bool check(int k) {
	for (int i = 1; i <= n; i++) {
		b[i] = calc(a[i], b[i - 1], k);
		if (b[i] == -1) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int l = 0, r = m - 1;
	while (r - l > 1) {
		int mid = (r + l) / 2;
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