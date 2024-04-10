#include <bits/stdc++.h>
using namespace std;
long long fct[200022];
const long long MOD = 998244353LL;
long long g(long long x, long long n){
	if(n==0LL) return 1LL;
	long long h=g(x,n/2LL);
	if(n&1LL) return ((h*h)%MOD*x)%MOD;
	return (h*h)%MOD;
}
int main(){
	fct[0]=1;
	for(int i=1;i<200022;i++){
		fct[i]=fct[i-1]*i%MOD;
	}
	int n,k;
	scanf("%d%d",&n,&k);
	if(n<=k){
		puts("0");
	}
	else if(k==0){
		printf("%lld\n",fct[n]);
	}
	else{
		k=n-k;
		long long ans=0LL;
		for(int i=0;i<k;i++){
			long long tmp=(g(fct[k-1-i],MOD-2LL)*g(fct[i],MOD-2LL))%MOD;
			tmp = (tmp*g((long long)(k-i),(long long)(n-1)))%MOD;
			if(i&1){
				ans = (ans + MOD - tmp) % MOD;
			}
			else{
				ans = (ans + tmp) % MOD;
			}
		}
		ans = (ans * fct[n]) % MOD;
		ans = (ans * g(fct[n-k],MOD-2LL)) % MOD;
		ans = (ans * 2LL) % MOD;
		printf("%lld\n",ans);
	}
}