#include<bits/stdc++.h>
using namespace std;
const int N=300005,E=262144;
const int M=998244353;
int n,t,i,p[N],q[N],ans,tree[N*4],siz[N*4],tree2[N*4],j,a[N];
void modify(int i,int l,int r,int x,int y)
{
	if(l==r)
	{
		siz[i]+=y;
		tree[i]=max(0,siz[i]);
		tree2[i]=min(0,siz[i]);
		return;
	}
	int mid=l+r>>1;
	if(mid>=x)
		modify(i<<1,l,mid,x,y);
	else
		modify(i<<1|1,mid+1,r,x,y);
	siz[i]=siz[i<<1]+siz[i<<1|1];
	tree[i]=max(tree[i<<1|1],tree[i<<1]+siz[i<<1|1]);
	tree2[i]=min(tree2[i<<1],tree2[i<<1|1]+siz[i<<1]);
}
struct str{
	int a,b,c;
};
str Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return (str){siz[i],tree[i],tree2[i]};
	int mid=l+r>>1,ans=10000000;
	str a,b;
	a.a=a.b=a.c=b.a=b.b=b.c=0;
	if(mid>=ll)
		a=Query(i<<1,l,mid,ll,rr);
	if(mid<rr)
		b=Query(i<<1|1,mid+1,r,ll,rr);
	return (str){a.a+b.a,max(a.b+b.a,b.b),min(a.c,b.c+a.a)};
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&p[i]);
		a[p[i]]=i;
	}
	for(i=1;i<=n;++i)
		scanf("%d",&q[i]);
	printf("%d ",n);
	ans=n;
	for(i=1;i<n;++i)
	{
		modify(1,0,n,q[i],-1);
		for(j=ans;;--j)
		{
			str e=Query(1,0,n,0,a[j]-1);
			str d=Query(1,0,n,a[j],n);
			if(e.b+d.c>=0)
				break;
			modify(1,0,n,a[j],1);
		}
		ans=j;
		printf("%d ",j);
	}
}