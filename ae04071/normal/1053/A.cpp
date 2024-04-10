#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
typedef long long lli;

int main() {
	lli n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);

	int f=0;
	lli g=__gcd(n,k);
	n/=g; k/=g;
	if(g!=1) f=1;

	g = __gcd(m,k);
	m/=g; k/=g;
	if(g!=1) f|=2;

	if(k>2) {
		puts("NO");
		return 0;
	}

	if(k==1) {
		if(f&1) n*=2;
		else m*=2;
	}
	
	puts("YES");
	printf("%lld %lld\n%lld %lld\n%lld %lld\n",0ll,0ll,n,0ll,0ll,m);

	return 0;
}