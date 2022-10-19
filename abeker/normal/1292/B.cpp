#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

ll x0, y0;
ll ax, ay;
ll bx, by;
ll xs, ys, t;

ll dist(pii p, pii q) {
	return abs(p.first - q.first) + abs(p.second - q.second);
}

ll calc(pii p, pii q, pii r) {
	return dist({xs, ys}, p) + dist(p, q) + dist(q, r);	
}

int get(int x, int y, int z) {
	return max(max(x, y), z) - min(min(x, y), z) + 1;
}

int main() {
	scanf("%lld%lld", &x0, &y0);
	scanf("%lld%lld", &ax, &ay);
	scanf("%lld%lld", &bx, &by);
	scanf("%lld%lld%lld", &xs, &ys, &t);
	
	vector <pii> pts;
	pts.push_back({x0, y0});
	while (pts.back().first < 2e16 && pts.back().second < 2e16)
		pts.push_back({ax * pts.back().first + bx, ay * pts.back().second + by});
		
	int ans = 0;
	int N = pts.size();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				if (calc(pts[i], pts[j], pts[k]) <= t)
					ans = max(ans, get(i, j, k));
	
	printf("%d\n", ans);
	
	return 0;
}