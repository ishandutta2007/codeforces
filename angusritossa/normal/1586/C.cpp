#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 1000010
vector<bool> inp[1000010];
vector<bool> grid[1000010];
int isBad[1000010];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		inp[i].push_back(0);
		grid[i].push_back(0);
		for (int j = 1; j <= m; j++) {
			char c;
			scanf(" %c", &c);
			inp[i].push_back(c == 'X');

			if (i == 1 || j == 1) {
				grid[i].push_back(c == 'X');
			} else if (c == 'X') {
				grid[i].push_back(1);
			} else {
				grid[i].push_back(grid[i-1][j] && grid[i][j-1]);
			}
		}
	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d", (int)grid[i][j]);
		}
		printf("\n");
	*/
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (inp[i-1][j] && inp[i][j-1]) {
				isBad[j-1] = 1;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		isBad[i] += isBad[i-1];
		//printf("%d: %d\n", i , isBad[i]);
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int am = isBad[b-1] - isBad[a-1];
		if (am) printf("NO\n");
		else printf("YES\n");
	}

}