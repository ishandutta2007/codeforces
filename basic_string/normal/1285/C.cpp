#include<cstdio>
#include<cmath>
long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
int main(){
	long long n,l;
	scanf("%lld",&n);
	l=sqrt(n);
	for(;;--l)if(n%l==0){
		if(gcd(n/l,l)==1){
			printf("%lld %lld",l,n/l);
		return 0;
		}
	}
	return 0;
}
//777