#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[1000];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int p=0,pd=0;
		for (int i=1;i<=n;++i)
		{
			p+=a[i];
			if (p==m)
			{
				if (i==n)
					pd=1;
				else
					swap(a[i],a[i+1]);
				break;
			}
		}
		if (pd)
			puts("NO");
		else
		{
			puts("YES");
			for (int i=1;i<=n;++i)
				printf("%d ",a[i]);
			puts("");
		}
	}
}