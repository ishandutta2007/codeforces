#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,t,m,tot,p[200005],a[200005],q[200005],i;
long long tree[800005],ans=10000000000000000ll,lazy[800005];
void modify(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		lazy[i]+=x;
		tree[i]+=x;
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll)
		modify(i<<1,l,mid,ll,rr,x);
	if(mid<rr)
		modify(i<<1|1,mid+1,r,ll,rr,x);
	tree[i]=min(tree[i<<1],tree[i<<1|1])+lazy[i];
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
		q[p[i]]=i;
	}
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(i!=n)
			modify(1,1,n-1,i,n-1,a[i]);
	}
	ans=min(ans,tree[1]);
	for(i=1;i<=n;++i)
	{
		if(q[i]!=n)
			modify(1,1,n-1,q[i],n-1,-a[q[i]]);
		if(q[i]!=1)
			modify(1,1,n-1,1,q[i]-1,a[q[i]]);
		ans=min(ans,tree[1]);
	}
	cout<<ans;
}