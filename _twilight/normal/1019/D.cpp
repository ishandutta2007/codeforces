#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

typedef class Point {
	public:
		int x, y;

		Point(int x = 0.0, int y = 0.0) : x(x), y(y) {	}

		Point normal();
		void normalize();

		void read() {
			scanf("%d%d", &x, &y);
		}
} Point, Vector;

Vector operator + (Vector a, Vector b) {
	return Vector(a.x + b.x, a.y + b.y);
}
Vector operator - (Vector a, Vector b) {
	return Vector(a.x - b.x, a.y - b.y);
}

ll dot(Vector a, Vector b) {
	return 1ll * a.x * b.x + 1ll * a.y * b.y;
}
ll cross(Vector a, Vector b) {
	return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

const int N = 2e3 + 5;

int n;
ll S;
Point Ps[N];

typedef class Event {
	public:
		int u, v;
		double ang;

		Event(int u, int v) : u(u), v(v) {
			Point d = Ps[v] - Ps[u];
			ang = atan2(d.y, d.x);
		}

		boolean operator < (Event e) const {
			return ang < e.ang;
		}
} Event;

vector<Event> E;

void answer(int x, int y, int z) {
	puts("Yes");
	printf("%d %d\n", Ps[x].x, Ps[x].y);
	printf("%d %d\n", Ps[y].x, Ps[y].y);
	printf("%d %d\n", Ps[z].x, Ps[z].y);
	exit(0);
}

int p[N], q[N];
int main() {
	scanf("%d%lld", &n, &S);
	S <<= 1;
	for (int i = 1; i <= n; i++) {
		Ps[i].read();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i ^ j) {
				E.emplace_back(i, j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	sort(p + 1, p + n + 1, [&] (int a, int b) {
				return Ps[a].y > Ps[b].y;
			});
	sort(E.begin(), E.end());
	for (int i = 1; i <= n; i++) {
		q[p[i]] = i;
	}
	for (auto e : E) {
		int u = e.u, v = e.v;
		int l = 1, r = n, mid;
		Point d = Ps[v] - Ps[u];
		while (l <= r) {
			mid = (l + r) >> 1;
			ll area = cross(d, Ps[p[mid]] - Ps[u]);
			if (area == S)
				answer(u, v, p[mid]);
			if (area < S) {
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		swap(q[u], q[v]);
		swap(p[q[u]], p[q[v]]);
	}
	puts("No");
	return 0;
}