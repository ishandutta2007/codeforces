#include <stdio.h>

int
main(void)
{
	int n, i, j, k, a[100100], sum, ans = 0;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++) scanf("%d", a+i);
	for(i = 0, j = 0, sum = a[0]; i < n; )
	{
		if(sum <= k)
		{	ans = ((++i)-j > ans) ? i-j : ans; sum += a[i];}
		else
			sum -= a[j++];
	}
	printf("%d\n", ans);
	return 0;
}