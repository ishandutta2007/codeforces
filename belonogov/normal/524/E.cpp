#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

#define y1 y1111
typedef long long ll;

const int maxn = 1 << 18;

int n, m, k, q;
int x[maxn], y[maxn], x1[maxn], y1[maxn], x2[maxn], y2[maxn];
bool ans[maxn];
int t[maxn];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = 0;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

void upd(int v, int tl, int tr, int x, int y) {
	if (tl == tr) {
		t[v] = max(t[v], y);
		return;
	}
	int tm = (tl + tr) >> 1;
	if (x <= tm) upd(v * 2, tl, tm, x, y);
	else upd(v * 2 + 1, tm + 1, tr, x, y);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
	if (l > r) return 1e9;
	if (l == tl && r == tr) return t[v];
	int tm = (tl + tr) >> 1;
	return min(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
/*#ifndef _ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif*/
	
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 0; i < k; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
	}

	for (int it = 0; it < 2; it++) {
		vector<pair<int, pair<int, int> > > events;
		for (int i = 0; i < k; i++) {
			events.push_back(make_pair(x[i], make_pair(0, i)));
		}
		for (int i = 0; i < q; i++) {
			events.push_back(make_pair(x2[i], make_pair(1, i)));
		}
		sort(events.begin(), events.end());

		build(1, 1, m);
		for (int i = 0; i < (int)events.size(); i++) {
			int id = events[i].second.second;
			if (events[i].second.first == 0) {
				upd(1, 1, m, y[id], x[id]);
			} 
			if (events[i].second.first == 1) {
				int o = get(1, 1, m, y1[id], y2[id]);
				if (o >= x1[id]) {
					ans[id] = 1;
				}
			}
		}

		swap(n, m);
		for (int i = 0; i < k; i++) {
			swap(x[i], y[i]);
		}
		for (int i = 0; i < q; i++) {
			swap(x1[i], y1[i]);
			swap(x2[i], y2[i]);
		}
	}
	for (int i = 0; i < q; i++) {
		if (ans[i]) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}