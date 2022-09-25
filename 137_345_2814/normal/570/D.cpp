#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int id[500001],sz[500001],sid[500001],id2[500001],sid2[500001],n,head[500001],q,a,b,cnt,val[500001],dep[500001],as[500001][2],m,cnt2,cnt3;
char s[500001];
struct edge{
	int next,t;
}ed[1000001];
void adde(int f,int t)
{
	ed[++cnt].t=t;
	ed[cnt].next=head[f];
	head[f]=cnt;
	ed[++cnt].t=f;
	ed[cnt].next=head[t];
	head[t]=cnt;
}
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	sid[++cnt2]=u;
	id[u]=cnt2;
	sz[u]=1;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	dfs(ed[i].t,u),sz[u]+=sz[ed[i].t];
}
void bfs()
{
	queue<int> wkr;
	wkr.push(1);
	while(!wkr.empty())
	{
		int t=wkr.front();wkr.pop();
		if(dep[t]>dep[sid2[cnt3]])
		as[dep[sid2[cnt3]]][1]=cnt3,
		as[dep[t]][0]=cnt3+1;
		id2[t]=++cnt3;sid2[cnt3]=t;
		for(int i=head[t];i;i=ed[i].next)
		if(dep[ed[i].t]>dep[t])
		wkr.push(ed[i].t);
	}
	as[dep[sid2[cnt3]]][1]=cnt3;
}
int che(int i,int j,int k)
{
	int lb=i,rb=j,ans=j;
	while(lb<=rb)
	{
		int mid=(lb+rb)>>1;
		if(id[sid2[mid]]>=id[k])
		rb=mid-1,ans=mid;
		else
		lb=mid+1;
	}
	return ans;
}
int che2(int i,int j,int k)
{
	int lb=i,rb=j,ans=i;
	while(lb<=rb)
	{
		int mid=(lb+rb)>>1;
		if(id[sid2[mid]]<=id[k]+sz[k]-1)
		lb=mid+1,ans=mid;
		else
		rb=mid-1;
	}
	return ans;
}
int main()
{
//	freopen("123.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	scanf("%d",&a),adde(a,i+1);
	dfs(1,0);bfs();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	val[i]=val[i-1]^(1<<(s[sid2[i]]-'a'));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		int l=as[b][0],r=as[b][1];
		if(l==r)
		{
			printf("Yes\n");
			continue;
		}
		int l1=che(l,r,a),l2=che2(l,r,a);
		if(l1==0)l1=1;
		int tmp=val[l2]^val[l1-1];
		if(l1>l2)
		tmp=0;
		if(tmp-(tmp&-tmp)==0)
		printf("Yes\n");
		else
		printf("No\n");
	}
}