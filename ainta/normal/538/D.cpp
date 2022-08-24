#include<stdio.h>
int n, w[10100][2], cnt;
char p[60][60], res[110][110];
bool Ck(int x, int y){
	if (1 <= x&&x <= n && 1 <= y&&y <= n)return true;
	return false;
}
bool Pos(int x, int y){
	int i, j;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			if (p[i][j] == 'o' && Ck(i + x, j + y) && p[i+x][j+y] == '.'){
				return false;
			}
		}
	}
	return true;
}
bool Pos2(int x, int y){
	int i;
	for (i = 0; i < cnt; i++){
		if (Ck(x - w[i][0], y - w[i][1]) && p[x - w[i][0]][y - w[i][1]] == 'o')return true;
	}
	return false;
}
int main(){
	int i, j, chk = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%s", p[i] + 1);
	}
	for (i = -n + 1; i <= n - 1; i++){
		for (j = -n + 1; j <= n - 1; j++){
			if (i == 0 && j == 0)continue;
			if (Pos(i, j)){
				w[cnt][0] = i;
				w[cnt][1] = j;
				cnt++;
			}
		}
	}
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++){
			if (p[i][j] == 'x' && !Pos2(i, j))chk = 1;
		}
	}
	if (chk){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (i = 1; i <= 2*n-1; i++){
		for (j = 1; j <= 2*n-1; j++){
			res[i][j] = '.';
		}
	}
	res[n][n] = 'o';
	for (i = 0; i < cnt; i++){
		res[n + w[i][0]][n + w[i][1]] = 'x';
	}
	for (i = 1; i <= 2 * n - 1; i++)printf("%s\n", res[i] + 1);
}