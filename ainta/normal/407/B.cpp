#pragma warning(disable:4996)
#include<stdio.h>
int D[1010], w[1010], Mod = 1000000007;
int main()
{
	int i, n, j, S;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	D[1] = 2;
	for (i = 2; i <= n; i++){
		S = 2;
		for (j = w[i]; j < i; j++){
			S = (S + D[j]) % Mod;
		}
		D[i] = S;
	}
	S = 0;
	for (i = 1; i <= n; i++)S = (S + D[i]) % Mod;
	printf("%d\n", S);
}