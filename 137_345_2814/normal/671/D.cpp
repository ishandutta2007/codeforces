#include<cstdio>
#include<algorithm>
using namespace std;
#define N 300050
#define M 8000080
int head[N],cnt,dep[N],n,m,a,b,c;
struct edge{int t,next;}ed[N*2];
struct sth{int t,v;};
vector<sth> tp[N];
long long mn[M],vl[N],lz[M];
int ch[M][2],rt[N],ct;
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
void dfs1(int u,int fa){dep[u]=dep[fa]+1;for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs1(ed[i].t,u);}
void ins(int x,int l,int r,int s,long long v)
{
	mn[x]=min(mn[x],v);
	if(l==r)return;
	if(lz[x])mn[ch[x][0]]+=lz[x],mn[ch[x][1]]+=lz[x],lz[ch[x][0]]+=lz[x],lz[ch[x][1]]+=lz[x],lz[x]=0;
	int mid=(l+r)>>1;
	int t=mid<s;
	if(!ch[x][t])ch[x][t]=++ct,mn[ct]=1e17+1;
	if(mid>=s)ins(ch[x][0],l,mid,s,v);
	else ins(ch[x][1],mid+1,r,s,v);
}
int merge(int x,int y)
{
	if(!x||!y)return x+y;
	if(lz[x])mn[ch[x][0]]+=lz[x],mn[ch[x][1]]+=lz[x],lz[ch[x][0]]+=lz[x],lz[ch[x][1]]+=lz[x],lz[x]=0;
	if(lz[y])mn[ch[y][0]]+=lz[y],mn[ch[y][1]]+=lz[y],lz[ch[y][0]]+=lz[y],lz[ch[y][1]]+=lz[y],lz[y]=0;
	mn[x]=min(mn[x],mn[y]);
	ch[x][0]=merge(ch[x][0],ch[y][0]);
	ch[x][1]=merge(ch[x][1],ch[y][1]);
	return x;
}
long long que(int x,int l,int r,int l1,int r1)
{
	if(!x)return 1e17+1;
	if(l==l1&&r==r1)return mn[x];
	if(lz[x])mn[ch[x][0]]+=lz[x],mn[ch[x][1]]+=lz[x],lz[ch[x][0]]+=lz[x],lz[ch[x][1]]+=lz[x],lz[x]=0;
	int mid=(l+r)>>1;
	if(mid>=r1)return que(ch[x][0],l,mid,l1,r1);
	else if(mid<l1)return que(ch[x][1],mid+1,r,l1,r1);
	else return min(que(ch[x][0],l,mid,l1,mid),que(ch[x][1],mid+1,r,mid+1,r1));
}
void dfs2(int u,int fa)
{
	rt[u]=++ct;mn[ct]=1e17+1;
	long long su=0;int fg=0;
	for(int i=head[u];i;i=ed[i].next)
	if(ed[i].t!=fa)
	{
		dfs2(ed[i].t,u);
		mn[rt[ed[i].t]]-=vl[ed[i].t];lz[rt[ed[i].t]]-=vl[ed[i].t];su+=vl[ed[i].t];
		rt[u]=merge(rt[ed[i].t],rt[u]);
		fg=1;
	}
	mn[rt[u]]+=su,lz[rt[u]]+=su;
	int sz=tp[u].size();
	if(!fg)for(int i=0;i<sz;i++)ins(rt[u],1,n,dep[tp[u][i].t],tp[u][i].v);
	else
	{
		for(int i=0;i<sz;i++)
		{
			long long vl=que(rt[u],1,n,1,dep[u]);
			if(vl<1e17)ins(rt[u],1,n,dep[tp[u][i].t],tp[u][i].v+vl);
		}
	}
	vl[u]=que(rt[u],1,n,1,u==1?1:dep[u]-1);
	if(vl[u]>1e16){printf("-1\n");exit(0);}
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n==1){printf("0");return 0;}
	for(int i=1;i<n;i++)scanf("%d%d",&a,&b),adde(a,b);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a,&b,&c),tp[a].push_back((sth){b,c});
	dfs1(1,0);dfs2(1,0);
	printf("%lld\n",vl[1]>2e15?-1:vl[1]);
}