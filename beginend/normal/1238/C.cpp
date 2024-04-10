#include<bits/stdc++.h>

const int N=200005;

int h,n,p[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&h,&n);
		for (int i=1;i<=n;i++) scanf("%d",&p[i]);
		int now=1,ans=0;
		while (now<=n)
		{
			if (now==n) break;
			if (p[now]>p[now+1]+1) p[now]=p[now+1]+1;
			else if (p[now]==2) break;
			else if (now+2<=n&&p[now+2]==p[now]-2) now+=2;
			else now++,p[now]--,ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}