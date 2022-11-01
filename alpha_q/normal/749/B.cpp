#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> point;

#define x first
#define y second

int x[5], y[5];
set <point> s;

int main (int argc, char const *argv[]) {
	for (int i = 0; i < 3; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < 3; ++i) {
		int j = (i + 1) % 3;
		int k = (i + 2) % 3;
		s.insert(make_pair(x[i] + x[j] - x[k], y[i] + y[j] - y[k]));
	}
	printf("%d\n", (int) s.size());
	for (point p : s) {
		printf("%d %d\n", p.x, p.y);
	}
    return 0;
}