#pragma warning(disable:4996)
#include<stdio.h>
#define N_ 1000010
int n, p[20][N_], dep[N_];
int dis(int a, int b){
	int t, i, lca, r = dep[a] + dep[b];
	if (dep[a] < dep[b])t = a, a = b, b = t;
	t = dep[a] - dep[b];
	i = 0;
	while (t){
		if (t & 1)a = p[i][a];
		i++, t >>= 1;
	}
	for (i = 19; i >= 0; i--){
		if (p[i][a] != p[i][b]){
			a = p[i][a], b = p[i][b];
		}
	}
	if (a != b) lca = p[0][a];
	else lca = a;
	return r - dep[lca] * 2;
}
int main()
{
	int i, cnt = 4, x, M = 2, u = 1, v = 2, t;
	dep[1] = dep[2] = dep[3] = 1;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &x);
		x--;
		p[0][cnt] = p[0][cnt + 1] = x;
		dep[cnt] = dep[cnt + 1] = dep[x] + 1;
		for (i = 1; i < 20; i++){
			p[i][cnt] = p[i - 1][p[i - 1][cnt]];
			p[i][cnt + 1] = p[i - 1][p[i - 1][cnt + 1]];
		}
		t = dis(x, v) + 1;
		if (M < t)M = t, u = cnt;
		t = dis(x, u) + 1;
		if (M < t)M = t, v = cnt;
		cnt += 2;
		printf("%d\n", M);
	}
}