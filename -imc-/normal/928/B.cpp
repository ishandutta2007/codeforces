#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt(), k = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
	}

	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
		if (a[i] == -1) {
			ans[i] = min(n, i + k + 1) - max(0, i - k);
		} else {
			ans[i] = ans[a[i]] + min(n, i + k + 1) - max(0, i - k) - max(0, min(n, a[i] + k + 1) - max(0, i - k));
		}
	}

	for (int x : ans) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}