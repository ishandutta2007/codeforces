#include <bits/stdc++.h>
using namespace std;

using lli = long long;
int main() {
	lli x,y;
	scanf("%lld%lld",&x,&y);
	
	if(__gcd(x,y)!=1) {puts("Impossible"); return 0;}
	while(x>1 || y>1) {
		if(x>y) {
			lli t=x/y;
			if(t*y==x) t--;
			printf("%lldA",t);
			x-=y*t;
		} else {
			lli t=y/x;
			if(t*x==y) t--;
			printf("%lldB",t);
			y-=x*t;
		}
	}
	return 0;
}