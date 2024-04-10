#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, a[10], b[N];
pair<int, int> c[N * 6];
map<int, int> mp;
int main() {
	for (int i = 1; i <= 6; i++) scanf("%d", &a[i]);
	scanf("%d", &n);
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		for (int j = 1; j <= 6; j++) c[++tot] = make_pair(b[i] - a[j], i);
	}
	sort(c + 1, c + 1 + tot);
	int ans = 1e9;
	for (int i = 1, j = 1; i <= tot; i++) {
		while (j <= tot && (int)mp.size() < n) {
			mp[c[j].second]++;
			j++;
		}
		if ((int)mp.size() < n) break;
		ans = min(ans, c[j - 1].first - c[i].first);
		mp[c[i].second]--;
		if (!mp[c[i].second]) mp.erase(c[i].second);
	}
	printf("%d\n", ans);
	return 0;
}