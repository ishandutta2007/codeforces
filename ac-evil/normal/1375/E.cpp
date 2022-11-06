#include <bits/stdc++.h>
using std::vector;
const int N = 1005;
int n, a[N], b[N][N], c[N];
struct Node { int x, y; };
vector<Node> ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), c[i] = a[i];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			b[i][j] = a[i] > a[j];
	for (int i = n; i; i--) {
		vector<int> tmp;
		for (int j = 1; j < i; j++)
			if (b[j][i]) tmp.push_back(j);
		std::sort(tmp.begin(), tmp.end(), [&](int x, int y){ return c[x] != c[y] ? c[x] < c[y] : x < y; });
		for (int j = 0; j < tmp.size(); j++)
			ans.push_back({tmp[j], i}), std::swap(a[tmp[j]], a[i]);
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].x, ans[i].y);
	return 0;
}