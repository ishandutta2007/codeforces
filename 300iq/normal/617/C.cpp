#include <bits/stdc++.h>
#define int long long
using namespace std;

int sqr(int a) {
	return a * a;
}

main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	vector <pair <int, int> > g(n);
	for (int i = 0; i < n; i++) {
		cin >> g[i].first >> g[i].second;
	}
	int r1 = 0, r2 = 0;
	int ans = 8e18;
	vector <int> k1, k2;
	for (int i = 0; i < n; i++) {
		r1 = sqr(g[i].first - x1) + sqr(g[i].second - y1);
		r2 = 0;
		for (int j = 0; j < n; j++) {
			int p1 = sqr(g[j].first - x1) + sqr(g[j].second - y1);
			int p2 = sqr(g[j].first - x2) + sqr(g[j].second - y2);
			if (r1 < p1) {
				r2 = max(r2, p2);
			}
		}
		ans = min(ans, r1 + r2);	
	}
	r1 = 0;
	r2 = 0;
	for (int j = 0; j < n; j++) {
		int p1 = sqr(g[j].first - x1) + sqr(g[j].second - y1);
		int p2 = sqr(g[j].first - x2) + sqr(g[j].second - y2);
		if (r1 < p1) {
			r2 = max(r2, p2);
		}
	}
	ans = min(ans, r1 + r2);

	cout << ans << endl;
}