#include <stdio.h>
#include <algorithm>

int a[212345];

bool comp(int a, int b){ return a > b;}

int
main(void)
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[n-i-1]);
	for(int i = 0; i < n; i++)
		a[i] = a[i] - i;
	std::sort(a, a+n, comp);
	for(int i = 0; i < n; i++)
		a[i] += i;
	for(int i = 1; i < n; i++)
		if(a[i-1] < a[i])
		{
			printf(":(\n");
			return 0;
		}
	for(int i = 0; i < n; i++)
		printf("%d\n", a[n-i-1]);
}