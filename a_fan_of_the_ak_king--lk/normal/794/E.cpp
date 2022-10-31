#include<bits/stdc++.h>
using namespace std;
int n,a[300005],i,tree[1000005],tree2[1000005],ans[600005],mx;
void modify(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		tree[i]=max(tree[i],x);
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll)
		modify(i<<1,l,mid,ll,rr,x);
	if(mid<rr)
		modify(i<<1|1,mid+1,r,ll,rr,x);
}
void modify2(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		tree2[i]=max(tree2[i],x);
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll)
		modify2(i<<1,l,mid,ll,rr,x);
	if(mid<rr)
		modify2(i<<1|1,mid+1,r,ll,rr,x);
}
void Out1(int i,int l,int r,int s)
{
	if(l==r)
	{
		if(n-2*l>=0)
			ans[n-2*l]=max(s,tree[i]);
		return;
	}
	int mid=l+r>>1;
	Out1(i<<1|1,mid+1,r,max(s,tree[i]));
	Out1(i<<1,l,mid,max(s,tree[i]));
}
void Out2(int i,int l,int r,int s)
{
	if(l==r)
	{
		if(n-2*l-1>=0)
			ans[n-2*l-1]=max(s,tree2[i]);
		return;
	}
	int mid=l+r>>1;
	Out2(i<<1|1,mid+1,r,max(s,tree2[i]));
	Out2(i<<1,l,mid,max(s,tree2[i]));
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		modify(1,1,n,1,min(i,n-i+1),a[i]);
	}
	for(i=2;i<=n;++i)
		modify2(1,1,n,1,min(i-1,n-i+1),min(a[i],a[i-1]));
	Out1(1,1,n,0);
	Out2(1,1,n,0);
	for(i=0;i<n-1;++i)
		printf("%d ",ans[i]);
	printf("%d",mx);
}