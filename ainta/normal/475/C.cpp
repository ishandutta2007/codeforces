#include<stdio.h>
int n, m;
char p[1010][1010];
int D[1010][1010];
bool Pos(int x, int y){
	int i, j, ax = -1, ay;
	int t = -1;
	for (i = y; i <= n; i++){
		for (j = x; j <= m; j++){
			if (D[i][j] - D[i][j - x] - D[i - y][j] + D[i - y][j - x] == x*y){
				if (t > j)return false;
				t = j;
			}
		}
	}
	return true;
}
bool Pos2(int x, int y){
	int i, j, ax = -1, ay;
	for (i = y; i <= n; i++){
		for (j = x; j <= m; j++){
			if (D[i][j] - D[i][j - x] - D[i - y][j] + D[i - y][j - x] == x*y){
				if (ax == -1 || (i == ax && j == ay + 1) || (i == ax + 1 && j == ay)){
					ax = i, ay = j;
					continue;
				}
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int i, j, Mx, My, c, Res, xx, yy;
	int be, ed, mid;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		scanf("%s", p[i] + 1);
	}
	Mx = m, My = n;
	for (i = 1; i <= n; i++){
		c = 0;
		for (j = 1; j <= m; j++){
			if (p[i][j] == 'X')c++;
			if (j == m || p[i][j + 1] == '.'){
				if (c && Mx > c)Mx = c;
				c = 0;
			}
		}
	}
	for (i = 1; i <= m; i++){
		c = 0;
		for (j = 1; j <= n; j++){
			if (p[j][i] == 'X')c++;
			if (j == n || p[j + 1][i] == '.'){
				if (c && My > c)My = c;
				c = 0;
			}
		}
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			if (p[i][j] == 'X')D[i][j] = 1;
			else D[i][j] = 0;
		}
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			D[i][j] += D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1];
		}
	}
	if (!Pos(Mx, My)){
		printf("-1\n");
		return 0;
	}
	xx = Mx, yy = My;
	be = 1, ed = Mx - 1;
	while (be <= ed){
		mid = (be + ed) >> 1;
		if (Pos(mid, My)){
			ed = mid - 1;
			xx = mid;
		}
		else be = mid + 1;
	}
	be = 1, ed = My - 1;
	while (be <= ed){
		mid = (be + ed) >> 1;
		if (Pos(Mx, mid)){
			yy = mid;
			ed = mid - 1;
		}
		else be = mid + 1;
	}
	Res = -1;
	if (Pos2(xx, My)){
		Res = xx*My;
	}
	if (Pos2(Mx, yy)){
		if (Res == -1 || Res > Mx * yy)Res = Mx*yy;
	}
	printf("%d\n", Res);
}