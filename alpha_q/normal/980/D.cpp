#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
const int S = 100000000;
const int M = 200000005;

bitset <N> vis;
vector <int> pr;
bitset <M> who;
int n, a[N], ans[N];

int main() {
	for (int i = 2; i * i < N; ++i) {
		if (vis[i]) continue;
		for (int j = i * i; j < N; j += i) {
			vis[j] = 1;
		}
	}
	for (int i = 2; i < N; ++i) {
		if (vis[i]) continue;
		pr.push_back(i);
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x, _x, y = 1;
		scanf("%d", &_x);
		if (_x == 0) {
			a[i] = 0;
			continue;
		}
		x = abs(_x);
		for (int p : pr) {
			if (p * p > x) break;
			int e = 0;
			while (x % p == 0) {
				e ^= 1, x /= p;
			}
			if (e) y *= p;
		}
		if (x > 1) y *= x;
		if (_x > 0) {
			a[i] = y;
		}	else {
			a[i] = -y;
		}
	}
	for (int i = 1; i <= n; ++i) {
		int tot = 0;
		// cout << a[i] << endl;
		for (int j = i; j <= n; ++j) {
			if (a[j] < 0) {
				if (!who[S - a[j]]) {
					who[S - a[j]] = 1, ++tot;
				}
			} else if (a[j] > 0) {
				if (!who[a[j]]) {
					who[a[j]] = 1, ++tot;
				}
			}
			++ans[max(1, tot)];
		}
		for (int j = i; j <= n; ++j) {
			if (a[j] == 0) continue;
			if (a[j] < 0) {
				who[S - a[j]] = 0;
			} else {
				who[a[j]] = 0;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");
  return 0;
}