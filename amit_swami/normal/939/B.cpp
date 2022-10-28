#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
int n,k,a[233333],ans;
signed main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;++i)scanf("%lld",a+i);
	ans=1;
	for(int i=2;i<=k;++i)
	{
		if(n%a[i]<n%a[ans])
		{
			ans=i;
		}
	}
	printf("%lld %lld",ans,n/a[ans]);
	return 0;
}