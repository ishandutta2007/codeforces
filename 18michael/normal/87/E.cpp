#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,n1,t,t1,res,q;
struct aaa
{
	int x,y;
	inline bool operator < (const aaa &a) const
	{
		return x==a.x? (y>a.y):(x<a.x);
	}
}A[150002],B[50002],tmp[150002];
set<aaa> sd,su;
set<aaa>::iterator it,it1;
inline aaa mns(aaa a,aaa b)
{
	return (aaa){a.x-b.x,a.y-b.y};
}
inline LL cross(aaa a,aaa b)
{
	return (LL)a.x*b.y-(LL)a.y*b.x;
}
inline bool cmp(aaa a,aaa b)
{
	return atan2(a.x,a.y)<atan2(b.x,b.y);
}
inline void maintain(aaa A[],int n)
{
	res=0;
	for(int i=1;i<n;++i)if(A[i]<A[res])res=i;
	for(int i=0;i<n;++i)tmp[i]=A[(i+res)%n];
	for(int i=0;i<n;++i)A[i]=tmp[i];
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d%d",&A[i].x,&A[i].y);
	maintain(A,n),A[n]=A[0];
	for(int i=n;i;--i)A[i].x-=A[i-1].x,A[i].y-=A[i-1].y;
	for(int o=0;o<2;++o)
	{
		scanf("%d",&n1),t=t1=1;
		for(int i=0;i<n1;++i)scanf("%d%d",&B[i].x,&B[i].y);
		maintain(B,n1),B[n1]=B[0];
		for(int i=n1;i;--i)B[i].x-=B[i-1].x,B[i].y-=B[i-1].y;
		A[0].x+=B[0].x,A[0].y+=B[0].y;
		for(int i=1;i<=n;++i)tmp[i]=A[i];
		for(;t<=n && t1<=n1;)
		{
			if(atan2(tmp[t].x,tmp[t].y)>atan2(B[t1].x,B[t1].y))A[t+t1-1]=tmp[t],++t;
			else A[t+t1-1]=B[t1],++t1;
		}
		for(;t<=n;)A[t+t1-1]=tmp[t],++t;
		for(;t1<=n1;)A[t+t1-1]=B[t1],++t1;
		n+=n1;
	}
	for(int i=1;i<=n;++i)A[i].x+=A[i-1].x,A[i].y+=A[i-1].y;
	t=inf,t1=-inf;
	for(int i=0;i<n;++i)t=min(t,A[i].x),t1=max(t1,A[i].x);
	for(int i=0;i<n;++i)
		if(A[i+1].x!=t)
		{
			for(;i<n && A[i-1].x<t1;++i)sd.insert(A[i]);
			for(--i;i+1<n && A[i+1].x==t1;++i);
			for(;i<=n;++i)su.insert(A[i]);
			break;
		}
	scanf("%d",&q);
	for(int i=0,x,y;i<q;++i)
	{
		scanf("%d%d",&x,&y),x*=3,y*=3;
		if(x<t || x>t1)
		{
			puts("NO");
			continue;
		}
		if(x==t)
		{
			puts((*sd.begin()).y<=y && y<=(*su.begin()).y? "YES":"NO");
			continue;
		}
		if(x==t1)
		{
			puts((*(--sd.end())).y<=y && y<=(*(--su.end())).y? "YES":"NO");
			continue;
		}
		it=su.lower_bound((aaa){x,inf});
		if((*it).x==x)
		{
			if((*it).y<y)
			{
				puts("NO");
				continue;
			}
		}
		else
		{
			--(it1=it);
			if(cross(mns(*it1,(aaa){x,y}),mns(*it,(aaa){x,y}))>0)
			{
				puts("NO");
				continue;
			}
		}
		it=sd.lower_bound((aaa){x,inf});
		if((*it).x==x)
		{
			if((*it).y>y)
			{
				puts("NO");
				continue;
			}
		}
		else
		{
			--(it1=it);
			if(cross(mns(*it1,(aaa){x,y}),mns(*it,(aaa){x,y}))<0)
			{
				puts("NO");
				continue;
			}
		}
		puts("YES");
	}
	return 0;
}