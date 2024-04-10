#include <stdio.h>

int n,m,k;

long long mod=1e9+7;
long long pow(long long a, long long p) {
	long long res=1;
	while(p) {
		if(p&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		p>>=1;
	}
	return res;
}
int main() {
	scanf("%d %d %d",&n,&m,&k);
	if(k>n)
		printf("%lld\n",pow(m,n));
	else if(k==n) {
		if(n%2==0)
			printf("%lld",pow(m,n/2));
		else
			printf("%lld",pow(m,n/2+1));
	}
	else if(k==1)
		printf("%lld",pow(m,n));
	else if(k%2==0)
		printf("%d",m);
	else 
		printf("%d",m*m);
	return 0;
}