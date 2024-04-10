#include<bits/stdc++.h>
using namespace std;

int query(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

int main() {
	int L = 1, R = 1e9;
	int d1 = query(R, L), d2 = query(R, R);
	int ym = (L + R + d1 - d2) / 2;
	int d3 = query(L, ym), d4 = query(R, ym);
	printf("! %d %d %d %d\n", d3 + L, d1 - d4 + L, R - d4, R - d2 + d4);
}