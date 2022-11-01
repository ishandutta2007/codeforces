#include<bits/stdc++.h>

const int N=100005;

int n,r,a[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&r);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);
		n=std::unique(a+1,a+n+1)-a-1;
		int p=n,now=0,ans=0;
		while (p>=1)
		{
			p--;now+=r;ans++;
			while (p<=n&&a[p]-now<=0) p--;
		}
		printf("%d\n",ans);
	}
	return 0;
}