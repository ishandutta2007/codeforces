#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 100005
#define MAXN 1000000000
using namespace std;

int n,m,Q,sz,root,gro[N],r[N],a[N];
struct people{int a,r;}peo[N];
struct query{int id,l,r,val,ans;}q[N];
struct tree{int l,r,s;}t[N*30];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

bool cmpr(people a,people b)
{
	return a.r<b.r;
}

bool cmpval(query a,query b)
{
	return a.val<b.val;
}

bool cmpid(query a,query b)
{
	return a.id<b.id;
}

void ins(int &d,int l,int r,int x)
{
	if (!d) d=++sz;
	t[d].s++;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) ins(t[d].l,l,mid,x);
	else ins(t[d].r,mid+1,r,x);
}

int find(int d,int l,int r,int x,int y)
{
	if (!d) return 0;
	if (l==x&&r==y) return t[d].s;
	int mid=(l+r)/2;
	if (y<=mid) return find(t[d].l,l,mid,x,y);
	else if (x>mid) return find(t[d].r,mid+1,r,x,y);
	else return find(t[d].l,l,mid,x,mid)+find(t[d].r,mid+1,r,mid+1,y);
}

void ins1(int &d,int l,int r,int x,int y)
{
	if (!d)
	{
		d=++sz;
		t[d].l=t[d].r=t[d].s=0;
	}
	t[d].s=max(t[d].s,y);
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) ins1(t[d].l,l,mid,x,y);
	else ins1(t[d].r,mid+1,r,x,y);
}

int query(int d,int l,int r,int x,int y)
{
	if (!d) return 0;
	if (l==x&&r==y) return t[d].s;
	int mid=(l+r)/2;
	if (y<=mid) return query(t[d].l,l,mid,x,y);
	else if (x>mid) return query(t[d].r,mid+1,r,x,y);
	else return max(query(t[d].l,l,mid,x,mid),query(t[d].r,mid+1,r,mid+1,y));
}

int main()
{
	//freopen("c.in","r",stdin);freopen("c.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++)
		peo[i].r=r[i]=read();
	for (int i=1;i<=n;i++)
		peo[i].a=a[i]=read();
	sort(peo+1,peo+n+1,cmpr);
	int now=1;
	while (now<=n)
	{
		int tail=now;
		while (tail<n&&peo[tail+1].r==peo[tail].r) tail++;
		for (int i=now;i<=tail;i++)
			ins(root,1,MAXN,peo[i].a);
		for (int i=now;i<=tail;i++)
			gro[i]=find(root,1,MAXN,max(1,peo[i].a-m),min(MAXN,peo[i].a+m));
		now=tail+1;
	}
	Q=read();
	for (int i=1;i<=Q;i++)
	{
		int x=read(),y=read();
		if (a[x]>a[y]) swap(x,y);
		q[i].val=max(r[x],r[y]);q[i].l=a[y]-m;q[i].r=a[x]+m;q[i].id=i;
	}
	sort(q+1,q+Q+1,cmpval);
	int now1=n,now2=Q;
	sz=root=0;
	while (now2>0)
	{
		while (now1>0&&peo[now1].r>=q[now2].val)
		{
			ins1(root,1,MAXN,peo[now1].a,gro[now1]);
			now1--;
		}
		while (now2>0&&(q[now2].val>peo[now1].r||!now1))
		{
			q[now2].ans=query(root,1,MAXN,q[now2].l,q[now2].r);
			now2--;
		}
	}
	sort(q+1,q+Q+1,cmpid);
	for (int i=1;i<=Q;i++)
	{
		if (q[i].ans==0) q[i].ans=-1;
		printf("%d\n",q[i].ans);
	}
	return 0;
}