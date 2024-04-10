#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200005;
int n,i,j,k,head[N],adj[N*2],nxt[N*2],c[N*2],p0[N],p1[N],sz0[N],sz1[N];
bool v[N];
long long ans;
int find0(int x)
{
	return !p0[x]?x:p0[x]=find0(p0[x]);
}
int find1(int x)
{
	return !p1[x]?x:p1[x]=find1(p1[x]);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d%d%d",&j,&k,&c[i*2]);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
		c[i*2-1]=c[i*2];
	}
	for(i=1;i<n;++i)
		if(c[i*2]==0)
			p0[find0(adj[i*2-1])]=find0(adj[i*2]);
		else
			p1[find1(adj[i*2-1])]=find1(adj[i*2]);
	for(i=1;i<=n;++i)
		sz0[find0(i)]++,sz1[find1(i)]++;
	for(i=1;i<=n;++i)
		if(sz0[find0(i)]>=2&&sz1[find1(i)]>=2)
			ans+=1ll*(sz0[find0(i)]-1)*(sz1[find1(i)]-1);
	for(i=1;i<=n;++i)
	{
		if(find0(i)==i)
			ans+=1ll*sz0[i]*(sz0[i]-1);
		if(find1(i)==i)
			ans+=1ll*sz1[i]*(sz1[i]-1);
	}
	printf("%lld",ans);
	return 0;
}