#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int u,v,w;
	bool operator<(const apple &other)const
	{
		return w<other.w;
	}
}e[300005];
int mx[300005],f[300005];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1);
	int wz=1;
    int ans=0;
	while(wz<=m)
	{
		int zw=wz;
		while(zw<m&&e[zw+1].w==e[zw].w)zw++;
		for(int i=wz;i<=zw;i++)
		{
			f[i]=mx[e[i].u]+1;
			ans=max(ans,f[i]);
		}
		for(int i=wz;i<=zw;i++)mx[e[i].v]=max(mx[e[i].v],f[i]);
		wz=zw+1;
	}
	cout<<ans<<endl;
	return 0;
}