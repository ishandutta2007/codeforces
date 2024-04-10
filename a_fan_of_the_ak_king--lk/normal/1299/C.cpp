#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
typedef long double lb;
int t,n,i,a[1000005],q[1000005],top,nx[1000005],j;
long long s[1000005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(i=n;i>=1;--i)
	{
		while(top>1&&((lb)s[q[top]]-s[i])/(q[top]-i)>((lb)s[q[top-1]]-s[i])/(q[top-1]-i))
			--top;
		q[++top]=i;
		int l=1,r=top;
		while(l<r)
		{
			int mid=l+r>>1;
			if(((lb)s[q[mid]]-s[i-1])/(q[mid]-(i-1))>((lb)s[q[mid+1]]-s[i-1])/(q[mid+1]-(i-1)))
				l=mid+1;
			else
				r=mid;
		}
		nx[i]=q[l];
	}
	i=1;
	while(i<=n)
	{
		lb ans=((lb)s[nx[i]]-s[i-1])/(nx[i]-(i-1));
		for(j=i;j<=nx[i];++j)
			printf("%.12LF\n",ans);
		i=nx[i]+1;
	}
}