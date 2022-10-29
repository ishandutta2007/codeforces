#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 5e5 + 5;

int n;
int a[N], p[N];
vector<int> G[N];

void solve(int l, int r, int basis) {
	p[r] = basis + r - l + 1;
	int ls = l;
	for (auto p : G[r]) {
		if (p < l) {
			throw 1;
		}
		solve(ls, p, basis + r - p - 1);
		ls = p + 1;
	}
} 

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n + 1; i++) {
		G[i].clear();
		p[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (a[i] == -1) {
			a[i] = i + 1;
		}
		G[a[i]].push_back(i);
	}
	try {
		solve(1, n + 1, 0);
	} catch (int) {
		puts("-1");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!p[i]) {
			puts("-1");
			return;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", p[i]);
	}
	putchar('\n');
}

int T;
int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}