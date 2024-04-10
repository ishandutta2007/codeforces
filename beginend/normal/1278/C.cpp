#include<bits/stdc++.h>

const int N=100005;

int n,fir[N*2],a[N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=0;i<=n*2;i++) fir[i]=-n;
		fir[n]=0;
		int s=0;
		for (int i=1;i<=n;i++)
		{
			int x;scanf("%d",&x);
			if (x==1) s++;
			else s--;
			fir[s+n]=i;
		}
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		s=0;
		int ans=n*2;
		ans=std::min(ans,n+n-fir[n]);
		for (int i=n;i>=1;i--)
		{
			if (a[i]==1) s--;
			else s++;
			ans=std::min(ans,i-1+n-fir[s+n]);
		}
		printf("%d\n",ans);
	}
	return 0;
}