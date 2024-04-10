#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct Point {
	long long x, y;
	int id, c;
	inline Point(long long _x = 0, long long _y = 0): x(_x), y(_y) {}
	inline bool operator < (const Point &oth) const { return x < oth.x || (x == oth.x && y < oth.y); }
	inline Point operator + (const Point &oth) const { return Point(x + oth.x, y + oth.y); }
	inline Point operator - (const Point &oth) const { return Point(x - oth.x, y - oth.y); }
	inline Point operator * (const long long &oth) const { return Point(x * oth, y * oth); }
};
inline long long dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
inline long long cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
inline bool intri(const Point &a, const Point &b, const Point &c, const Point &p) {
	return abs(cross(a - p, b - p)) + abs(cross(b - p, c - p)) + abs(cross(c - p, a - p)) == abs(cross(b - a, c - a));
}
int n, m;
bool used[N];
Point a[N], b[N];
vector<pair<int, int> > ans;
inline void Sp(const Point &a, const Point &b, const Point &c, vector<Point> &buck, vector<Point> &ret) {
	vector<Point> rem;
	ret.clear();
	for (const auto &p : buck) {
		if (intri(a, b, c, p)) ret.push_back(p);
		else rem.push_back(p);
	}
	buck.swap(rem);
}
void Solve(const Point &a, const Point &b, const Point &c, vector<Point> buck) {
	if (buck.size() == 0) return;
	bool vis[2];
	memset(vis, 0, sizeof(vis));
	for (const auto &p : buck) vis[p.c] = 1;
	if (!vis[c.c]) {
		for (const auto &p : buck) ans.emplace_back(a.id, p.id);
		return;
	}
	if (!vis[a.c]) {
		for (const auto &p : buck) ans.emplace_back(c.id, p.id);
		return;
	}
	Point p;
	for (int i = 0; i < (int)buck.size(); i++) if (c.c == buck[i].c) {
		p = buck[i];
		buck.erase(buck.begin() + i);
		break;
	}
	ans.emplace_back(c.id, p.id);
	vector<Point> cur;
	Sp(a, b, p, buck, cur);
	Solve(a, b, p, cur);
	Sp(p, c, a, buck, cur);
	Solve(p, c, a, cur);
	Solve(p, c, b, buck);
}
int main() {
	scanf("%d", &n);
	bool vis[2];
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%d", &a[i].x, &a[i].y, &a[i].c);
		vis[a[i].c] = 1;
		a[i].id = i;
	}
	if (!vis[0] || !vis[1]) {
		printf("%d\n", n - 1);
		for (int i = 1; i < n; i++) printf("%d %d\n", 0, i);
		return 0;
	}
	sort(a + 1, a + 1 + n);
	m = 0;
	for (int i = 1; i <= n; i++) {
		while (m > 1 && cross(b[m] - b[m - 1], a[i] - b[m]) <= 0) m--;
		b[++m] = a[i];
	}
	int lim = m;
	for (int i = n - 1; i >= 1; i--) {
		while (m > lim && cross(b[m] - b[m - 1], a[i] - b[m]) <= 0) m--;
		b[++m] = a[i];
	}
	m--;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= m; i++) vis[b[i].c] = used[b[i].id] = 1;
	if (!vis[0] || !vis[1]) {
		for (int i = 1; i < m; i++) ans.emplace_back(b[i].id, b[i + 1].id);
		int st;
		for (st = 1; st <= n; st++) if (!vis[a[st].c]) break;
		used[a[st].id] = 1;
		vector<Point> buck, cur;
		for (int i = 1; i <= n; i++) if (!used[a[i].id]) buck.push_back(a[i]);
		for (int i = 1; i <= m; i++) {
			Sp(b[i], b[i + 1], a[st], buck, cur);
			Solve(b[i], b[i + 1], a[st], cur);
		}
	} else {
		vector<int> vc;
		for (int i = 1; i <= m; i++) if (b[i].c != b[i + 1].c) vc.push_back(i);
		if (vc.size() > 2) {
			puts("Impossible");
			return 0;
		}
		if (b[vc[0] + 1].c) swap(vc[0], vc[1]);
		vector<Point> vp[2], buck, cur;
		for (int i = 1; i <= n; i++) if (!used[a[i].id]) buck.push_back(a[i]);
		for (int i = vc[0] % m + 1; b[i].c == 0; i = i % m + 1) vp[0].push_back(b[i]);
		for (int i = vc[1] % m + 1; b[i].c == 1; i = i % m + 1) vp[1].push_back(b[i]);
		for (int i = 1; i < (int)vp[0].size(); i++) {
			ans.emplace_back(vp[0][i - 1].id, vp[0][i].id);
			Sp(vp[0][i - 1], vp[0][i], vp[1][0], buck, cur);
			Solve(vp[0][i - 1], vp[0][i], vp[1][0], cur);
		}
		for (int i = 1; i < (int)vp[1].size(); i++) {
			ans.emplace_back(vp[1][i - 1].id, vp[1][i].id);
			Sp(vp[1][i - 1], vp[1][i], vp[0][0], buck, cur);
			Solve(vp[1][i - 1], vp[1][i], vp[0][0], cur);
		}
	}
	printf("%d\n", (int)ans.size());
	for (auto &P : ans) printf("%d %d\n", P.first - 1, P.second - 1);
	return 0;
}