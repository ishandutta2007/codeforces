#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
const int N=600005;
struct node
{
	int h;
	long long d;
}t;
bool operator <(node a,node b)
{
	return a.d>b.d;
}
priority_queue<node> q;
int n,m,s,i,j,k,head[N],adj[N],nxt[N],len[N],w[N];
long long dis[N],ans;
bool v[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&j,&k,&len[i*2]);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
		len[i*2-1]=len[i*2];
	}
	scanf("%d",&s);
	for(i=1;i<=n;++i)
		dis[i]=1ll<<60;
	dis[s]=0;
	q.push((node){s,0});
	while(!q.empty())
	{
		t=q.top();
		q.pop();
		if(v[t.h])
			continue;
		v[t.h]=true;
		for(i=head[t.h];i;i=nxt[i])
			if(t.d+len[i]<dis[adj[i]]||t.d+len[i]==dis[adj[i]]&&(!w[adj[i]]||len[i]<len[w[adj[i]]*2]))
			{
				dis[adj[i]]=t.d+len[i];
				w[adj[i]]=(i+1)/2;
				q.push((node){adj[i],dis[adj[i]]});
			}
	}
	for(i=1;i<=n;++i)
		ans+=len[w[i]*2];
	printf("%lld\n",ans);
	for(i=1;i<=n;++i)
		if(w[i])
			printf("%d ",w[i]);
	return 0;
}