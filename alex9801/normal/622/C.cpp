#include <stdio.h>
#include <algorithm>

int arr[200010];
int pos[200010];

int main()
{
	int n, m, c = 0, l, r, x, p1, p2, i;
	scanf("%d%d", &n, &m);
	for(i = 1; i<=n; i++)
		scanf("%d", &arr[i]);

	for(i = 1; i<=n; i++)
		if(i==n||arr[i]!=arr[i+1])
			pos[c++] = i;

	for(i = 0; i<m; i++)
	{
		scanf("%d%d%d", &l, &r, &x);
		if(arr[l]!=x)
		{
			printf("%d\n", l);
			continue;
		}
		p1 = std::lower_bound(pos, pos+c, l) - pos;
		p2 = std::lower_bound(pos, pos+c, r) - pos;
		if(p1==p2)
			printf("-1\n");
		else
			printf("%d\n", pos[p1]+1);
	}
	return 0;
}