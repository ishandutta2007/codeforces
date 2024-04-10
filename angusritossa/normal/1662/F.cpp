#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
struct Node {
	int left, right;
	pair<int, int> mn, mx;
};
Node rangetree[MAXN*4];
int upto = 1;
void update(int node, int mn, int mx, int curr = 1, int cstart = 0, int cend = MAXN) {
	if (cstart == cend) {
		rangetree[curr].mn = { mn, node };
		rangetree[curr].mx = { mx, node };
		return;
	}
	int mid = (cstart+cend)/2;
	if (node <= mid) {
		if (!rangetree[curr].left) {
			rangetree[curr].left = ++upto;
			rangetree[rangetree[curr].left] = rangetree[0];
		}
		update(node, mn, mx, rangetree[curr].left, cstart, mid);
	} else {
		if (!rangetree[curr].right) {
			rangetree[curr].right = ++upto;
			rangetree[rangetree[curr].right] = rangetree[0];
		}
		update(node, mn, mx, rangetree[curr].right, mid+1, cend);
	}
	rangetree[curr].mx = max(rangetree[rangetree[curr].left].mx, rangetree[rangetree[curr].right].mx);
	rangetree[curr].mn = min(rangetree[rangetree[curr].left].mn, rangetree[rangetree[curr].right].mn);
}
pair<pair<int, int>, pair<int, int> > query(int s, int e, int curr = 1, int cstart = 0, int cend = MAXN) {
	if (s <= cstart && cend <= e) {
		return {rangetree[curr].mn, rangetree[curr].mx};
	}
	int mid = (cstart+cend)/2;
	if (e <= mid) {
		return query(s, e, rangetree[curr].left, cstart, mid);
	} else if (s > mid) {
		return query(s, e, rangetree[curr].right, mid+1, cend);
	} else {
		auto val1 = query(s, e, rangetree[curr].left, cstart, mid);
		auto val2 = query(s, e, rangetree[curr].right, mid+1, cend);
		return { min(val1.first, val2.first), max(val1.second, val2.second) };
	}
}
int p[MAXN], dis[MAXN];
int main() {
	rangetree[0].mn.first = 1e9;
	rangetree[0].mx.first = -1e9;
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		upto = 1;
		rangetree[1] = rangetree[0];
		fill_n(dis, MAXN, 1e9);
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		a--;
		b--;
		for (int i = 0; i < n; i++) {
			scanf("%d", &p[i]);
			update(i, i-p[i], i+p[i]);
		}
		update(a, 1e9, -1e9);
		dis[a] = 0;
		queue<int> q;
		q.push(a);
		while (q.size()) {
			int i = q.front();
			q.pop();
			D("%d: %d p[i]: %d\n", i, dis[i], p[i]);
			while (1) {
				auto res = query(max(0, i-p[i]), i).second;
				if (res.first >= i) {
					q.push(res.second);
					dis[res.second] = dis[i]+1;
					update(res.second, 1e9, -1e9);
				} else {
					break;
				}
			}
			while (1) {
				auto res = query(i, min(n-1, i+p[i])).first;
				if (res.first <= i) {
					q.push(res.second);
					dis[res.second] = dis[i]+1;
					update(res.second, 1e9, -1e9);
				} else {
					break;
				}
			}
		}
		printf("%d\n", dis[b]);
	}
}