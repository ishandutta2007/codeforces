#pragma warning(disable:4996)
#include<stdio.h>
#define LL long long
bool Solve(LL a, LL b){
	if (!a)return false;
	if (!Solve(b%a, a))return true;
	LL t = b / a - 1;
	return ((t + 1) % (a + 1)) % 2 == 0;
}
int main()
{
	int T;
	LL a, b, t;
	scanf("%d", &T);
	while (T--){
		scanf("%lld%lld", &a, &b);
		if (a > b)t = a, a = b, b = t;
		printf(Solve(a, b) ? "First\n" : "Second\n");
	}
}