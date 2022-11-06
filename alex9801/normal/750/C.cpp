#include <stdio.h>
#include <string.h>
#include <algorithm>

char tmp[100];
const int INF = 2000000000;

int main()
{
	int n, a = 0, c, d, d1, d2, i;

	d1 = INF;
	d2 = -INF;

	scanf("%d", &n);
	for(i = 0; i<n; i++)
	{
		scanf("%d%d", &c, &d);
		if(d==1)
			d1 = std::min(d1, a);
		else
			d2 = std::max(d2, a);
		a += c;
	}

	if(d2 == -INF)
	{
		printf("Infinity");
		return 0;
	}

	if(d2 >= d1)
	{
		printf("Impossible");
		return 0;
	}

	printf("%d", a + (1899 - d2));

	return 0;
}