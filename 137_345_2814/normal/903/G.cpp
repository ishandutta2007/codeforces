#include<cstdio>
#include<algorithm>
using namespace std;
#define N 300100
long long a[N],b[N],ans[N],n,m,q,x,y;
struct s{int f,t,v;}ed[N];
bool cmp(s a,s b){return a.f>b.f;}
struct edge{int l,r;long long lazy,mn;}e[N*4];
inline void pushup(int x){e[x].mn=min(e[x<<1].mn,e[x<<1|1].mn);}
inline void pushdown(int x){e[x<<1].mn+=e[x].lazy;e[x<<1|1].mn+=e[x].lazy;e[x<<1].lazy+=e[x].lazy;e[x<<1|1].lazy+=e[x].lazy;e[x].lazy=0;}
void build(int x,int l,int r)
{
	e[x].l=l;
	e[x].r=r;
	e[x].lazy=0;
	if(l==r)
	{
		e[x].lazy=0;e[x].mn=b[l];
		e[x<<1].mn=e[x<<1|1].mn=b[l];
		return;
	}
	int mid=(e[x].l+e[x].r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	pushup(x);
}
void add(int x,int l,int r,long long v)
{
	if(e[x].l==l&&e[x].r==r)
	{
		e[x].lazy+=v;
		e[x].mn+=v;
		return;
	}
	pushdown(x);
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)
	add(x<<1,l,r,v);
	else
	if(mid<l)
	add(x<<1|1,l,r,v);
	else
	add(x<<1,l,mid,v),add(x<<1|1,mid+1,r,v);
	pushup(x);
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<n;i++)
	scanf("%lld%lld",&a[i],&b[i]);
	build(1,0,n-1);
	for(int i=1;i<=m;i++)
	scanf("%lld%lld%lld",&ed[i].f,&ed[i].t,&ed[i].v);
	sort(ed+1,ed+m+1,cmp);
	int nt=m;
	for(int i=1;i<=n;i++)
	{
		while(ed[nt].f==i)add(1,0,ed[nt].t-1,ed[nt].v),nt--;
		ans[i]=e[1].mn;
	}
	for(int i=1;i<=n;i++)
	b[i]=ans[i]+a[i];
	build(1,1,n);
	printf("%lld\n",e[1].mn);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&x,&y);
		add(1,x,x,y-a[x]);a[x]=y;
		printf("%lld\n",e[1].mn);
	}
}//STo lsj Orz