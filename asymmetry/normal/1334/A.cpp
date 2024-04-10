#include <bits/stdc++.h>

using namespace std;

int n, gh, a, b, c, d, e;

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		scanf("%d", &n);
		c=0;
		d=0;
		e=1;
		for(int i=1; i<=n; ++i)
		{
			scanf("%d%d", &a, &b);
			if(a<c || b<d || b-d>a-c)
			{
				e=0;
			}
			c=a;
			d=b;
		}
		if(e)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}