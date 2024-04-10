#include <bits/stdc++.h>
using std::vector;
const int N = 1005;
int T, n, a[N], b[N], c[N];
vector<int> ans;
int find() {
	for (int i = 0; i <= n; i++) b[i] = 0;
	for (int i = 0; i < n; i++) b[a[i]] = 1;
	for (int i = 0; i <= n; i++)
		if (!b[i]) return i;
	return -1;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i <= n; i++) c[i] = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]), c[a[i]]++;
		ans.clear();
		for (int i = 0; i < n; i++)
			if (c[a[i]] > 1)
				ans.push_back(i), c[a[i]]--, a[i] = find();
		int tmp = find();
		do {
			int ok = 1;
			for (int i = 1; i < n; i++)
				if (a[i] <= a[i - 1]) { ok = 0; break; }
			if (ok) break;
			if (tmp == n) {
				for (int i = 0; i < n; i++)
					if (a[i] != i) { ans.push_back(i), std::swap(a[i], tmp); break; }
			} else
				ans.push_back(tmp), std::swap(a[tmp], tmp);
		} while (1);
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i] + 1);
		putchar('\n');
	}
	return 0;
}