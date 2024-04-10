#include<bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, m, a[N], p[N], sum[N];
bool vis[N];

bool check(int w) {
	for (int i = 1; i <= w; i++) a[n - w + i] = p[i];
	for (int i = w + 1; i <= n; i++) a[i - w] = p[i];
	for (int i = 1; i <= n; i++) vis[i] = 0;
	int s = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			s++;
			int x = i;
			while (!vis[x]) vis[x] = 1, x = a[x];
		}
	return n - s <= m;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++) sum[i] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &p[i]);
			int w;
			if (p[i] <= i) w = i - p[i];
			else w = n - p[i] + i;
			sum[w]++;
		}
		vector<int> ans;
		for (int i = 0; i < n; i++)
			if (sum[i] >= n / 3 && check(i)) ans.push_back(i);
		sort(ans.begin(), ans.end());
		printf("%d ", ans.size());
		for (int i : ans) printf("%d ", i);
		puts("");
	}
	return 0;
}