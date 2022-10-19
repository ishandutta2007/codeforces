#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
#define x first
#define y second

pii p[5];
set <pii> ans;

void load() {
	for (int i = 0; i < 3; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
}

void add_hor(int x1, int x2, int y) {
	if (x1 > x2)
		swap(x1, x2);
	for (int i = x1; i <= x2; i++)
		ans.insert({i, y});
}

void add_ver(int y1, int y2, int x) {
	if (y1 > y2)
		swap(y1, y2);
	for (int i = y1; i <= y2; i++)
		ans.insert({x, i});
}

void solve() {
	sort(p, p + 3);
	
	add_hor(p[0].x, p[1].x, p[0].y);
	add_ver(p[0].y, p[1].y, p[1].x);
	add_ver(p[1].y, p[2].y, p[1].x);
	add_hor(p[1].x, p[2].x, p[2].y);
	
	printf("%d\n", ans.size());
	for (auto it : ans)
		printf("%d %d\n", it.first, it.second);
}

int main() {
	load();
	solve();
	return 0;
}