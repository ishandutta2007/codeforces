#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200005;
int t,n,m,i,j,k,l,p[N],head[N],adj[N*2],nxt[N*2],w[N];
int find(int x)
{
	return !p[x]?x:p[x]=find(p[x]);
}
void dfs(int x,int dad)
{
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dfs(adj[y],x);
			if(w[adj[y]]==0)
				w[x]=2;
			else if(w[adj[y]]==2)
				w[x]=max(w[x],1);
		}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)
			head[i]=p[i]=w[i]=0;
		l=0;
		for(i=1;i<=m;++i)
		{
			scanf("%d%d",&j,&k);
			if(find(j)!=find(k))
			{
				p[find(j)]=find(k);
				adj[++l]=k;
				nxt[l]=head[j];
				head[j]=l;
				adj[++l]=j;
				nxt[l]=head[k];
				head[k]=l;
			}
		}
		dfs(1,-1);
		if(w[1]==0)
			w[1]=2;
		for(i=1,j=0;i<=n;++i)
			if(w[i]==2)
				++j;
		printf("%d\n",j);
		for(i=1;i<=n;++i)
			if(w[i]==2)
				printf("%d ",i);
		puts("");
	}
	return 0;
}