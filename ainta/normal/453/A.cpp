#pragma warning(disable:4996)
#include<stdio.h>
int n, m;
double Res;
double Do(double a, int p){
	double r = 1.0;
	while (p){
		if (p & 1){
			r *= a;
		}
		p >>= 1;
		a = a * a;
	}
	return r;
}
int main()
{
	int i;
	scanf("%d%d", &m, &n);
	Res = m;
	for (i = 1; i < m; i++){
		Res -= Do((double)i / m, n);
	}
	printf("%lf\n", Res);
}