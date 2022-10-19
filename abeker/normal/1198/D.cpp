#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;

int N;
char mat[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%s", mat[i] + 1);
}

int rec(int x1, int y1, int x2, int y2) {
	int &ref = dp[x1][y1][x2][y2];
	if (ref != -1)
		return ref;
	if (x1 == x2 && y1 == y2)
		return ref = mat[x1][y1] == '#';
	if (x2 - x1 > y2 - y1) {
		ref = x2 - x1 + 1;
		for (int x = x1; x < x2; x++)
			ref = min(ref, rec(x1, y1, x, y2) + rec(x + 1, y1, x2, y2));
	}
	else {
		ref = y2 - y1 + 1;
		for (int y = y1; y < y2; y++)
			ref = min(ref, rec(x1, y1, x2, y) + rec(x1, y + 1, x2, y2));
	}
	return ref;
}

int solve() {
	memset(dp, -1, sizeof dp);
	return rec(1, 1, N, N);
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}