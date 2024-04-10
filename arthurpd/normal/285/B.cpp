#include <stdio.h>

bool hash[100100];

int
main(void)
{
	int n, s, t, p[100100], i, ans = 0;
	scanf("%d %d %d", &n, &s, &t);
	for(i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	while(s != t)
	{
		if(hash[s] == true)
		{
			ans = -1;
			break;
		}
		hash[s] = true;
		s = p[s];
		ans++;
	}
	
	printf("%d\n", ans);
}