#include <bits/stdc++.h>
using namespace std;
struct Point {
	long long x, y;
	Point(long long _x = 0, long long _y = 0): x(_x), y(_y) {}
};
Point operator + (const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}
Point operator - (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}
Point operator * (const Point &a, const long long &b) {
    return Point(a.x * b, a.y * b);
}
long long dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
long long cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
#define area(p) (((p).y == 0 && (p).x < 0) || (p).y > 0)
bool cmp_angle(const Point &a, const Point &b) {
    if (area(a) != area(b)) return area(a) < area(b);
    return cross(a, b) > 0;
}
#undef area
int n;
Point P[5005];
Point vec[5005];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &P[i].x, &P[i].y);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if (j != i)
				vec[++cnt] = P[j] - P[i];
		sort(vec + 1, vec + 1 + cnt, cmp_angle);
		for (int j = cnt + 1; j <= 2 * cnt; j++)
			vec[j] = vec[j - cnt];
		long long cur = 0;
		for (int j = 1, k = 1; j <= cnt; j++) {
			if (k < j + 1)
				k = j + 1;
			while (k <= 2 * cnt && cross(vec[j], vec[k]) > 0) k++;
			cur += 1ll * (k - j - 1) * (k - j - 2) / 2;
		}
		ans += 1ll * (n - 1) * (n - 2) * (n - 3) / 6 - cur;
	}
	ans = ans * (n - 4)/ 2;
	cout << ans;
	return 0;
}