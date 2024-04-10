#include <stdio.h>

int a[112345];

int
main(void)
{
	int n, k, x;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		a[i%k] += x;
	}
	int min = 0x3f3f3f3f, ans = 0;
	for(int i = 0; i < k; i++)
		if(a[i] < min)
			min = a[ans=i];
	printf("%d\n", ans+1);
}