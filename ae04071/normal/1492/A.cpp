#include <bits/stdc++.h>
using namespace std;
using lli = long long;

long long func(lli p, lli a) {
	return ((p-1) / a + 1) * a - p;
}

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		long long p, a, b, c;
		scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
	
		printf("%lld\n",min({func(p, a), func(p, b), func(p, c)}));
	}
	return 0;
}