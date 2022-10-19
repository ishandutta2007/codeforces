#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N;
int x[5], y[5];
bool bio[MAXN][MAXN];

bool ok(int r, int c) {
	return r > 0 && r <= N && c > 0 && c <= N && r != x[0] && c != y[0] && r - c != x[0] - y[0] && r + c != x[0] + y[0];
}

bool dfs(int r, int c) {
	if (bio[r][c])
		return false;
	bio[r][c] = true;
	if (r == x[2] && c == y[2])
		return true;
	for (int k = -1; k < 2; k++)
		for (int l = -1; l < 2; l++)
			if ((k || l) && ok(r + k, c + l) && dfs(r + k, c + l))
				return true;
	return false;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < 3; i++)
		scanf("%d%d", x + i, y + i);
	
	puts(dfs(x[1], y[1]) ? "YES" : "NO");
	
	return 0;
}