#include<bits/stdc++.h>
using namespace std;
struct point {
	double x, y;
	point(double a=0, double b=0):x(a), y(b){}
};
point operator+(point a, point b) {
	return point(a.x+b.x, a.y+b.y);
}
point operator-(point a, point b) {
	return point(a.x-b.x, a.y-b.y);
}
point operator*(point a, double k) {
	return point(a.x*k, a.y*k);
}
point operator/(point a, double k) {
	return point(a.x/k, a.y/k);
}
double dis(point x) {
	return sqrt(x.x*x.x+x.y*x.y);
}
double cross(point a, point b) {
	return a.x*b.y-a.y*b.x;
}
bool operator<(point a, point b) {
	if (fabs(b.y) < 1e-10 && b.x < 0) return 0;
	if (fabs(a.y) < 1e-10 && a.x < 0) return 1;
	if (a.y * b.y < 0) return a.y < b.y;
	return cross(a, b) > 0;
}
bool operator==(point a, point b) {
	return fabs(dis(a-b)) < 1e-10;
}
point cut(point a, point b, double k) {
	return point(a.x*(1-k)+b.x*k, a.y*(1-k)+b.y*k);
}
struct line {
	point a, dir;
	line(point x=point(), point y=point()):a(x), dir(y){}
}l[50001];
double dis(line l, point a) {
	return cross(l.dir, a-l.a)/dis(l.dir);
}
point intersect(line l1, line l2) {
	double d1 = dis(l1, l2.a), d2 = dis(l1, l2.a+l2.dir);
	return cut(l2.a, l2.a+l2.dir, d1/(d1-d2));
}
int n;
struct info {
	point p1, p2;
}i0[50001];
point a0[100001];
bool operator<(const info &a, const info &b) {
	if (a.p1 == b.p1) return a.p2 < b.p2;
	return a.p1 < b.p1;
}
double st[50001];
int c[100001];
void modify(int x) {
	for (; x <= n * 2; x += x & -x) ++c[x];
}
int query(int x) {
	int ans = 0;
	for (; x; x -= x & -x) ans += c[x];
	return ans;
}
int cnt, tot;
long long check(double d) {
	cnt = 0, tot = 0;
	for (int i = 1; i <= n; i++)
		if (fabs(dis(l[i], point(0,0))) <= d) {
			point p = intersect(l[i], line(point(0,0), point(-l[i].dir.y, l[i].dir.x)));
			if (dis(p) > d) break;
			double d0 = sqrt(d*d-dis(p)*dis(p));
			point tmp = l[i].dir/dis(l[i].dir)*d0;
			point p1 = p+tmp, p2 = p-tmp;
			if (p2 < p1) swap(p1, p2);
			++cnt, i0[cnt].p1 = p1, i0[cnt].p2 = p2;
			a0[++tot] = p1, a0[++tot] = p2;
		}
	sort(i0 + 1, i0 + cnt + 1);
	sort(a0 + 1, a0 + tot + 1);
	tot = unique(a0 + 1, a0 + tot + 1) - a0 - 1;
	long long ans = 0;
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= cnt; i++) {
		int n1 = lower_bound(a0 + 1, a0 + tot + 1, i0[i].p1) - a0;
		int n2 = lower_bound(a0 + 1, a0 + tot + 1, i0[i].p2) - a0;
		ans += query(n2) - query(n1-1);
		modify(n2);
	}
	return ans;
}
int main() {
	cin >> n;
	double x, y;
	int m;
	cin >> x >> y >> m;
	x /= 1000, y /= 1000;
	for (int i = 1; i <= n; i++) {
		double a, b;
		cin >> a >> b;
		a /= 1000, b /= 1000;
		b += a*x-y;
		l[i] = line(point(0, b), point(1, a));
	}
	double l = 0, r = 1e12;
	for (int i = 0; i <= 100; i++) {
		double mid = (l + r) / 2;
		if (check(mid) < m) l = mid;
		else r = mid;
	}
	check(l);
	set<pair<point, point> > s0;
	double ans = 0;
	for (int i = 1; i <= cnt; i++) {
		while (s0.size() && s0.begin()->first < i0[i].p1) s0.erase(s0.begin());
		for (auto j : s0) {
			if (i0[i].p2 < j.first) break;
			--m;
			point p1 = i0[i].p1, p2 = i0[i].p2;
			point p3 = j.second, p4 = j.first;
			if (p1 == p2) ans += dis(p1);
			else if (p3 == p4) ans += dis(p3);
			else {
				point p0 =intersect(line(p1,p2-p1), line(p3,p4-p3));
				ans += dis(p0);
			}
		}
		s0.insert(make_pair(i0[i].p2, i0[i].p1));
	}
	ans += l*m;
	cout << fixed << setprecision(9) << ans << endl;
}