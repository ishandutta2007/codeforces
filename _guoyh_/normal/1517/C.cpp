# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 505;
int n;
int a[MAXN], pos[MAXN];
int c[MAXN][MAXN];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; i++){
		int nx = i, ny = i;
		c[nx][ny] = a[i];
		for (int j = 1; j < a[i]; j++){
			if (i < pos[j]) nx++;
			else ny--;
			if (c[nx][ny]){
				printf("-1\n");
				return 0;
			}
			c[nx][ny] = a[i];
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++) printf("%d ", c[i][j]);
		putchar('\n');
	}
	return 0;
}