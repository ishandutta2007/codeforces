#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
int n,k,Test_num;
LL ans;
int a[1000002];
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d%d",&n,&k),ans=1;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n-k;++i)ans=(ans*(a[i]? (~a[i]? 1:k+i):k+1))%mod;
		for(int i=n-k+1;i<=n;++i)ans=(ans*(a[i]>0? 0:(n-i+1)))%mod;
		printf("%lld\n",ans);
	}
	return 0;
}