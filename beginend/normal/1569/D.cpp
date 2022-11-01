#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200005;
const int MAXL = 1000000;

int n, m, k, scol[MAXL + 5], srow[MAXL + 5], a[N], b[N];
vector<int> ccol, crow;
vector<pair<int, int> > col, row;

LL calc(int x) {
	return (LL)x * (x - 1) / 2;
}

void ins(int *a, int x, int y) {
	while (x <= MAXL) a[x] += y, x += x & (-x);
}

int find(int *a, int x) {
	int res = 0;
	while (x) res += a[x], x -= x & (-x);
	return res;
}

LL solve(vector<pair<int, int> > vec) {
	LL res = 0; int s = 1;
	for (int i = 1; i < vec.size(); i++)
		if (vec[i] == vec[i - 1]) s++;
		else res += calc(s), s = 1;
	res += calc(s);
	return res;
}

void clear() {
	col.clear(); row.clear();
	for (int i = 0; i < crow.size(); i++)
		ins(srow, crow[i], -1);
	for (int i = 0; i < ccol.size(); i++)
		ins(scol, ccol[i], -1);
	crow.clear(); ccol.clear();
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= k; i++) {
			int x, y; scanf("%d%d", &x, &y);
			int u = lower_bound(a + 1, a + n + 1, x) - a;
			int v = lower_bound(b + 1, b + m + 1, y) - b;
			if (u <= n && a[u] == x && v <= m && b[v] == y) continue;
			if (u <= n && a[u] == x) {
				row.push_back(make_pair(u, v));
				ins(srow, y, 1);
				crow.push_back(y);
			}
			if (v <= m && b[v] == y) {
				col.push_back(make_pair(u, v));
				ins(scol, x, 1);
				ccol.push_back(x);
			}
		}
		LL ans = 0;
		for (int i = 1; i < n; i++)
			ans += calc(find(scol, a[i + 1]) - find(scol, a[i]));
		for (int i = 1; i < m; i++)
			ans += calc(find(srow, b[i + 1]) - find(srow, b[i]));
		sort(row.begin(), row.end());
		sort(col.begin(), col.end());
		ans -= solve(row) + solve(col);
		printf("%lld\n", ans);
		clear();
	}
	return 0;
}