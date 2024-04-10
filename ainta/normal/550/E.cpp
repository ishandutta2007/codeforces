#include<stdio.h>
int n, w[101000];
void Do1(int b, int e){
	int i;
	for (i = b; i <= e; i++)printf("(");
	for (i = b; i < e; i++)printf("%d)->", w[i]);
	printf("%d)", w[e]);
}
void Do2(int b, int e){
	int i;
	for (i = b; i < e; i++)printf("(%d->", w[i]);
	printf("(%d", w[e]);
	for (i = b; i <= e; i++)printf(")");
}
int main()
{
	int i, t;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	if (w[n] == 1){
		printf("NO\n");
		return 0;
	}
	for (i = 1; i <= n; i++)if (w[i] == 0)break;
	if (i == n - 1){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	if (n == 1){
		printf("0");
		return 0;
	}
	if (w[n - 1] == 1){
		Do1(1, n);
		return 0;
	}
	for (i = n - 2; i >= 1; i--)if (w[i] == 0)break;
	t = i;
	if (t == 1){
		printf("(");
		Do2(t, n - 1);
		printf("->%d)", w[n]);
		return 0;
	}
	printf("((");
	Do1(1, t - 1);
	printf("->");
	Do2(t, n - 1);
	printf(")->%d)", w[n]);
}