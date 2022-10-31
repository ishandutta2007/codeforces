#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,P=998244353;
const int N=200005,E=262144;
#define inf 2147483647
int n,i,j,t,a[N],m;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	if(n>m)
	{
		puts("0");
		return 0;
	}
	sort(a+1,a+1+n);
	long long ans=1;
	for(i=1;i<=n;++i)
		for(j=i+1;j<=n;++j)
			ans=ans*(a[j]-a[i])%m;
	cout<<ans;
}