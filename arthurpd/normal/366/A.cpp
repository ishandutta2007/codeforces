#include <stdio.h>
#include <vector>
using namespace std;

int
main(void)
{
	int n, a, b, c, d;
	scanf("%d", &n);
	for(int i = 1; i <= 4; i++)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(min(a,b) + min(c,d) <= n)
		{
			printf("%d %d %d\n", i, min(a,b), n - min(a,b));
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}