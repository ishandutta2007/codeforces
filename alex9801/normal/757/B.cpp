#include <stdio.h>
#include <string.h>
#include <algorithm>

int cnt[100001];
bool chk[100001];

int main()
{
	int c, r, a, n, i;
	long long x, y;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
	{
		scanf("%d", &a);
		cnt[a]++;
	}

	r = 1;
	for(x = 2; x<50000; x++)
	{
		if(!chk[x])
		{
			c = 0;
			for(i = x; i<=100000; i += x)
				c += cnt[i];
			r = std::max(c, r);

			for(y = x*x; y<50000; y += x)
				chk[y] = 1;
		}
	}

	for(x = 50000; x<=100000; x++)
	{
		r = std::max(cnt[x], r);
	}

	printf("%d", r);
	return 0;
}