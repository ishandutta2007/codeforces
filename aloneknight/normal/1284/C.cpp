#include<bits/stdc++.h>
using namespace std;
const int N=250005;
int n,m,ans,fac[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=fac[0]=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%m;
	for(int i=1;i<=n;i++)ans=(ans+1ll*(n-i+1)*(n-i+1)%m*fac[n-i]%m*fac[i])%m;
	printf("%d\n",ans);
	return 0;
}