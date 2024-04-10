#include<cstdio>
#include<algorithm>
using namespace std;
int n, D[2010][2010], K, w[2010][2010], Rank[2010][2010];
char p[2010][2010];
struct point {
	int a, b, num;
	bool operator<(const point &p)const {
		return a != p.a ? a < p.a : b < p.b;
	}
}T[2010];
void Go(int x, int y) {
	printf("%c", p[x][y]);
	if (x == n&&y == n)return;
	if (y == n)Go(x + 1, y);
	else if (x == n)Go(x, y + 1);
	else {
		if (Rank[x + 1][y] < Rank[x][y + 1])Go(x + 1, y);
		else Go(x, y + 1);
	}
}
int main() {
	int i, j;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; i++) {
		scanf("%s", p[i] + 1);
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			int t = 1e9;
			if (i == 1 && j == 1)t = 0;
			if (i != 1)t = min(t, D[i - 1][j]);
			if (j != 1)t = min(t, D[i][j - 1]);
			D[i][j] = t + (p[i][j] != 'a');
		}
	}
	int Mx = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (D[i][j] <= K && Mx < i + j)Mx = i + j;
		}
	}
	Rank[n][n] = 1;
	for (i = n + n - 1; i >= 1; i--) {
		int cnt = 0;
		for (j = 1; j <= n; j++) {
			int x = j, y = i - j;
			if (1 <= y && y <= n) {
				int tp = 1e9;
				if (x != n)tp = min(tp, Rank[x + 1][y]);
				if (y != n)tp = min(tp, Rank[x][y + 1]);
				T[++cnt] = {p[x][y] - 'a' + 1, tp, x};
			}
		}
		sort(T + 1, T + cnt + 1);
		int c = 0;
		for (j = 1; j <= cnt; j++) {
			if (j == 1 || T[j].a != T[j - 1].a || T[j].b != T[j - 1].b)c++;
			Rank[T[j].num][i - T[j].num] = c;
		}
	}
	if (Mx == n + n) {
		for (i = 1; i < 2 * n; i++)printf("a");
		return 0;
	}
	if (Mx == 0) {
		Go(1, 1);
	}
	else {
		int RR = 1e9, pv = -1;
		for (i = 1; i <= n; i++)for (j = 1; j <= n; j++)if (Mx + 1 == i + j  && ((i!=1 && D[i-1][j] <= K)|| (j!=1 && D[i][j-1]<=K)))  {
			if (RR > Rank[i][j])RR = Rank[i][j], pv = i;
		}
		for (i = 1; i < Mx; i++)printf("a");
		Go(pv, Mx + 1 - pv);
	}
}