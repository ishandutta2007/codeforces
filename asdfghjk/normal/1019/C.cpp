#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
const int N=1000005;
int n,m,i,j,k,head[N],adj[N],nxt[N],ans[N],cnt,vis[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i]=k;
		nxt[i]=head[j];
		head[j]=i;
	}
	for(i=1;i<=n;++i)
		if(vis[i]==0)
		{
			vis[i]=1;
			for(j=head[i];j;j=nxt[j])
				if(vis[adj[j]]==0)
					vis[adj[j]]=-1;
		}
	for(i=n;i>=1;--i)
		if(vis[i]==1)
			for(j=head[i];j;j=nxt[j])
				if(vis[adj[j]]==1)
					vis[adj[j]]=-1;
	for(i=1;i<=n;++i)
		if(vis[i]==1)
			ans[++cnt]=i;
	printf("%d\n",cnt);
	for(i=1;i<=cnt;++i)
		printf("%d ",ans[i]);
	return 0;
}