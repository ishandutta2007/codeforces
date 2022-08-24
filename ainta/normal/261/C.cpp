#pragma warning(disable:4996)
#include<stdio.h>
long long MX = 1000000000000LL;
long long C[60][60];
int p[60];
int main()
{
	long long n, t, x, Res = 0;
	int c = 0, m = 0, i, j;
	C[0][0] = 1;
	for (i = 1; i < 60; i++){
		C[i][0] = 1;
		for (j = 1; j < 60; j++){
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	scanf("%lld%lld", &n, &t);
	x = 1;
	while (1){
		if (t == x)break;
		if (x > MX)break;
		x *= 2;
		c++;
	}
	if (x > MX){
		printf("0\n");
		return 0;
	}
	c++;
	while (n){
		p[m++] = n % 2;
		n /= 2;
	}
	p[1]++;
	for (i = 1; p[i] == 2; i++){
		p[i + 1]++;
		p[i] = 0;
	}
	if (p[m + 1])m += 2;
	if (p[m])m++;
	for (i = m - 1; i >= 0; i--){
		if (p[i] == 1){
			Res += C[i][c];
			c--;
			if (c < 0)break;
		}
	}
	if (t == 1)Res--;
	printf("%lld\n", Res);
}