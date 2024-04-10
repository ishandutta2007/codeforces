#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[1010][1010],vis[1010][1010];
void DFS(int x, int y) {
	if (x<1 || x>n || y<1 || y>n)return;
	vis[x][y] = 1;
	int i, j;
	for (i = -1; i <= 1; i++)for (j = -1; j <= 1; j++) {
		if (!w[x + i][y + j] && !vis[x + i][y + j]) {
			DFS(x + i, y + j);
		}
	}
}
int main() {
	int i, j, ax, ay, bx, by, cx, cy;
	scanf("%d", &n);
	scanf("%d%d", &ax, &ay);
	scanf("%d%d", &bx, &by);
	scanf("%d%d", &cx, &cy);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == ax || j == ay || i + j == ax + ay || i - j == ax - ay) {
				w[i][j] = 1;
			}
		}
	}
	DFS(bx, by);
	if (vis[cx][cy])puts("YES");
	else puts("NO");
}