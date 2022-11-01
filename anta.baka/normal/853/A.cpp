#include <bits/stdc++.h>

using namespace std;

int t[4 * 600000];

void build(int v, int l, int r) {
	if(l == r) {
		t[v] = 1;
		return;
	}
	int m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m + 1, r);
	t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

void upd(int v, int l, int r, int pos) {
	if(pos < l || r < pos) return;
	if(l == r) {
		t[v] = 0;
		return;
	}
	int m = (l + r) / 2;
	upd(v * 2 + 1, l, m, pos);
	upd(v * 2 + 2, m + 1, r, pos);
	t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

int sum(int v, int l, int r, int l1, int r1) {
	if(r < l1 || r1 < l) return 0;
	if(l1 <= l && r <= r1) return t[v];
	int m = (l + r) / 2;
	return sum(v * 2 + 1, l, m, l1, r1) + sum(v * 2 + 2, m + 1, r, l1, r1);
}

int kth(int v, int l, int r, int k) {
	if(l == r) return l;
	int m = (l + r) / 2;
	if(t[v * 2 + 1] >= k) return kth(v * 2 + 1, l, m, k);
	return kth(v * 2 + 2, m + 1, r, k - t[v * 2 + 1]);
}

pair<int, int> a[300000];
int n, k, ans[300000];
long long ians;

main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	build(0, 0, n + k - 1);
	for(int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
	sort(a, a + n, [](pair<int, int> a, pair<int, int> b){ return a.first > b.first || a.first == b.first && a.second < b.second; });
	for(int i = 0; i < n; i++) {
		int idx = a[i].second;
		int l = max(k, idx);
		int s = (l != 0 ? sum(0, 0, n + k - 1, 0, l - 1) : 0);
		ans[idx] = kth(0, 0, n + k - 1, s + 1);
		ians += 1LL * (ans[idx] - idx) * a[i].first;
		upd(0, 0, k + n - 1, ans[idx]);
	}
	cout << ians << '\n';
	for(int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
}