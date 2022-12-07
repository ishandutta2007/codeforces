#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int Maxn=100010;
const int inf=2147483647;
const double eps=1e-8;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
struct Edge{int y,next;}e[Maxn<<1];
int last[Maxn],len=1;
void ins(int x,int y)
{
	int t=++len;
	e[t].y=y;e[t].next=last[x];last[x]=t;
}
int n,L[Maxn],R[Maxn],fa[Maxn],deg[Maxn],id[Maxn],tt;bool vis[Maxn];double p[Maxn],V[Maxn];
double sum=0,sum1=0;
void bfs()
{
	queue<int>q;q.push(1);tt=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();vis[x]=true;
		deg[x]=1;
		if(x==1)deg[x]=0;
		for(int i=last[x];i;i=e[i].next)
		{
			int y=e[i].y;
			if(vis[y])continue;
			deg[x]++;
			id[y]=++tt;L[x]=min(L[x],tt);R[x]=max(R[x],tt);
			V[tt]=p[y];fa[y]=x;sum1+=(1.0-p[x])*(1.0-p[y]);
			q.push(y);
		}
	}
}
struct Seg{int l,r,lc,rc;double c,tag;}tr[Maxn<<1];
int trlen=0;
void up(int x)
{
	int lc=tr[x].lc,rc=tr[x].rc;
	tr[x].c=tr[lc].c+tr[rc].c;
}
void build(int l,int r)
{
	if(l>r)return;
	int t=++trlen;
	tr[t].l=l;tr[t].r=r;
	if(l==r)
	{
		tr[t].c=V[l];
		return ;
	}
	int mid=l+r>>1;
	tr[t].lc=trlen+1,build(l,mid);
	tr[t].rc=trlen+1,build(mid+1,r);
	up(t);
}
void add(int x,int p,double v)
{
	if(tr[x].l==tr[x].r)
	{
		tr[x].c=v;
		return ;
	}
	int lc=tr[x].lc,rc=tr[x].rc,mid=tr[x].l+tr[x].r>>1;
	if(p<=mid)add(lc,p,v);
	else add(rc,p,v);
	up(x);
}
double query(int x,int l,int r)
{
//	printf("%d %d\n",l,r);
	if(l>n)return 0.0;
	if(tr[x].l==l&&tr[x].r==r)return tr[x].c;
	int lc=tr[x].lc,rc=tr[x].rc,mid=tr[x].l+tr[x].r>>1;
	if(r<=mid)return query(lc,l,r);
	if(l>mid)return query(rc,l,r);
	return query(lc,l,mid)+query(rc,mid+1,r);
}
int main()
{
	memset(L,63,sizeof(L));
	memset(R,0,sizeof(R));
	n=read();
	for(int i=1;i<=n;i++)scanf("%lf",&p[i]),sum+=(1.0-p[i]);
	for(int i=1;i<n;i++)
	{
		int x=read()+1,y=read()+1;
		ins(x,y),ins(y,x);
	}
	bfs();
//	printf("%.5lf %.5lf %.5lf\n",sum-sum1,sum,sum1);
//	for(int i=1;i<=n;i++)printf("%d %d %d %d\n",i,id[i],L[i],R[i]);
	int q=read();
	fa[1]=0;p[0]=0.0;
	build(1,tt);
	while(q--)
	{
		int x=read()+1;double P;
//		puts("ok1");

		double tmp=query(1,L[x],R[x])+p[fa[x]];
//		printf("%d %d %d %d\n",x,L[x],R[x],deg[x]);
//		printf("%.4lf \n",tmp);
//		puts("ok2");

		scanf("%lf",&P);
		sum-=(1.0-p[x]);
		sum1+=(double)deg[x]*p[x];
		sum1-=p[x]*tmp;
		
		p[x]=P;
		
		sum+=(1.0-p[x]);
		sum1-=(double)deg[x]*p[x];
		sum1+=p[x]*tmp;
		if(x!=1)add(1,id[x],p[x]);
		
//		printf("%.5lf %.5lf\n",sum,sum1);
		
		printf("%.5lf\n",sum-sum1);
	}
}