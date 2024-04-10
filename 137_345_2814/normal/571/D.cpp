#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000050
int head[N],cnt,fa[N],id2[N],id[N],ct,ct2,ct3,q[N][2],lb[N],rb[N],n,m,a,b,is[N],vis[N];
char s[2],t[N];
long long as[N],tr[N];
struct que{int t,x,id,s;friend bool operator <(que a,que b){return a.t<b.t;}}r[N];
struct edge{int t,next;}ed[N];
int finds(int x){return fa[x]==x?x:fa[x]=finds(fa[x]);}
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
void dfs(int u,int fa){vis[u]=1;if(u<=n)id[u]=++ct3;for(int i=head[u];i;i=ed[i].next)if(ed[i].t!=fa)dfs(ed[i].t,u);}
struct segt{int l,r,lz;}e[N*2];
void pushdown(int x){e[x<<1].lz=max(e[x].lz,e[x<<1].lz);e[x<<1|1].lz=max(e[x].lz,e[x<<1|1].lz);}
void build(int x,int l,int r){e[x].l=l;e[x].r=r;if(l==r)return;int mid=(l+r)>>1;build(x<<1,l,mid);build(x<<1|1,mid+1,r);}
void modify(int x,int l,int r,int s){if(e[x].l==l&&e[x].r==r){e[x].lz=s;return;}pushdown(x);int mid=(e[x].l+e[x].r)>>1;if(mid>=r)modify(x<<1,l,r,s);else if(mid<l)modify(x<<1|1,l,r,s);else modify(x<<1,l,mid,s),modify(x<<1|1,mid+1,r,s);}
int query(int x,int s){if(e[x].l==e[x].r)return e[x].lz;pushdown(x);int mid=(e[x].l+e[x].r)>>1;if(mid>=s)return query(x<<1,s);else return query(x<<1|1,s);}
void add(int x,int v){for(int i=x;i<=n;i+=i&-i)tr[i]+=v;}
long long que1(int x){long long as=0;for(int i=x;i;i-=i&-i)as+=tr[i];return as;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s%d",s,&a);
		if(s[0]=='U'||s[0]=='M')scanf("%d",&b);else b=0;
		q[i][0]=a;q[i][1]=b;t[i]=s[0];
	}
	for(int i=1;i<=n;i++)id2[i]=i,fa[i]=i;
	ct2=n;
	for(int i=1;i<=m;i++)if(t[i]=='M')
	{
		int ta=finds(q[i][0]),tb=finds(q[i][1]);
		int st=++ct2;
		adde(st,id2[ta]);adde(st,id2[tb]);
		id2[ta]=st;fa[tb]=ta;
	}
	for(int i=ct2;i>=1;i--)if(!vis[i])dfs(i,0);build(1,1,n);
	for(int i=1;i<=n;i++)lb[i]=rb[i]=id[i];
	for(int i=1;i<=m;i++)
	if(t[i]=='M')
	{
		if(lb[q[i][0]]<lb[q[i][1]])rb[q[i][0]]=rb[q[i][1]];
		else lb[q[i][0]]=lb[q[i][1]];
	}
	else if(t[i]=='Z')modify(1,lb[q[i][0]],rb[q[i][0]],i);
	else if(t[i]=='Q')
	{
		is[i]=1;
		int ti=query(1,id[q[i][0]]);
		r[++ct]=(que){i,q[i][0],i,1};
		r[++ct]=(que){ti-1,q[i][0],i,-1};
	}
	for(int i=1;i<=ct2;i++)vis[i]=0,head[i]=0;
	for(int i=1;i<=n;i++)id2[i]=i,fa[i]=i;
	ct2=n;ct3=0;cnt=0;
	for(int i=1;i<=m;i++)if(t[i]=='U')
	{
		int ta=finds(q[i][0]),tb=finds(q[i][1]);
		int st=++ct2;
		adde(st,id2[ta]);adde(st,id2[tb]);
		id2[ta]=st;fa[tb]=ta;
	}
	for(int i=ct2;i>=1;i--)if(!vis[i])dfs(i,0);
	for(int i=1;i<=n;i++)lb[i]=rb[i]=id[i];
	int st=1;
	sort(r+1,r+ct+1);
	while(r[st].t<1)st++;
	for(int i=1;i<=m;i++)
	{
		if(t[i]=='U')
		{
			if(lb[q[i][0]]<lb[q[i][1]])rb[q[i][0]]=rb[q[i][1]];
			else lb[q[i][0]]=lb[q[i][1]];
		}
		else if(t[i]=='A')
		{
			int st=rb[q[i][0]]-lb[q[i][0]]+1;
			add(lb[q[i][0]],st);
			add(rb[q[i][0]]+1,-st);
		}
		while(r[st].t==i&&st<=ct)
		as[r[st].id]+=que1(id[r[st].x])*r[st].s,st++;
	}
	for(int i=1;i<=m;i++)if(is[i])printf("%lld\n",as[i]);
}