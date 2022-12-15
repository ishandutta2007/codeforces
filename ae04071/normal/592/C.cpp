#include <bits/stdc++.h>
using namespace std;
using lli = unsigned long long;

const lli inf = 5000000000000000000ll+1;
lli mul(lli a,lli b) {
	if(a>=inf || b>=inf || inf/a<=b) return inf;
	else return a*b;
}
lli __gcd(lli a, lli b) {
	lli t;
	while(b) {
		t=a%b; a=b; b=t;
	}
	return a;
}

void print(lli a,lli b) {
	printf("%llu/%llu\n",a/__gcd(a,b), b/__gcd(a,b));
}
int main() {
	lli n,a,b;
	scanf("%llu%llu%llu",&n,&a,&b);
	if(a>b) swap(a,b);
	
	lli ln = mul(a/__gcd(a,b), b),t=n/ln;
	if(t==0) print(min(n,a-1), n);
	else {
		lli cnt = t * a-1, nt = n - t*ln+1;
		print(cnt+min(nt,a), n);
	}
	
	return 0;
}