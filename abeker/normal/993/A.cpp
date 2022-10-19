#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAX = 400;

pii a[5], b[5];

void norm(pii &p) {
	p.first *= 4;
	p.second *= 4;
}

bool in_range(int val, int lo, int hi) {
	return val >= lo && val <= hi;
}

bool in_first(int x, int y) {
	int x1 = MAX, x2 = -MAX;
	int y1 = MAX, y2 = -MAX;
	for (int i = 0; i < 4; i++) {
		x1 = min(x1, a[i].first);
		x2 = max(x2, a[i].first);
		y1 = min(y1, a[i].second);
		y2 = max(y2, a[i].second);
	}
	return in_range(x, x1, x2) && in_range(y, y1, y2);
}

bool in_second(int x, int y) {
	int x1 = 2 * MAX, x2 = -2 * MAX;
	int y1 = 2 * MAX, y2 = -2 * MAX;
	for (int i = 0; i < 4; i++) {
		x1 = min(x1, b[i].first - b[i].second);
		x2 = max(x2, b[i].first - b[i].second);
		y1 = min(y1, b[i].first + b[i].second);
		y2 = max(y2, b[i].first + b[i].second);
	}
	return in_range(x - y, x1, x2) && in_range(x + y, y1, y2);
}

int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
		norm(a[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d%d", &b[i].first, &b[i].second);
		norm(b[i]);
	}
	
	for (int i = -MAX; i <= MAX; i++)
		for (int j = -MAX; j <= MAX; j++)
			if (in_first(i, j) && in_second(i, j)) {
				puts("yes");
				return 0;
			}
	
	puts("no");
	
	return 0;
}