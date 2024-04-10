#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

typedef class Point {
	public:
		int x, y;

		Point(double x = 0.0, double y = 0.0) : x(x), y(y) {	}

		void read() {
			scanf("%d%d", &x, &y);
		}
} Point;

#define ll long long

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

double cross(Point a, Point b) {
	return 1.0 * a.x * b.y - 1.0 * a.y * b.x;
}
ll intpoints(Point a, Point b) {
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	(dx < 0) && (dx = -dx);
	(dy < 0) && (dy = -dy);
	return gcd(dx, dy);
}

int n;
Point ps[N];
double pw2[N], _pw2[N], Pall;

double get_probablity(int K) {
	if (n <= 100) {
		return (pw2[n - K - 1] - 1) / Pall;
	}
	return _pw2[K + 1];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ps[i].read();
	}
	pw2[0] = 1, _pw2[0] = 1;
	for (int i = 1; i <= n; i++) {
		pw2[i] = pw2[i - 1] + pw2[i - 1];
		_pw2[i] = _pw2[i - 1] * 0.5;
	}
	if (n <= 100) {
		Pall = pw2[n] - 1 - n - 0.5 * n * (n - 1);
	}
	double ES = 0.0;
	for (int i = 0; i < n; i++) {
		for (int k = 1; k < n && k <= 40; k++) {
			int j = (i + k) % n;
			ES += get_probablity(k) * cross(ps[i], ps[j]);
		}
	}
	ES /= 2;
	double Es = 0.0;
	for (int i = 0; i < n; i++) {
		for (int k = 1; k < n && k <= 40; k++) {
			int j = (i + k) % n;
			Es += get_probablity(k) * intpoints(ps[i], ps[j]);

		}
	}
	double E = ES - Es * 0.5 + 1;
	printf("%.9lf", E);
	return 0;
}