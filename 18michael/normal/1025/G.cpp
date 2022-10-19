#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,t,ans=1;
int a[502];
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		if(~x)++a[x];
	}
	for(int i=1;i<n;++i)(ans<<=1)%=mod;
	--ans;
	for(int i=1;i<=n;++i)
	{
		for(int j=t=1;j<=a[i];++j)(t<<=1)%=mod;
		(ans-=t-1)%=mod;
	}
	return 0&printf("%d",(ans+mod)%mod);
}