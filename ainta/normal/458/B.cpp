#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, i;
int a[100010], b[100010];
unsigned long long S, Res = 0xFFFFFFFFFFFFFFFF, SS = 0;
int main()
{
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for (i = 1; i <= m; i++){
		scanf("%d", &b[i]);
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	for (i = 1; i <= m; i++)S = S + b[i];
	SS = 0;
	for (i = 1; i <= n; i++){
		if (Res > S*(n + 1 - i) + SS)Res = S*(n + 1 - i) + SS;
		SS = SS + a[i];
	}
	S = 0;
	for (i = 1; i <= n; i++)S = S + a[i];
	SS = 0;
	for (i = 1; i <= m; i++){
		if (Res > S*(m + 1 - i) + SS)Res = S*(m + 1 - i) + SS;
		SS = SS + b[i];
	}
	printf("%lld\n", Res);
}