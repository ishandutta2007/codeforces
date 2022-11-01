#include<bits/stdc++.h>

const int N=200005;

int n,ls[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int ans=n+1;
		for (int i=1;i<=n;i++)
		{
			int x;scanf("%d",&x);
			if (ls[x]) ans=std::min(ans,i-ls[x]+1);
			ls[x]=i;
		}
		if (ans==n+1) puts("-1");
		else printf("%d\n",ans);
		for (int i=1;i<=n;i++) ls[i]=0;
	}
	return 0;
}