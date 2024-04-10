#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 1000005
using namespace std;

int n,m,c[N],a[N],sum[N],last[N];
struct data{int l,r,ans,id;}q[N];
struct hehe{int a,id;}b[N];

bool cmp(data a,data b)
{
	return a.r<b.r;
}

int lowbit(int x)
{
	return x&(-x);
}

void ins(int x,int y)
{
	if (!x) return;
	while (x<=n)
	{
		c[x]^=y;
		x+=lowbit(x);
	}
}

int find(int x)
{
	if (!x) return 0;
	int s=0;
	while (x)
	{
		s^=c[x];
		x-=lowbit(x);
	}
	return s;
}

bool cmp1(data a,data b)
{
	return a.id<b.id;
}

bool cmp2(hehe a,hehe b)
{
	return (a.a<b.a||a.a==b.a&&a.id<b.id);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i].a=a[i];b[i].id=i;
		sum[i]=sum[i-1]^a[i];
	}
	sort(b+1,b+n+1,cmp2);
	for (int i=2;i<=n;i++)
		if (b[i].a==b[i-1].a) last[b[i].id]=b[i-1].id;
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	int point=1;
	for (int i=1;i<=n;i++)
	{
		if (last[i]) ins(last[i],a[i]);
		ins(i,a[i]);
		while (q[point].r==i)
		{
			q[point].ans=find(q[point].r)^find(q[point].l-1)^sum[i]^sum[q[point].l-1];
			point++;
		}
		if (point>m) break;
	}
	sort(q+1,q+m+1,cmp1);
	for (int i=1;i<=m;i++)
		printf("%d\n",q[i].ans);
	return 0;
}