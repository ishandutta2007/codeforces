#pragma warning(disable:4996)
#include<stdio.h>
long long n, m, k, res, S, T, C, Mod = 1000000009;
long long Pow(long long x){
	long long r = 1, y = 2;
	while (x){
		if (x&(1ll)){
			r = r*y%Mod;
		}
		x >>= 1;
		y = y*y%Mod;
	}
	return r;
}
int main()
{
	scanf("%lld%lld%lld", &n, &m, &k);
	if (k*(n - m) >= n){
		printf("%lld\n", m);
	}
	else{
		res = (n - m)*(k - 1);
		T = n - (n - m)*k;
		C = T / k;
		S = (Pow(C) - 1) * 2 % Mod * k % Mod;
		res = S + T - (C*k) + res;
		printf("%lld\n", res%Mod);
	}
}