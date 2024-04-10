#include<cstdio>
using namespace std;
struct edge{
	long long l,r,ans,lazy,v;
}e[400044];
int n,m;
int ABS(int a) {return a>0?a:-a;}
void pushup(int m)
{
	if(e[m<<1].v==0||e[m<<1|1].v==0||e[m<<1].v!=e[m<<1|1].v)
	e[m].v=0;
	else
	e[m].v=e[m<<1].v;
	e[m].ans=e[m<<1].ans+e[m<<1|1].ans;
}
void push(int m)
{
	e[m<<1].ans+=e[m].lazy*(e[m<<1].r-e[m<<1].l+1);
	e[m<<1|1].ans+=e[m].lazy*(e[m<<1|1].r-e[m<<1|1].l+1);
	e[m<<1|1].lazy+=e[m].lazy;
	e[m<<1].lazy+=e[m].lazy;
	e[m<<1].v=e[m<<1|1].v=e[m].v;
	e[m].lazy=0;
}
void build(int m,int l,int r)
{
	e[m].l=l;
	e[m].r=r;
	if(l==r)
	{
		e[m].v=l;
		e[m].ans=e[m].lazy=0;
		return;
	}
	int mid=(l+r)>>1;
	build(m<<1,l,mid);
	build(m<<1|1,mid+1,r);
	return;
}
void add(int m,int l,int r,int d)
{
	if(e[m].l==l&&e[m].r==r&&e[m].v)
	{
		e[m].lazy+=ABS(e[m].v-d);
		e[m].ans+=ABS(e[m].v-d)*(e[m].r-e[m].l+1);
		e[m].v=d;
		return;
	}
	if(e[m].l==e[m].r)
	return;
	if(e[m].lazy)
	push(m);
	int mid=(e[m].l+e[m].r)>>1;
	if(l>mid)
    add(m<<1|1,l,r,d);
    else
    if(r<=mid)
    add(m<<1,l,r,d);
    else
    {
        add(m<<1,l,mid,d);
        add(m<<1|1,mid+1,r,d);
    }
    pushup(m);
}
long long que(int m,int l,int r)
{
	if(e[m].l==l&&e[m].r==r)
	return e[m].ans;
	long long as=0;
	if(e[m].l==e[m].r)
	return 0;
	if(e[m].lazy)
	push(m);
	int mid=(e[m].l+e[m].r)>>1;
	if(l>mid)
    as+=que(m<<1|1,l,r);
    else
    if(r<=mid)
    as+=que(m<<1,l,r);
    else
    {
        as+=que(m<<1,l,mid);
        as+=que(m<<1|1,mid+1,r);  
    }
    pushup(m);
    return as;
}
int main()
{
	int a,b,c,d;
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			scanf("%d",&d);
			add(1,b,c,d);
		}
		else
		printf("%lld\n",que(1,b,c));
	}
}
//wen_krdalao