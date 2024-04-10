#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int p[200005];
ii a[200005];

int find(int x) {
	if (p[x] == x) return x;
	return (p[x] = find(p[x]));
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) p[x] = y;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		a[i].x = 1e9;
		a[i].y = 0;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}
	int cnt = 0;
	set<int> s;
	for (int i = 1; i <= n; i++) {
		int u = find(i);
		a[u].x = min(a[u].x, i);
		a[u].y = max(a[u].y, i);
	}
	int res = 0;
	int nx = 0;
	for (int i = 1; i <= n; i++) {
		if (i <= nx) continue;
		for (int j = i + 1; j <= a[find(i)].y; j++) {
			if (find(j) != find(i)) {
				a[find(i)].y = a[find(j)].y = max(a[find(i)].y, a[find(j)].y);
				merge(i, j);
				res++;
			}
		}
		nx = a[find(i)].y;
	}
	cout << res << endl;
	return 0;
}