#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int N=500005,M=1000000007;
int n,a[3][200005],k1,k2,k3,i,l,tree2[1000005],tree3[1000005],mn[1000005],ans;
void pushup(int x)
{
	tree2[x]=tree2[x<<1]+tree2[x<<1|1];
	tree3[x]=tree3[x<<1]+tree3[x<<1|1];
	mn[x]=max(mn[x<<1]+tree3[x<<1|1],mn[x<<1|1]+tree2[x<<1]);
}
void modify(int i,int l,int r,int x,int y)
{
	if(l==r)
	{
		if(y==2)
			++tree2[i];
		else
			++tree3[i];
		++mn[i];
		return;
	}
	int mid=l+r>>1;
	if(mid>=x)
		modify(i<<1,l,mid,x,y);
	else
		modify(i<<1|1,mid+1,r,x,y);
	pushup(i);
}
struct str{
	int t2,t3,mn;
};
str Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return (str){tree2[i],tree3[i],mn[i]};
	int mid=l+r>>1;
	if(mid>=ll&&mid<rr)
	{
		str x=Query(i<<1,l,mid,ll,rr);
		str y=Query(i<<1|1,mid+1,r,ll,rr);
		return (str){x.t2+y.t2,x.t3+y.t3,max(x.mn+y.t3,y.mn+x.t2)};
	}
	if(mid>=ll)
		return Query(i<<1,l,mid,ll,rr);
	else
		return Query(i<<1|1,mid+1,r,ll,rr);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d %d",&k1,&k2,&k3);
	n=k1+k2+k3;
	for(i=1;i<=k1;++i)
		scanf("%d",&a[0][i]);
	for(i=1;i<=k2;++i)
	{
		scanf("%d",&a[1][i]);
		modify(1,1,n,a[1][i],2);
	}
	for(i=1;i<=k3;++i)
	{
		scanf("%d",&a[2][i]);
		modify(1,1,n,a[2][i],3);
	}
	sort(a[0]+1,a[0]+1+k1);
	l=1;
	for(i=0;i<=n;++i)
	{
		while(l<=k1&&a[0][l]<=i)
			++l;
		int s=0;
		if(i<n)
		{
			str tmp=Query(1,1,n,i+1,n);
			s=tmp.mn;
		}
		ans=max(ans,s+l-1);
	}
	cout<<n-ans<<endl;
}