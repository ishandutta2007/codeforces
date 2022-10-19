#include <bits/stdc++.h>
using namespace std;
#define ll long long
main(){
	ll a,b,ab;
	scanf("%lld%lld%lld",&a,&b,&ab);
	ll q1 = 0;
	if(a+b) q1 = 1;
	ll qab = 2*ab + 2*min(a,b);
	if(a > b) qab++;
	
	ll qba = 0;
	if(b){
		b--;
		qba = 1 + 2*ab;
		qba += 2*min(a,b);
		if(a > b) qba++;
	}
	
	printf("%lld\n",max(q1,max(qab,qba)));
}