#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const int N=200005;
int n,m,i,j,k,K,head[N],adj[N],nxt[N],rhead[N],radj[N],rnxt[N],p[N],q[N],bg,ed,dis[N],mn,mx;
bool v[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i]=k;
		nxt[i]=head[j];
		head[j]=i;
		radj[i]=j;
		rnxt[i]=rhead[k];
		rhead[k]=i;
	}
	scanf("%d",&K);
	for(i=1;i<=K;++i)
		scanf("%d",p+i);
	q[bg=ed=1]=p[K];
	v[q[bg]]=true;
	dis[q[bg]]=0;
	while(bg<=ed)
	{
		for(i=rhead[q[bg]];i;i=rnxt[i])
			if(!v[radj[i]])
			{
				q[++ed]=radj[i];
				v[q[ed]]=true;
				dis[q[ed]]=dis[q[bg]]+1;
			}
		++bg;
	}
	for(i=1;i<K;++i)
	{
		for(j=head[p[i]],k=0;j;j=nxt[j])
			if(dis[p[i]]==dis[adj[j]]+1)
				++k;
		if(dis[p[i+1]]+1==dis[p[i]])
		{
			if(k>1)
				mx++;
		}
		else
			mn++,mx++;
	}
	printf("%d %d",mn,mx);
	return 0;
}