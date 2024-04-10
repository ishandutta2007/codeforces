#include<bits/stdc++.h>

int n,ans[100005];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int tot=0;
		for (int i=1,last;i<=n;i=last+1)
		{
			last=n/(n/i);
			ans[++tot]=n/i;
		}
		ans[++tot]=0;
		printf("%d\n",tot);
		while (tot) printf("%d ",ans[tot--]);
		puts("");
	}
}