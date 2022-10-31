#include<bits/stdc++.h>

typedef long long LL;

int n,k,vis[105];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		memset(vis,0,sizeof(vis));
		int mx=0;
		for (int i=1;i<=n;i++)
		{
			LL x;scanf("%lld",&x);
			int cnt=0;
			while (x)
			{
				cnt++;
				if (x%k>1) mx=2;
				else if (x%k==1) vis[cnt]++,mx=std::max(mx,vis[cnt]);
				x/=k;
			}
		}
		puts(mx<=1?"YES":"NO");
	}
	return 0;
}