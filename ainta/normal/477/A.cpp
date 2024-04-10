#include<stdio.h>
long long Res, Mod = 1000000007;
int main()
{
	long long a, b, i, T;
	scanf("%lld%lld", &a, &b);
	T = a*(a + 1) / 2 % Mod * b % Mod;
	for (i = 1; i < b; i++){
		Res = (Res + i * (T+a)) % Mod;
	}
	printf("%lld\n", Res);
}