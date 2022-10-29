#include <bits/stdc++.h>
#ifndef local
#define Auto "%I64d"
#else
#define Auto "%lld"
#endif
using namespace std;
typedef bool boolean;

const int N = 2e3 + 3;

#define ll long long

typedef class Point {
	public:
		ll x, y;

		Point(ll x = 0, ll y = 0) : x(x), y(y) {	}

		void read() {
			scanf(Auto""Auto, &x, &y);
		}
} Point;

Point operator - (Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y);
}

ll cross(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}

int n;
char s[N];
Point P[N];
boolean used[N];

int get_L(int id) {
	int rt = -1;
	for (int i = 1; i <= n; i++) {
		if (used[i]) continue;
		if (rt == -1) {
			rt = i;
		} else if (cross(P[rt] - P[id], P[i] - P[id]) > 0) {
			rt = i;
		}
	}
	printf("%d ", rt);
	used[rt] = true;
	return rt;
}
int get_R(int id) {
	int rt = -1;
	for (int i = 1; i <= n; i++) {
		if (used[i]) continue;
		if (rt == -1) {
			rt = i;
		} else if (cross(P[rt] - P[id], P[i] - P[id]) < 0) {
			rt = i;
		}
	}
	printf("%d ", rt);
	used[rt] = true;
	return rt;
}

int main() {
	scanf("%d", &n);
	int cur = 1;
	for (int i = 1; i <= n; i++) {
		P[i].read();
	}
	for (int i = 2; i <= n; i++) {
		if (P[i].x < P[cur].x || (P[i].x == P[cur].x && P[i].y < P[cur].y)) {
			cur = i;
		}
	} 
	scanf("%s", s + 1);
	used[cur] = true;
	printf("%d ", cur);
	for (int i = 1; i <= n - 2; i++) {
		if (s[i] == 'L') {
			cur = get_R(cur);
		} else {
			cur = get_L(cur);
		}
	}
	get_R(cur);
	return 0;
}