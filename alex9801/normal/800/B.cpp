#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>

double x[1010];
double y[1010];

double dis(int i, int j)
{
	return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

double area(int i, int j, int k)
{
	return 0.5 * abs((x[j]-x[i])*(y[k]-y[i]) - (x[k]-x[i])*(y[j]-y[i]));
}

int main()
{
	int n, i, j;
	double t, r;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
		scanf("%lf%lf", &x[i], &y[i]);

	x[n] = x[0];
	y[n] = y[0];
	x[n+1] = x[1];
	y[n+1] = y[1];

	t = 1e10;
	for(i = 0; i<n; i++)
		for(j = i+1; j<n; j++)
			t = std::min(t, dis(i, j));

	r = t/2;
	for(i = 1; i<=n; i++)
		r = std::min(r, area(i-1, i, i+1) / dis(i-1, i+1));

	printf("%.10lf", r);
	return 0;
}