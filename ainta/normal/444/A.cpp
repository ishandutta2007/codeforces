#pragma warning(disable:4996)
#include<stdio.h>
int n, m, w[1010];
double R = 0;
int main()
{
	int i, a, b, d;
	double t;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
	}
	for (i = 1; i <= m; i++){
		scanf("%d%d%d", &a, &b, &d);
		t = w[a] + w[b];
		t = t / (double)d;
		if (R < t) R = t;
	}
	printf("%.10lf\n", R);
}