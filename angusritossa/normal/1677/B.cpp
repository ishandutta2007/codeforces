#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 1000010
int n, m;
int cols[MAXN];
int rangetree[MAXN*4];
vector<int> changes;
void update(int s, int e, int curr = 1, int cstart = 0, int cend = MAXN) {
	if (s <= cstart && cend <= e) {
		changes.push_back(curr);
		rangetree[curr]++;
		return;
	}
	int mid = (cstart+cend)/2;
	if (e <= mid) update(s, e, 2*curr, cstart, mid);
	else if (s > mid) update(s, e, 2*curr+1, mid+1, cend);
	else {
		update(s, e, 2*curr, cstart, mid);
		update(s, e, 2*curr+1, mid+1, cend);
	}
}
int query(int node, int curr = 1, int cstart = 0, int cend = MAXN) {
	if (cstart == cend) {
		return rangetree[curr];
	}
	int mid = (cstart+cend)/2;
	if (node <= mid) return query(node, 2*curr, cstart, mid) + rangetree[curr];
	else return query(node, 2*curr+1, mid+1, cend) + rangetree[curr];
}

int main() {
	int t;
	scanf("%d", &t);
	for (int CASE = 0; CASE < t; CASE++) {
		scanf("%d%d", &n, &m);
		fill_n(cols, m, 0);
		int numCols = 0;
		int pre = -1e6;
		for (int i = 0; i < n*m; i++) {
			char c;
			scanf(" %c", &c);
			if (c == '1') {
				if (!cols[i%m]) {
					cols[i%m] = 1;
					numCols++;
				}

				if (i-pre >= m) {
					update(0, m-1);
				} else {
					int am = i-pre;
					int s = pre%m;
					int e = pre+am-1;
					e %= m;
					if (s <= e) update(s, e);
					else {
						update(s, m-1);
						update(0, e);
					}
				}
				pre = i;
			}
			int ans = query(i%m) + numCols;
			printf("%d ", ans);
		}
		printf("\n");
		for (auto a : changes) rangetree[a] = 0;
		changes.clear();
	}
}