#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int T;
	long long n,m,g,b,s;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&g,&b);
		if(n&1)m=n/2+1;else m=n/2;
		if(m%g!=0)s=(m/g)*(g+b)+m%g;
		else s=(m/g)*(g+b)-b;
		printf("%lld\n",max(s,n));
	}
	return 0;
}//