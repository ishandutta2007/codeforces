#include<cstdio>
#include<cstring>
typedef long long ll;
typedef double db;
#define lowbit(x) (x&(-x))
int n;
ll x,y;
int a[1111111];
inline ll min(ll x,ll y)
{return(x<y)?x:y;}
ll F[1111111];
ll t[1111111];
void add(int p,int d)
{
	for(register int i=p;i<=n;i+=lowbit(i))t[i]+=d;
}
ll qry(int p)
{
	ll r=0;
	for(register int i=p;i;i-=lowbit(i))r+=t[i];
	return r;
}
struct segt
{
	int l,r,siz;
	int tagx,tagy;
	ll sumx,sumy;
}tr[1111111];
void build(int l=1,int r=n,int p=1)
{
	tr[p].l=l,tr[p].r=r,tr[p].siz=1;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(l,mid,p<<1),build(mid+1,r,p<<1|1);
	tr[p].siz=tr[p<<1].siz+tr[p<<1|1].siz; 
}
void pushd(int p)
{
	tr[p<<1].tagx+=tr[p].tagx;
	tr[p<<1|1].tagx+=tr[p].tagx;
	tr[p<<1].tagy+=tr[p].tagy;
	tr[p<<1|1].tagy+=tr[p].tagy;
	tr[p<<1].sumx+=tr[p<<1].siz*1ll*tr[p].tagx;
	tr[p<<1|1].sumx+=tr[p<<1|1].siz*1ll*tr[p].tagx;
	tr[p<<1].sumy+=tr[p<<1].siz*1ll*tr[p].tagy;
	tr[p<<1|1].sumy+=tr[p<<1|1].siz*1ll*tr[p].tagy;
	tr[p].tagx=tr[p].tagy=0;
}
void erase(int x,int p=1)
{
	if(tr[p].r<x||tr[p].l>x)return;
	if(tr[p].l==tr[p].r)return(void)(tr[p].siz=tr[p].sumx=tr[p].sumy=0);
	pushd(p),erase(x,p<<1),erase(x,p<<1|1);
	tr[p].siz=tr[p<<1].siz+tr[p<<1|1].siz;
	tr[p].sumx=tr[p<<1].sumx+tr[p<<1|1].sumx;
	tr[p].sumy=tr[p<<1].sumy+tr[p<<1|1].sumy;
}
void modify(int l,int r,int d,int typ,int p=1)
{
	if(l>r||tr[p].r<l||tr[p].l>r)return;
	if(l<=tr[p].l&&tr[p].r<=r)
	{
		if(typ==0)tr[p].sumx+=d*1ll*tr[p].siz,tr[p].tagx+=d;
		else tr[p].sumy+=d*1ll*tr[p].siz,tr[p].tagy+=d;
		return;
	}pushd(p),modify(l,r,d,typ,p<<1),modify(l,r,d,typ,p<<1|1);
}
ll getsum(int l,int r,int typ,int p=1)
{
	if(l>r||tr[p].r<l||tr[p].l>r)return 0;
	if(l<=tr[p].l&&tr[p].r<=r)
	{
		if(typ==0)return tr[p].sumx;
		if(typ==1)return tr[p].sumy;
	}return pushd(p),getsum(l,r,typ,p<<1)+getsum(l,r,typ,p<<1|1);
}
int r[1111111];
void exec()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]),r[a[i]]=i;
	for(i=1;i<=n;i++)
	F[i]=F[i-1]+i-qry(r[i])-1,
	add(r[i],1);
	build();
	for(i=1;i<=n;i++)t[i]=0;
	for(i=1;i<=n;i++)
	{
		int p=r[i];
		modify(p+1,n,1,0);
		modify(1,p-1,1,1);
		erase(p);
		add(p,1);
		int l=0,r=n+1;
		while(l+1<r)
		{
			int mid=(l+r)>>1;
			if(qry(mid)<=(i>>1))l=mid;
			else r=mid;
		}//printf("%d %d %d\n",l,getsum(1,l,0),getsum(l+1,n,1));
		F[i]+=getsum(1,l,0)+getsum(l+1,n,1);
	}for(i=1;i<=n;i++)printf("%I64d ",F[i]);
	puts("");
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}
/*
All things passing through, leaving me behind.
Where is your fighting heart, std?
*/