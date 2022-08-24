#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int w[100010], n, m, par[100010], C[100010];
long long Sum;
double Gap;
struct Edge{
	int a, b, c;
	bool operator <(const Edge &p)const{
		return c < p.c;
	}
}E[100010];
int find(int a){
	if (a == par[a])return a;
	return par[a] = find(par[a]);
}
int main()
{
	int i, x, y;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		par[i] = i;
		C[i] = 1;
	}
	for (i = 0; i < m; i++){
		scanf("%d%d", &E[i].a, &E[i].b);
		E[i].c = min(w[E[i].a], w[E[i].b]);
	}
	sort(E, E + m);
	for (i = m - 1; i >= 0; i--){
		x = find(E[i].a);
		y = find(E[i].b);
		if (x == y)continue;
		Sum += (long long)C[x] * (long long)C[y] * (long long)E[i].c;
		par[y] = x;
		C[x] += C[y];
		C[y] = 0;
	}
	Gap = n;
	Gap *= (Gap - 1)*0.5;
	Gap = Sum / Gap;
	printf("%lf\n", Gap);
}