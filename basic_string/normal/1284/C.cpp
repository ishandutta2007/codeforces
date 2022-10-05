//%%%
#include<bits/stdc++.h>
using namespace std;
long long fac[275009];
int main(){
	register int n,i;
	register long long m,s=0;
	scanf("%d%lld",&n,&m);
	fac[0]=1;
	for(i=1;i<=n;++i)fac[i]=fac[i-1]*i%m;
	for(i=1;i<=n;++i)s=(s+i*(long long)i%m*fac[i-1]%m*fac[n+1-i])%m;
	printf("%lld",s);
	return 0;
}