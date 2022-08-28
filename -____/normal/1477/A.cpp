#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL x,LL y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
int n;
LL k,x,y,z;
int main(){
	int T,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld%lld",&n,&k,&x);
		z=0;
		for(i=2;i<=n;i++){
			scanf("%lld",&y);
			z=gcd(z,abs(y-x));
		}
		if(k==x){
			printf("YES\n");
			continue;
		}
		if(abs(k-x)%z==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}