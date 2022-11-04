#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, L[N], R[N], ans[N], vis[N], mp[N], cnt[N];
inline bool check(int mid) {
	for (int i = 1; i <= n; i++) vis[i] = 0, mp[i] = n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cnt[j] = 0;
		for (int j = 1; j <= n; j++) if (!vis[j]) cnt[mp[j]]++;
		for (int j = 2; j <= n; j++) cnt[j] += cnt[j - 1];
		for (int j = 1; j <= n; j++) if (cnt[j] > max(0, j - i + 1)) return false;
		int lim = n;
		for (int j = i; j <= n; j++) if (cnt[j] == j - i + 1) { lim = j; break; }
		int p = 0;
		for (int j = 1; j <= n; j++) if (!vis[j] && mp[j] <= lim) {
			if (!p || R[j] < R[p]) p = j;
		}
		vis[p] = 1;
		ans[i] = p;
		for (int j = 1; j <= n; j++) if (L[j] <= R[p] && L[p] <= R[j]) mp[j] = min(mp[j], i + mid);
	}
	return true;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &L[i], &R[i]);
	int lo = 1, hi = n - 1;
	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		if (check(mid)) hi = mid;
		else lo = mid + 1;
	}
	check(hi);
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}