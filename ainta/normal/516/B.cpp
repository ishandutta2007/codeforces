#include<stdio.h>
int Q[4010000][2], n, m, h, t;
bool v[2010][2010];
char p[2010][2010];
void Add(int x, int y){
	t++;
	Q[t][0] = x, Q[t][1] = y;
}
int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
int Chk(int x, int y){
	if (p[x][y] != '.' || v[x][y])return 0;
	int i, cnt = 0;
	for (i = 0; i < 4; i++){
		if (p[x + dir[i][0]][y + dir[i][1]] == '.')cnt++;
	}
	return cnt;
}
int main(){
	int i, j, x, y, x2, y2, x3, y3;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		scanf("%s", p[i] + 1);
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			if (Chk(i, j) == 1)Add(i, j);
		}
	}
	while (h < t){
		++h;
		x = Q[h][0], y = Q[h][1];
		if (p[x][y] != '.')continue;
		for (i = 0; i < 4; i++){
			x2 = x + dir[i][0], y2 = y + dir[i][1];
			if (p[x2][y2] == '.')break;
		}
		if (i == 4)break;
		if (i == 0)p[x][y] = '<', p[x2][y2] = '>';
		if (i == 1)p[x][y] = '^', p[x2][y2] = 'v';
		if (i == 2)p[x][y] = '>', p[x2][y2] = '<';
		if (i == 3)p[x][y] = 'v', p[x2][y2] = '^';
		for (i = 0; i < 4; i++){
			x3 = x + dir[i][0], y3 = y + dir[i][1];
			if (Chk(x3, y3) == 1)Add(x3, y3);
			x3 = x2 + dir[i][0], y3 = y2 + dir[i][1];
			if (Chk(x3, y3) == 1)Add(x3, y3);
		}
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			if (p[i][j] == '.')break;
		}
		if (j != m + 1)break;
	}
	if (i == n + 1){
		for (i = 1; i <= n; i++)printf("%s\n", p[i] + 1);
	}
	else{
		printf("Not unique\n");
	}
}