#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, l, r, a[N], cnt[2][N];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &l, &r);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			cnt[0][i] = cnt[1][i] = 0;
		}
		if (l > r) {
			swap(l, r);
			reverse(a + 1, a + 1 + n);
		}
		for (int i = 1; i <= l; i++) cnt[0][a[i]]++;
		for (int i = l + 1; i <= n; i++) cnt[1][a[i]]++;
		set<pair<int, int> > st;
		for (int i = 1; i <= n; i++) if (cnt[1][i]) {
			st.emplace(cnt[0][i] - cnt[1][i], i);
		}
		int tar = (r - l) / 2;
		while (tar--) {
			auto P = *st.begin();
			st.erase(st.begin());
			int i = P.second;
			cnt[0][i]++, cnt[1][i]--;
			if (cnt[1][i]) st.emplace(cnt[0][i] - cnt[1][i], i);
		}
		int ans = r - l;
		for (int i = 1; i <= n; i++) ans += abs(cnt[0][i] - cnt[1][i]);
		ans /= 2;
		printf("%d\n", ans);
	}
	return 0;
}