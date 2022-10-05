#include<bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
int main(){
	int T;
	long long a,b,s,i;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&a,&b);
		b/=gcd(a,b),s=b;
		for(i=2;i*i<=b;++i){
			if(b%i==0){
				do b/=i;while(b%i==0);
				s=s/i*(i-1);
			}
		}
		if(b>1)s=s/b*(b-1);
		printf("%lld\n",s);
	}
	return 0;
}//drtkrdstkdtrkdtrkdtk