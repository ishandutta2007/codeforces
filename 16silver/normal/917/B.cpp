#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, char> pic;
vector<pic> A[100];

int d[100][100][26];

int solve(int x, int y, char s) {
	if (d[x][y][s - 'a'] != -1) return d[x][y][s - 'a'];
	int i, ans = 0;
	for (i = 0; i < A[x].size(); i++) {
		if (A[x][i].second >= s) {
			if (solve(y, A[x][i].first, A[x][i].second) == 0) ans = 1;
		}
	}
	return d[x][y][s - 'a'] = ans;
}

int main()
{
	int n, m, i, j, k, u, v;
	char c[7];
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d%s", &u, &v, c);
		A[u - 1].push_back(pic(v - 1, c[0]));
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < 26; k++) d[i][j][k] = -1;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%c", (solve(i, j, 'a') ? 'A' : 'B'));

		}
		printf("\n");
	}
}