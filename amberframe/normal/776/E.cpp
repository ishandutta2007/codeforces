#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const LL mod = 1000000007;

LL n,k;
LL getphi(LL n)
{
	LL res=n;
	for (LL i=2;i*i<=n;i++)
	if (n%i==0) {
		while (n%i==0) n/=i;
		res=res/i*(i-1);
	}
	if (n>1) {
		res=res/n*(n-1);
	}
	return res;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("children.in","r",stdin);
		freopen("children.out","w",stdout);
	#endif
	scanf("%lld %lld",&n,&k);k=(k+1)/2;
	while (n>1&&k) {
		n=getphi(n);k--;
	}
	printf("%lld",n%mod);
	return 0;
}