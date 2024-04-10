#pragma warning(disable:4996)
#include<stdio.h>
long long n, i, K = 1e17, x, num, R;
int main()
{
	scanf("%lld", &n);
	x = 1;
	while (x < K){
		x *= 3;
		if (x >= n){
			if (R < 1)R = 1;
			break;
		}
		if (n%x != 0){
			num = n / x + 1;
			if (R < num)R = num;
		}
	}
	printf("%lld\n", R);
}