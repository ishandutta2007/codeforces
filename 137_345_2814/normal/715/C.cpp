#include<cstdio>
#include<map>
using namespace std;
#define N 100050
int n,m,k,sz[N],vis[N],dis[N],dis2[N],dis3[N],mx[N],head[N],cnt,a1,b1,c,mod,pw[N],inv[N],val,ans,tmp;
map<int,int> s1,s2,s3,s4;
long long Ans;
struct edge{int t,next,v;}ed[N*2];
void adde(int f,int t,int v){ed[++cnt]=(edge){t,head[f],v};head[f]=cnt;ed[++cnt]=(edge){f,head[t],v};head[t]=cnt;}
void dfs1(int u,int fa)
{
	sz[u]=1;mx[u]=0;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t])
	{
		dfs1(ed[i].t,u);
		sz[u]+=sz[ed[i].t];
		if(mx[u]<sz[ed[i].t])
		mx[u]=sz[ed[i].t];
	}
	if(mx[u]<val-sz[u])
	mx[u]=val-sz[u];
	if(mx[u]<ans)
	ans=mx[u],tmp=u;
}
void dfs2(int u,int fa)
{
	s4[dis3[u]]++;
	long long tmp=(mod-1ll*dis2[u]*inv[dis[u]]%mod)%mod;
	s3[tmp]++;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa&&!vis[ed[i].t])
	dis[ed[i].t]=dis[u]+1,dis2[ed[i].t]=(1ll*dis2[u]*10+ed[i].v)%mod,dis3[ed[i].t]=(dis3[u]+1ll*pw[dis[u]]*ed[i].v)%mod,dfs2(ed[i].t,u);
}
void work(int u)
{
	s1[0]=1,s2[0]=1;
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t])
	{
		dis2[ed[i].t]=dis3[ed[i].t]=ed[i].v%mod;
		dis[u]=0;dis[ed[i].t]=1;
		dfs2(ed[i].t,u);
		for(map<int,int>::iterator it=s3.begin();it!=s3.end();it++)
		{
			int a=it->first;int b=it->second;
			if(s2.count(a))
			Ans+=1ll*s2[a]*b;
		}
		for(map<int,int>::iterator it=s4.begin();it!=s4.end();it++)
		{
			int a=it->first;int b=it->second;
			if(s1.count(a))
			Ans+=1ll*s1[a]*b;
		}
		for(map<int,int>::iterator it=s3.begin();it!=s3.end();it++)
		{
			int a=it->first;int b=it->second;
			s1[a]+=b;
		}
		for(map<int,int>::iterator it=s4.begin();it!=s4.end();it++)
		{
			int a=it->first;int b=it->second;
			s2[a]+=b;
		}
		s3.clear();s4.clear();
	}
	s1.clear();s2.clear();
}
void dfs3(int u)
{
	vis[u]=1;
	work(u);
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t])
	ans=19260817,val=sz[ed[i].t],dfs1(ed[i].t,u),dfs3(tmp);
}
long long exgcd(long long a,long long b,long long& x,long long& y){if(!b){x=1,y=0;return a;}long long gcd=exgcd(b,a%b,x,y);long long t=x;x=y;y=t-a/b*y;return gcd;}
long long inv1(long long s,long long mod){long long x,y;exgcd(s,mod,x,y);return (x%mod+mod)%mod;}
int main()
{
	scanf("%d%d",&n,&mod);
	pw[0]=1,pw[1]=10,inv[0]=1,inv[1]=inv1(10,mod);
	for(int i=2;i<=n;i++)
	pw[i]=1ll*pw[i-1]*pw[1]%mod,inv[i]=1ll*inv[i-1]*inv[1]%mod; 
	for(int i=1;i<n;i++)
	scanf("%d%d%d",&a1,&b1,&c),adde(a1+1,b1+1,c);
	ans=19260817,val=n,dfs1(1,0),dfs3(tmp);
	printf("%lld\n",Ans);
}