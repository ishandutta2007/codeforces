#include<cstdio>
#include<map>
#include<algorithm>
#define mod 1000000007
#define N 350
using namespace std;
map<int,int> id,tid;
int ct,n,m,a,b,q[N][2],is[N],head[N],cnt,vis[N];
long long ans;
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
int getsize(int x)
{
	int ans=0,lb=x,rb=x;
	while(lb<=n)
	{
		if(rb>n)rb=n;
		ans+=rb-lb+1;
		rb=rb*2+1,lb=lb*2;
	}
	return ans;
}
int getsz(int s)
{
	int ans=0;
	if(!id[s*2])ans+=getsize(s*2);
	if(!id[s*2+1])ans+=getsize(s*2+1);
	return ans+1;
}
void link(int s)
{
	if(s==1)return;
	if(!id[s])id[s]=++ct,tid[ct]=s;
	if(!id[s/2])id[s/2]=++ct,tid[ct]=s/2;
	if(!is[id[s]])adde(id[s],id[s/2]),is[id[s]]=1;
	link(s/2);
}
void getas(int a,int b){ans=(ans+1ll*getsz(tid[a])*getsz(tid[b]))%mod;}
void dfs(int s,int u)
{
	vis[u]=1;
	getas(s,u);
	for(int i=head[u];i;i=ed[i].next)
	if(!vis[ed[i].t])dfs(s,ed[i].t);
	vis[u]=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	id[ct=1]=tid[1]=1;
	for(int i=1;i<=m;i++)
	scanf("%d%d",&q[i][0],&q[i][1]),link(q[i][0]),link(q[i][1]),adde(id[q[i][0]],id[q[i][1]]);
	for(int i=1;i<=ct;i++)dfs(i,i);
	printf("%lld\n",ans%mod);
}