#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctype.h>

using namespace std;

int main() {
	long long l,r;
	scanf("%lld%lld",&l,&r);
	puts("YES");
	for(long long i=r;i>=l;i-=2) {
		printf("%lld %lld\n",i,i-1);
	}

	return 0;
}