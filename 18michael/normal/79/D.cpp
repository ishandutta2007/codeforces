#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,k,l,p,t=0,Mx;
int a[10002],b[10002],f[1048576],pos[22],one[1048576],lg[1048576];
int dis[22][10002];
queue<int> q;
int main()
{
	scanf("%d%d%d",&n,&k,&l),lg[0]=-1;
	for(int i=1,x;i<=k;++i)scanf("%d",&x),b[x]=1;
	for(int i=1;i<=l;++i)scanf("%d",&a[i]);
	for(int i=0;i<=n;++i)if(b[i]^=b[i+1])pos[t++]=i;
	Mx=(1<<t)-1;
	for(int i=0;i<t;++i)
	{
		for(int j=0;j<=n;++j)dis[i][j]=inf;
		for(dis[i][pos[i]]=0,q.push(pos[i]);!q.empty();)
		{
			p=q.front(),q.pop();
			for(int j=1;j<=l;++j)
			{
				if(p+a[j]<=n && dis[i][p+a[j]]==inf)dis[i][p+a[j]]=dis[i][p]+1,q.push(p+a[j]);
				if(p-a[j]>=0 && dis[i][p-a[j]]==inf)dis[i][p-a[j]]=dis[i][p]+1,q.push(p-a[j]);
			}
		}
	}
	for(int i=1;i<=Mx;++i)
	{
		if((lg[i]=lg[i>>1]+1,one[i]=one[i>>1]+(i&1))&1)continue;
		f[i]=inf;
		for(int j=0;j<lg[i];++j)if((i>>j)&1)f[i]=min(f[i],f[i^(1<<j)^(1<<lg[i])]+dis[lg[i]][pos[j]]);
	}
	return 0&printf("%d",f[Mx]==inf? -1:f[Mx]);
}