#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int n,x;

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&x);
		int mx1=0,mx2=0;
		for (int i=1;i<=n;i++)
		{
			int p,q;scanf("%d%d",&p,&q);
			mx1=std::max(mx1,p-q);
			mx2=std::max(mx2,p);
		}
		if (mx2>=x) printf("%d\n",1);
		else if (!mx1) puts("-1");
		else printf("%d\n",(x-mx2+mx1-1)/mx1+1);
	}
	return 0;
}