#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;

int x[MX], y[MX], a[MX], b[MX], n;

void check(int X, int Y) {
	set<pair<int, int>> S;
	for (int i = 0; i < n; i++) S.emplace(a[i], b[i]);
	for (int i = 0; i < n; i++)
		if (S.count(make_pair(X - x[i], Y - y[i])) == 0)
			return;
	
	printf("%d %d\n", X, Y);
	exit(0);
}

int main() {
	ignore = scanf("%d", &n);
	for (int i = 0; i < n; i++) ignore = scanf("%d %d", x + i, y + i);
	for (int i = 0; i < n; i++) ignore = scanf("%d %d", a + i, b + i);
	
	for (int i = 0; i < n; i++) check(x[0] + a[i], y[0] + b[i]);
	
	return 0;
}