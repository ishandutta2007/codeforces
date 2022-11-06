#include <bits/stdc++.h>
typedef long long ll;
const int N = 8e5 + 5;
int n;
struct point { int x, y; } a[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		a[i] = {x + y, x - y};
	}
	std::sort(a + 1, a + n + 1, [](point a, point b) { return a.x < b.x; });
	std::priority_queue<int> pa, pb;
	ll ans = 0; pa.push(0), pb.push(0);
	for (int i = 1; i <= n; i++) {
		ll x = a[i].x, y = a[i].y;
		ans += std::max({pa.top() - x - y, y + pb.top() - x, 0ll});
		if (-pb.top() > y - x)
			pa.push(y + x), pa.push(y + x), pb.push(-(pa.top() - 2 * x)), pa.pop();
		else
			pb.push(-(y - x)), pb.push(-(y - x)), pa.push(-pb.top() + 2 * x), pb.pop();
	}
	ans /= 2;
	printf("%lld\n", ans);
	return 0;
}