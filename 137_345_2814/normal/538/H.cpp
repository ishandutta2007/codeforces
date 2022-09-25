#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define N 300050
int l,r,n,m,lb[N],rb[N],head[N],col[N],is[2],sb[2][2],s[N],s2[N],ct,ct2,a,b,ct3,cnt,as[N];
struct edge{int t,next;}ed[N*2];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
map<long long,int> tp;
struct line{int l,r;friend bool operator <(line a,line b){return a.l<b.l;}}t[N],t2[N];
struct node{int l,r,l1,r1,lz,rz;}e[N*4];
void pushdown(int x){if(e[x].lz>0)e[x<<1].lz=max(e[x<<1].lz,e[x].lz),e[x<<1].rz=min(e[x<<1].rz,e[x].rz),e[x<<1].l1=max(e[x<<1].l1,e[x].lz),e[x<<1].r1=min(e[x<<1].r1,e[x].rz),
e[x<<1|1].lz=max(e[x<<1|1].lz,e[x].lz),e[x<<1|1].rz=min(e[x<<1|1].rz,e[x].rz),e[x<<1|1].l1=max(e[x<<1|1].l1,e[x].lz),e[x<<1|1].r1=min(e[x<<1|1].r1,e[x].rz),e[x].lz=-1e9,e[x].rz=1e9;}
struct sth{int l,r;};
void build(int x,int l,int r)
{
	e[x].l1=e[x].lz=-1e9;
	e[x].r1=e[x].rz=1e9;
	e[x].l=l;e[x].r=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
}
void modify(int x,int l,int r,int l1,int r1)
{
	if(e[x].l==l&&e[x].r==r){e[x].lz=max(e[x].lz,l1);e[x].rz=min(e[x].rz,r1);e[x].l1=max(e[x].l1,l1);e[x].r1=min(e[x].r1,r1);return;}
	pushdown(x);
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)modify(x<<1,l,r,l1,r1);
	else if(mid<l)modify(x<<1|1,l,r,l1,r1);
	else modify(x<<1,l,mid,l1,r1),modify(x<<1|1,mid+1,r,l1,r1);
}
sth query(int x,int s)
{
	if(e[x].l==e[x].r)return (sth){e[x].l1,e[x].r1};
	pushdown(x);
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=s)return query(x<<1,s);
	else return query(x<<1|1,s);
}
void dfs(int x)
{
	is[col[x]]=1;
	sb[col[x]][0]=max(sb[col[x]][0],lb[x]);
	sb[col[x]][1]=min(sb[col[x]][1],rb[x]);
	for(int i=head[x];i;i=ed[i].next)
	{
		if(col[ed[i].t]==-1)col[ed[i].t]=!col[x],dfs(ed[i].t);
		else if(col[ed[i].t]==col[x]){printf("IMPOSSIBLE\n");exit(0);}
	}
}
void dfs2(int x)
{
	col[x]=-1;as[x]=1;
	for(int i=head[x];i;i=ed[i].next)
	if(col[ed[i].t]!=-1)dfs2(ed[i].t);
}
int main()
{
	scanf("%d%d%d%d",&l,&r,&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&lb[i],&rb[i]),s[++ct]=lb[i],s[++ct]=rb[i],s[++ct]=rb[i]+1;
	for(int i=1;i<=m;i++)scanf("%d%d",&a,&b),adde(a,b);
	if(m==0)
	{
		int mn=-1e9,mx=1e9;
		for(int i=1;i<=n;i++)mn=max(mn,lb[i]),mx=min(mx,rb[i]);
		if(mn<=mx&&mn<=r)
		{
			printf("POSSIBLE\n");
			printf("%d %d\n",mn,r-mn);
			for(int i=1;i<=n;i++)printf("1");
			return 0;
		}
	}
	for(int i=1;i<=n;i++)col[i]=-1;
	sort(s+1,s+ct+1);s[0]=-1;
	for(int i=1;i<=ct;i++)if(s[i]!=s[i-1])s2[++ct2]=s[i],tp[s[i]]=ct2;
	build(1,1,ct2);
	for(int i=1;i<=n;i++)if(col[i]==-1)
	{
		is[0]=is[1]=0;sb[0][0]=sb[1][0]=-1e9;
		sb[0][1]=sb[1][1]=1e9;
		col[i]=0;dfs(i);
		if(!is[1])t[++ct3]=(line){tp[sb[0][0]],tp[sb[0][1]]};
		else
		{
			int l1=tp[sb[0][0]],r1=tp[sb[0][1]],l2=tp[sb[1][0]],r2=tp[sb[1][1]];
			if(l1>r1||l2>r2){printf("IMPOSSIBLE\n");exit(0);}
			if(r1<l2)
			{
				if(l1>1)modify(1,1,l1-1,1e9,-1e9);
				if(l1<=r1)modify(1,l1,r1,l2,r2);
				if(tp[s2[r1]+1]<l2)modify(1,tp[s2[r1]+1],l2-1,1e9,-1e9);
				if(l2<=r2)modify(1,l2,r2,l1,r1);
				modify(1,tp[s2[r2]+1],ct2,1e9,-1e9);
			}
			else if(r2<l1)
			{
				l1^=l2^=l1^=l2;r1^=r2^=r1^=r2;
				if(l1>1)modify(1,1,l1-1,1e9,-1e9);
				if(l1<=r1)modify(1,l1,r1,l2,r2);
				if(tp[s2[r1]+1]<l2)modify(1,tp[s2[r1]+1],l2-1,1e9,-1e9);
				if(l2<=r2)modify(1,l2,r2,l1,r1);
				modify(1,tp[s2[r2]+1],ct2,1e9,-1e9);
			}
			else
			{
				if(l1>l2)l1^=l2^=l1^=l2,r1^=r2^=r1^=r2;
				if(l1>1)modify(1,1,l1-1,1e9,-1e9);
				if(l1<l2)modify(1,l1,l2-1,l2,r2);
				if(r1<=r2)
				{
					if(l2<=r1)modify(1,l2,r1,l1,r2);
					if(r1<r2)modify(1,r1+1,r2,l1,r1);
					if(r2<ct2)modify(1,r2+1,ct2,1e9,-1e9);
				}
				else
				{
					if(l2<=r2)modify(1,l2,r2,l1,r1);
					if(r2<r1)modify(1,r2+1,r1,l2,r2);
					if(r1<ct2)modify(1,r1+1,ct2,1e9,-1e9);
				}
			}
		}
	}
	if(ct3)sort(t+1,t+ct3+1);
	t2[ct3]=t[ct3];
	for(int i=ct3-1;i>=1;i--)t2[i]=(line){max(t2[i+1].l,t[i].l),min(t2[i+1].r,t[i].r)};
	int mx=tp[s2[t2[1].r]+1],st=1;
	if(!ct3)mx=ct2;
	for(int i=1;i<mx;i++)
	{
		int lb=s2[i],rb=s2[i+1]-1,lb1,rb1;
		sth t1=query(1,i);
		if(t1.l>t1.r)continue;
		if(t1.l<=-1e8)lb1=-1e9,rb1=1e9;
		else lb1=s2[t1.l],rb1=s2[t1.r];
		while(st<=ct3&&t[st].l<=i)st++;
		if(st<=ct3)lb1=max(lb1,s2[t2[st].l]),rb1=min(rb1,s2[t2[st].r]);
		lb1=max(lb1,l-rb);rb1=min(rb1,r-lb);
		if(lb1>rb1||rb1<0)continue;
		printf("POSSIBLE\n");
		int ar=lb1,al=min(rb,r-lb1);
		printf("%d %d\n",al,ar);
		for(int j=1;j<=n;j++)if(!as[j])
		{
			is[0]=is[1]=0;sb[0][0]=sb[1][0]=-1e9;
			sb[0][1]=sb[1][1]=1e9;
			dfs2(j);
			col[j]=0;dfs(j);
			if(!(al>=sb[0][0]&&al<=sb[0][1]&&ar>=sb[1][0]&&ar<=sb[1][1]))dfs2(j),col[j]=1,dfs(j);
		}
		for(int i=1;i<=n;i++)printf("%d",col[i]+1);
		return 0;
	}
	printf("IMPOSSIBLE\n");
}//.......................