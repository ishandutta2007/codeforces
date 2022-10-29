#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,i,jc[250005],ans;
int main()
{
	scanf("%d%d",&n,&m);
	jc[0]=1;
	for(i=1;i<=n;++i)
		jc[i]=1ll*jc[i-1]*i%m;
	for(i=1;i<=n;++i)
		ans=(ans+1ll*(n-i+1)*(n-i+1)%m*jc[n-i]%m*jc[i])%m;
	printf("%d",ans);
	return 0;
}