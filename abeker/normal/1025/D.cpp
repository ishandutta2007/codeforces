#include <bits/stdc++.h>
using namespace std;

const int MAXN = 7e2 + 5;

int N;
int a[MAXN];
int mat[MAXN][MAXN];
int dp[MAXN][MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

int rec(int x, int y) {
	int &ref = dp[x][y];
	if (ref != -1)
		return ref;
	
	if (x == y)
		return ref = 1;
	
	if (x < y) {
		for (int i = x + 1; i <= y; i++)
			if (mat[x][i] > 1 && rec(i, x + 1) && rec(i, y))
				return ref = 1;
		return ref = 0;
	}
	
	for (int i = x - 1; i >= y; i--)
		if (mat[x][i] > 1 && rec(i, x - 1) && rec(i, y))
			return ref = 1;
	
	return ref = 0;
}

bool solve() {
	memset(dp, -1, sizeof dp);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			mat[i][j] = __gcd(a[i], a[j]);
	
	for (int i = 0; i < N; i++)
		if (rec(i, 0) && rec(i, N - 1))
			return true;
	
	return false;
}

int main() {
	load();
	puts(solve() ? "Yes" : "No");
	return 0;
}