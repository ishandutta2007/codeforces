#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,P=998244353;
const int N=400005,E=262144;
#define inf 2147483647
int n,i,j,s,ans,a[N],b[N],c[N],kb,kc;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(i=25;i>=0;--i)
	{
		kb=kc=0;
		for(j=1;j<=n;++j)
			if((a[j]>>i)&1)
				c[++kc]=a[j]&((1<<i)-1);
			else
				b[++kb]=a[j]&((1<<i)-1);
		sort(b+1,b+1+kb);
		sort(c+1,c+1+kc);
		int l=1,s=0;
		for(j=kc;j>=1;--j)
		{
			while(l<=kb&&b[l]+c[j]<(1<<i))
				++l;
			s^=(l-1)&1;
		}
		l=1;
		for(j=kb;j>=1;--j)
		{
			while(l<=kb&&b[l]+b[j]<(1<<i))
				++l;
			s^=max((min(j-1,kb)-l+1),0)&1;
		}
		l=1;
		for(j=kc;j>=1;--j)
		{
			while(l<=kc&&c[l]+c[j]<(1<<i))
				++l;
			s^=max((min(j-1,kc)-l+1),0)&1;
		}
		ans^=s<<i;
	}
	cout<<ans;
}