#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);
	if (n <= 5) puts("-1");
	else
	{
		puts("1 2");
		puts("1 3");
		puts("1 4");
		for (int i = 5; i <= n; i ++)
			printf("2 %d\n", i);
	}
	for (int i = 2; i <= n; i ++)
		printf("1 %d\n", i);
	return 0;
}