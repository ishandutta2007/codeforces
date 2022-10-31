#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int M=1000000007;
typedef long double lb;
int n,m,i,j,t,k,tot,a[100005],ans;
bool check(int m)
{
	int i,r=1000000000,l=0;
	for(i=1;i<n;++i)
	{
		if(a[i]!=-1)
			if(a[i+1]==-1)
			{
				l=max(l,a[i]-m);
				r=min(r,a[i]+m);
			}
		if(a[i+1]!=-1)
			if(a[i]==-1)
			{
				l=max(l,a[i+1]-m);
				r=min(r,a[i+1]+m);
			}
	}
	ans=r;
	return (l<=r);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		int l=0,r=1000000000;
		for(i=1;i<n;++i)
			if(a[i]!=-1&&a[i+1]!=-1)
				l=max(l,abs(a[i]-a[i+1]));
		while(l<r)
		{
			int mid=l+r>>1;
			if(check(mid))
				r=mid;
			else
				l=mid+1;
		}
		check(l);
		printf("%d %d\n",l,ans);
	}
}