#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<math.h>
char p[100010], q[100010];
int m, r[100010], L1, L2;
int main()
{
	int i, t;
	scanf("%s", p);
	scanf("%s", q);
	for (i = 0; p[i]; i++);
	L1 = m = i;
	for (i = 0; q[i]; i++);
	L2 = i;
	if (m < i)m = i;
	if (m < 2)m = 2;
	for (i = L1 - 1; i >= 0; i--){
		p[i + m - L1] = p[i];
	}
	for (i = 0; i < m - L1; i++)p[i] = '0';
	for (i = L2 - 1; i >= 0; i--){
		q[i + m - L2] = q[i];
	}
	for (i = 0; i < m - L2; i++)q[i] = '0';
	for (i = 0; i < m; i++){
		r[i] = p[i] - q[i];
	}
	for (i = 0; i < m - 2; i++){
		if (r[i] > 100000)r[i] = 100000;
		if (r[i] < -100000)r[i] = -100000;
		if (r[i] != 0){
			r[i + 1] += r[i];
			r[i + 2] += r[i];
			r[i] = 0;
		}
	}
	double o;
	o = r[m - 2] * (sqrt(5.0) + 1)*0.5 + r[m - 1];
	if (o < 1e-8 && o > -(1e-8))printf("=\n");
	else if (o < 0)printf("<\n");
	else printf(">\n");
}