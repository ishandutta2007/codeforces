#include<bits/stdc++.h>

using namespace std;

const int MX = 100000;

long double p[MX], q[MX], a[MX], b[MX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double f;
		scanf("%lf", &f);
		
		p[i] = f;
	}
	
	for (int i = 0; i < n; i++) {
		double f;
		scanf("%lf", &f);
		
		q[i] = f;
	}
	
	long double sumA = 0, sumB = 0;
	for (int i = 0; i < n; i++) {
		long double B = -(p[i] + q[i] + sumB - sumA);
		long double C = p[i] - (p[i] + q[i]) * sumA;
		long double D = B * B - 4 * C;
		if (D < 0) D = 0.0;
		else D = sqrt(D);
		
		a[i] = (D - B) / 2.0;
		b[i] = p[i] + q[i] - a[i];
		
		sumA += a[i];
		sumB += b[i];
	}
	
	for (int i = 0; i < n; i++) printf("%.12f ", (double)(a[i]));
	printf("\n");

	for (int i = 0; i < n; i++) printf("%.12f ", (double)(b[i]));
	printf("\n");
	
	return 0;
}