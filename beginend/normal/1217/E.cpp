#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ls d<<1
#define rs d<<1|1

const int N=200005;
const int inf=1000000000;

int n,m,sz,mn1,mn2,now;
struct tree{int mn1,mn2;}t[N*40];

void updata(int d)
{
	int id=d+now,l=(ls)+now,r=(rs)+now;
	t[id].mn1=t[l].mn1;t[id].mn2=t[l].mn2;
	if (t[r].mn1<t[id].mn1) t[id].mn2=t[id].mn1,t[id].mn1=t[r].mn1;
	else if (t[r].mn1<t[id].mn2) t[id].mn2=t[r].mn1;
	if (t[r].mn2<t[id].mn2) t[id].mn2=t[r].mn2;
}

void ins(int d,int l,int r,int x,int y)
{
	if (l==r) {t[d+now].mn1=y;t[d+now].mn2=inf;return;}
	int mid=(l+r)/2;
	if (x<=mid) ins(ls,l,mid,x,y);
	else ins(rs,mid+1,r,x,y);
	updata(d);
}

void query(int d,int l,int r,int x,int y)
{
	if (x<=l&&r<=y)
	{
		if (t[d+now].mn1<mn1) mn2=mn1,mn1=t[d+now].mn1;
		else if (t[d+now].mn1<mn2) mn2=t[d+now].mn1;
		if (t[d+now].mn2<mn2) mn2=t[d+now].mn2;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) query(ls,l,mid,x,y);
	if (y>mid) query(rs,mid+1,r,x,y);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		int y=x;
		for (int j=1;j<10;j++)
		{
			if (y%10) now=(j-1)*n*4,ins(1,1,n,i,x);
			else now=(j-1)*n*4,ins(1,1,n,i,inf);
			y/=10;
		}
	}
	while (m--)
	{
		int op;scanf("%d",&op);
		if (op==1)
		{
			int i,x;scanf("%d%d",&i,&x);
			int y=x;
			for (int j=1;j<10;j++)
			{
				if (y%10) now=(j-1)*n*4,ins(1,1,n,i,x);
				else now=(j-1)*n*4,ins(1,1,n,i,inf);
				y/=10;
			}
		}
		else
		{
			int l,r;scanf("%d%d",&l,&r);
			int ans=inf*2;
			for (int i=1;i<10;i++)
			{
				mn1=mn2=inf;
				now=(i-1)*n*4;query(1,1,n,l,r);
				if (mn2<inf) ans=std::min(ans,mn1+mn2);
			}
			if (ans<inf*2) printf("%d\n",ans);
			else puts("-1");
		}
	}
	return 0;
}