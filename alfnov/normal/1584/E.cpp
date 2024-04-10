#include<bits/stdc++.h>
using namespace std;
int a[300005];
long long d[300005],dd[300005];
int f[21][300005],gg[21][300005];
vector<int>g[300005];
int main()
{
	int T=1;
	cin>>T;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=0;i<=n;i++)g[i].clear();
		if(n==1)
		{
			if(a[1])printf("0\n");
			else printf("1\n");
			continue;
		}
		long long sy=0;
		d[0]=dd[0]=0;
		for(int i=1;i<=n;i++)
		{
			sy=a[i]-sy;
			if(i&1)d[i]=dd[i]=-sy;
			else d[i]=dd[i]=sy;
		}
		sort(dd,dd+n+1);
		for(int i=0;i<=n;i++)
		{
			d[i]=f[0][i]=gg[0][i]=lower_bound(dd,dd+n+1,d[i])-dd;
			if(i&1)f[0][i]=INT_MAX;
			else gg[0][i]=INT_MIN;
		}
		for(int i=1;i<=n;i++)g[d[i]].push_back(i);
		for(int i=1;i<=20;i++)for(int j=1;j<=n;j++)
		{
			if(j+(1<<i)-1>n)break;
			f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
			gg[i][j]=max(gg[i-1][j],gg[i-1][j+(1<<i-1)]);
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int ss=i,tt=i;
			for(int j=20;j>=0;j--)if(ss+(1<<j)-1<=n&&gg[j][ss]<=d[i-1])ss+=1<<j;
			for(int j=20;j>=0;j--)if(tt+(1<<j)-1<=n&&f[j][tt]>=d[i-1])tt+=1<<j;
			ss=min(ss,tt);
			int l=i,r=ss-1;
			if(r<l)continue;
			int ww=d[l-1];
			int R=upper_bound(g[ww].begin(),g[ww].end(),r)-g[ww].begin()-1;
			int L=lower_bound(g[ww].begin(),g[ww].end(),l)-g[ww].begin();
			ans+=R-L+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}