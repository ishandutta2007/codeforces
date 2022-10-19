#include<bits/stdc++.h>
using namespace std;
int a[20];
long long mp[20][20],f[20][1<<18];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	while(k--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		mp[u][v]+=w;
	}
	for(int i=1;i<(1<<n);i++)for(int j=1;j<=n;j++)if(i&(1<<j-1))
	{
		f[j][i]=a[j];
		for(int k=1;k<=n;k++)if((i&(1<<k-1))&&j!=k)
			f[j][i]=max(f[j][i],a[j]+f[k][i^(1<<j-1)]+mp[k][j]);
	}
	long long ans=0;
	for(int i=0;i<(1<<n);i++)
	{
		int gs=0;
		long long aa=0;
		for(int j=1;j<=n;j++)gs+=(i>>j-1)&1,aa=max(aa,f[j][i]);
		if(gs==m)ans=max(ans,aa);
	}
	cout<<ans<<endl;
	return 0;
}