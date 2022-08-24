#pragma warning(disable:4996)
#include<stdio.h>
int n, par[20][101000], Dep[100010];
struct point{
	long long x, y;
}w[100010];
int st[100010], top;
bool ccw(point a, point b, point c){
	return (b.x - a.x)*(c.y - a.y) > (b.y - a.y)*(c.x - a.x);
}
int LCA(int a, int b){
	if (Dep[a] < Dep[b])return LCA(b, a);
	int d = Dep[a] - Dep[b], t = 0, i;
	while (d){
		if (d&(1 << t)){
			d ^= (1 << t);
			a = par[t][a];
		}
		t++;
	}
	for (i = 16; i >= 0; i--){
		if (par[i][a] != par[i][b])a = par[i][a], b = par[i][b];
	}
	if (a != b)a = par[0][a], b = par[0][b];
	return a;
}
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%lld%lld", &w[i].x, &w[i].y);
	}
	for (i = n; i >= 1; i--){
		if (i == n){
			st[++top] = i;
			continue;
		}
		while (top > 1 && ccw(w[i], w[st[top]], w[st[top - 1]])) top--;
		par[0][i] = st[top];
		Dep[i] = Dep[st[top]] + 1;
		st[++top] = i;
	}
	for (i = 1; i <= 16; i++){
		for (j = 1; j <= n; j++){
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
	int Q, a, b;
	scanf("%d", &Q);
	while (Q--){
		scanf("%d%d", &a, &b);
		printf("%d ", LCA(a, b));
	}
}