#include<bits/stdc++.h>
using namespace std;
const int N=1000005,M=998244353,E=2097152;
int n,q,i,a[N],lazy[N*4],mn[N*4],mnn[N*4],x,y;
void pushup(int i)
{
	mn[i]=min(mn[i<<1],mn[i<<1|1]);
	mnn[i]=0;
	if(mn[i]==mn[i<<1])
		mnn[i]+=mnn[i<<1];
	if(mn[i]==mn[i<<1|1])
		mnn[i]+=mnn[i<<1|1];
	mn[i]+=lazy[i];
}
void modify(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		mn[i]+=x;
		lazy[i]+=x;
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll)
		modify(i<<1,l,mid,ll,rr,x);
	if(mid<rr)
		modify(i<<1|1,mid+1,r,ll,rr,x);
	pushup(i);
}
void modify2(int i,int l,int r,int x,int y)
{
	if(l==r)
	{
		mnn[i]+=y;
		return;
	}
	int mid=l+r>>1;
	if(mid>=x)
		modify2(i<<1,l,mid,x,y);
	else
		modify2(i<<1|1,mid+1,r,x,y);
	pushup(i);
}
int main()
{
	scanf("%d %d",&n,&q);
	a[0]=1000001;
	a[n+1]=0;
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=0;i<=n;++i)
	{
		if(a[i]>a[i+1])
			modify(1,1,1000001,a[i+1]+1,a[i],1);
		if(i)
			modify2(1,1,1000001,a[i],1);
	}
	while(q--)
	{
		scanf("%d %d",&x,&y);
		modify2(1,1,1000001,a[x],-1);
		if(a[x]>a[x+1])
			modify(1,1,1000001,a[x+1]+1,a[x],-1);
		if(a[x-1]>a[x])
			modify(1,1,1000001,a[x]+1,a[x-1],-1);
		a[x]=y;
		modify2(1,1,1000001,a[x],1);
		if(a[x]>a[x+1])
			modify(1,1,1000001,a[x+1]+1,a[x],1);
		if(a[x-1]>a[x])
			modify(1,1,1000001,a[x]+1,a[x-1],1);
		printf("%d\n",mnn[1]);
	}
}