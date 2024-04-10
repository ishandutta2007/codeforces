#include<stdio.h>
char p[101000];
char q[101000];
int n;
int main(){
	int i, b, e, r = 0;
	scanf("%d", &n);
	scanf("%s%s", p, q);
	for (i = 0; i < n; i++)if (p[i] != q[i])break;
	b = i;
	for (i = n - 1; i >= 0; i--)if (p[i] != q[i])break;
	e = i;
	if (b == e){
		printf("%d\n", 2);
		return 0;
	}
	for (i = b; i < e; i++)if (p[i] != q[i + 1])break;
	if (i == e)r++;
	for (i = b; i < e; i++)if (p[i + 1] != q[i])break;
	if (i == e)r++;
	printf("%d\n", r);
}