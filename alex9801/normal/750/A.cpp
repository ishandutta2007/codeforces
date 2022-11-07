#include <stdio.h>
#include <string.h>
#include <algorithm>

int main()
{
	int n, k, t = 0, i;
	scanf("%d%d", &n, &k);
	t += k;
	for(i = 1; i<=n; i++)
	{
		t += 5*i;
		if(t > 240)
		{
			printf("%d", i-1);
			return 0;
		}
	}

	printf("%d", n);

	return 0;
}