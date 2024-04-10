#include<cstdio>
#include<algorithm>
using namespace std;
#define N 105000
struct edge{int t,next,v;}ed[N*2];
struct sth{int a;long long b;int t;friend bool operator <(sth a,sth b){return a.b==b.b?a.t>b.t:a.b>b.b;}}s[N*2];
int head[N],cnt,n,m,b,c,ct,fa[N],sz[N],is[N];
long long a;
int finds(int x){return fa[x]==x?x:fa[x]=finds(fa[x]);}
long long f[N],m1[N],m2[N],dp1[N],dp2[N];
void adde(int f,int t,int v){ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;ed[++cnt]=(edge){f,head[t],v};head[t]=cnt;}
void dfs1(int u,int fa)
{
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		dfs1(ed[i].t,u);
		dp1[u]=max(dp1[u],dp1[ed[i].t]+ed[i].v);
		if(m1[u]<dp1[ed[i].t]+ed[i].v)m2[u]=m1[u],m1[u]=dp1[ed[i].t]+ed[i].v;
		else if(m2[u]<dp1[ed[i].t]+ed[i].v)m2[u]=dp1[ed[i].t]+ed[i].v;
	}
}
void dfs2(int u,int fa)
{
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		long long st=m1[u];
		if(dp1[ed[i].t]+ed[i].v==st)st=m2[u];
		dp2[ed[i].t]=max(st,dp2[u])+ed[i].v;
		dfs2(ed[i].t,u);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%lld%d%d",&a,&b,&c),adde(a,b,c);
	dfs1(1,0);dfs2(1,0);
	for(int i=1;i<=n;i++)f[i]=max(dp1[i],dp2[i]);
	scanf("%d",&m);
	while(m--)
	{
		int as=1;ct=0;
		scanf("%lld",&a);
		for(int i=1;i<=n;i++)
		{
			s[++ct]=(sth){i,f[i],1};
			s[++ct]=(sth){i,f[i]-a,0};
		}
		sort(s+1,s+ct+1);
		for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1,is[i]=0;
		for(int i=1;i<=ct;i++)
		{
			int a=s[i].a,b=s[i].t;
			if(b==1)
			{
				is[a]=1;
				for(int j=head[a];j;j=ed[j].next)
				if(is[ed[j].t])
				{
					int v1=finds(a),v2=finds(ed[j].t);
					fa[v1]=v2,sz[v2]+=sz[v1],as=max(as,sz[v2]);
				}
			}
			else sz[finds(a)]--;
		}
		printf("%d\n",as);
	}
}