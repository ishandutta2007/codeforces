#include<cstdio>
#include<algorithm>
using namespace std;
struct ed{
	int l,r,mx,lazy,v;
}e[400004];
int n,cnt,m,ans[100001];
void build(int m,int l,int r)
{
	e[m].l=l;
	e[m].r=r;
	e[m].mx=e[m].lazy=0;
	if(l==r)
	{
		e[m].v=++cnt;
		return;
	}
	int mid=(l+r)>>1;
	build(m<<1,l,mid);
	build(m<<1|1,mid+1,r);
}
void push(int m,int l)
{
	e[m<<1].mx+=l;
	e[m<<1|1].mx+=l;
	e[m<<1].lazy+=l;
	e[m<<1|1].lazy+=l;
	e[m].lazy=0;
}
void add(int m,int l,int r,int ad)
{
	if(e[m].l==l&&e[m].r==r)
	{
		e[m].mx+=ad;
		e[m].lazy+=ad;
		return;
	}
	if(e[m].lazy)
	push(m,e[m].lazy);
	int mid=(e[m].l+e[m].r)>>1;
	if(mid>=r)
	add(m<<1,l,r,ad);
	else
	if(l>mid)
	add(m<<1|1,l,r,ad);
	else
	{
		add(m<<1,l,mid,ad);
		add(m<<1|1,mid+1,r,ad);
	}
	e[m].mx=max(e[m<<1].mx,e[m<<1|1].mx);
}
int query(int m)
{
	if(e[1].mx<=0)
	return -1;
	if(e[m].l==e[m].r)
	return e[m].v;
	if(e[m].lazy)
	push(m,e[m].lazy);
	if(e[m<<1|1].mx>0)
	return query(m<<1|1);
	else
	return query(m<<1);
}
int main()
{
	int a,b,c;
	scanf("%d",&n);
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(b==1)
		{
			scanf("%d",&c);
			ans[a]=c;
			add(1,1,a,1);
		}
		else
		add(1,1,a,-1);
		int y=query(1);
		if(y<0)
		printf("%d\n",y);
		else
		printf("%d\n",ans[y]);
	}
}