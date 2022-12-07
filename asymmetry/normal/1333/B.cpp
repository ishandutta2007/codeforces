#include <bits/stdc++.h>

using namespace std;

int t, n, c, d, e;
int a[100001];
int b[100001];

int main()
{
	scanf("%d", &t);
	for(int gh=0; gh<t; ++gh)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", &a[i]);
		}
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", &b[i]);
		}
		c=0;
		d=0;
		e=1;
		for(int i=1; i<=n; ++i)
		{
			if(a[i]==b[i])
			{
				if(a[i]==-1)
				{
					c=1;
				}
				if(a[i]==1)
				{
					d=1;
				}
				continue;
			}
			if(a[i]<b[i])
			{
				if(!d)
				{
					e=0;
					break;
				}
			}
			else
			{
				if(!c)
				{
					e=0;
					break;
				}
			}
			if(a[i]==-1)
			{
				c=1;
			}
			if(a[i]==1)
			{
				d=1;
			}
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