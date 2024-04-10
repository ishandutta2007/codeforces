#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <vector>

typedef long long LL;
#define pb push_back
using namespace std;
const LL mod = 1e6+3;
LL qpow(LL p,LL k) {
	LL res=1ll;p%=mod;
	for (;k;k>>=1,(p*=p)%=mod)
		if (k&1) (res*=p)%=mod;
	return res;
}
bool judge(LL n,LL k) {
	LL res=1ll;
	for (LL i=1;i<=n;i++) {
		res*=2ll;
		if (res>=k) return false;
	}
	return true;
}
LL n,k,sum[mod]; 
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("birthday.in","r",stdin);
		freopen("birthday.out","w",stdout);
	#endif
	scanf("%I64d %I64d",&n,&k);
	if (judge(n,k)) {puts("1 1");return 0;}
	LL B=qpow(qpow(2,n),k-1),A=0;
	if (k<mod) {
		LL b=qpow(2,n);A=1ll;
		for (int i=1;i<k;i++) (A*=b-i)%=mod;
	}
	LL num=k-1,cnt=0,inc;
	while (num) cnt+=(num/=2);
	inc=qpow(qpow(2,mod-2),cnt);
	(A*=inc)%=mod;(B*=inc)%=mod;(A=B-A)%=mod;
	if (A<0) A+=mod; 
	if (B<0) B+=mod;
	printf("%I64d %I64d",A,B);
	return 0;
}