#include <stdio.h>
#include <vector>
using namespace std;

int a[112345], b[112345];

int
main(void)
{
	int n, m, ans = 0, ok = 1;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
		scanf("%d %d", &a[i], &b[i]);
	ans = max(ans, b[0] + a[0] - 1);
	ans = max(ans, b[m-1] + (n - a[m-1]));
	
	for(int i = 1; i < m; i++)
	{
		if(b[i] - b[i-1] > a[i] - a[i-1] || b[i-1] - b[i] > a[i] - a[i-1])
			ok = false;
//			x - b[i-1] + x - b[i] = a[i] - a[i-1]
		ans = max(ans, (b[i] + b[i-1] + a[i] - a[i-1]) / 2);
	}
	if(ok)
		printf("%d\n", ans);
	else
		printf("IMPOSSIBLE\n");
}