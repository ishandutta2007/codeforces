#include <stdio.h>

int n, a, b;
char str[200000];

int main()
{
	scanf("%d %d %d", &n, &a, &b);
	scanf("%s", str);
	if (str[a - 1] == str[b - 1])printf("0\n");
	else printf("1\n");
	return 0;
}