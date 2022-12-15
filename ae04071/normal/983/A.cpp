#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef pair<lli,int> pli;

lli gcd(lli a,lli b) {
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		lli a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a==0) {
			puts("Finite");
			continue;
		}
		b /= gcd(a,b);
		
		lli t=gcd(c,b);
		while(t!=1) {
			lli val=b;
			while(val%t==0) {
				val/=t;
			}
			if(val==b) break;
			b=val;
			t=gcd(c,b);
		}
		puts(b==1 ? "Finite" : "Infinite");
	}
	return 0;
}