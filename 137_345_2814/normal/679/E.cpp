#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100500
#define ll long long
ll s[15]={1,42,1764,74088,3111696,130691232,5489031744ll,230539333248ll,9682651996416ll,406671383849472ll,17080198121677824ll};
int n,m,v[N],a,b,c,d;
struct segt{long long lz1,lz2,nt;int l,r;}e[N*4];
long long getnt(long long v){int lb=1,rb=10,as=-1;while(lb<=rb){int mid=(lb+rb)>>1;if(s[mid]>=v)as=mid,rb=mid-1;else lb=mid+1;}return as==-1?1e18:s[as]-v;}
void pushdown(int x)
{
	if(e[x].lz2)
	{
		e[x<<1].lz2=e[x<<1|1].lz2=e[x].lz2;
		e[x<<1].lz1=e[x<<1|1].lz1=0;
		e[x<<1].nt=e[x<<1|1].nt=e[x].nt;
		e[x].lz2=0;
	}
	if(e[x].lz1)
	{
		e[x<<1].nt-=e[x].lz1,e[x<<1|1].nt-=e[x].lz1;
		if(e[x<<1].lz2)e[x<<1].lz2+=e[x].lz1;else e[x<<1].lz1+=e[x].lz1;
		if(e[x<<1|1].lz2)e[x<<1|1].lz2+=e[x].lz1;else e[x<<1|1].lz1+=e[x].lz1;
		e[x].lz1=0;
	}
}
void pushup(int x){e[x].nt=min(e[x<<1].nt,e[x<<1|1].nt);}
void build(int x,int l,int r)
{
	e[x].l=l;e[x].r=r;
	if(l==r){e[x].lz1=v[l];e[x].nt=getnt(v[l]);return;}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);build(x<<1|1,mid+1,r);
	pushup(x);
}
long long query(int x,int s)
{
	if(e[x].lz2)return e[x].lz2;
	if(e[x].l==e[x].r)return e[x].lz1;
	pushdown(x);
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=s)return query(x<<1,s);
	else return query(x<<1|1,s);
}
void modify(int x,int l,int r,int s)
{
	if(e[x].l==l&&e[x].r==r){e[x].lz1=0;e[x].lz2=s;e[x].nt=getnt(s);return;}
	int mid=(e[x].l+e[x].r)>>1;
	pushdown(x);
	if(mid>=r)modify(x<<1,l,r,s);
	else if(mid<l)modify(x<<1|1,l,r,s);
	else modify(x<<1,l,mid,s),modify(x<<1|1,mid+1,r,s);
	pushup(x);
}
void modify2(int x,int l,int r,int s)
{
	if(e[x].lz2&&(e[x].l==l&&e[x].r==r)){e[x].lz2+=s;e[x].nt=getnt(e[x].lz2);return;}
	if(e[x].nt>=s&&(e[x].l==l&&e[x].r==r)){e[x].lz1+=s;e[x].nt-=s;return;}
	if(e[x].l==e[x].r){e[x].lz1+=s;e[x].nt=getnt(e[x].lz1);return;}
	pushdown(x);
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)modify2(x<<1,l,r,s);
	else if(mid<l)modify2(x<<1|1,l,r,s);
	else modify2(x<<1,l,mid,s),modify2(x<<1|1,mid+1,r,s);
	pushup(x);
}
long long query2(int x,int l,int r)
{
	if(e[x].lz2)return e[x].nt;
	if(e[x].l==l&&e[x].r==r)return e[x].nt;
	pushdown(x);
	int mid=(e[x].l+e[x].r)>>1;
	if(mid>=r)return query2(x<<1,l,r);
	else if(mid<l)return query2(x<<1|1,l,r);
	else return min(query2(x<<1,l,mid),query2(x<<1|1,mid+1,r));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	build(1,1,n);
	while(m--)
	{
		scanf("%d",&a);
		if(a==1)scanf("%d",&b),printf("%lld\n",query(1,b));
		else if(a==2)scanf("%d%d%d",&b,&c,&d),modify(1,b,c,d);
		else{scanf("%d%d%d",&b,&c,&d);modify2(1,b,c,d);while(query2(1,b,c)==0)modify2(1,b,c,d);}
	}
}