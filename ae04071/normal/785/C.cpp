#include <stdio.h>
#include <algorithm>

typedef long long lli;

int main() {
	lli a,b;
	scanf("%lld %lld", &a, &b);
	if(a<=b) {
		printf("%lld\n",a);
		return 0;
	}

	lli lo=0,up=std::min(a,3000000000ll);
	while(up-lo>1) {
		lli md=(lo+up)/2;
		if((md-1)*md/2+(md+b)<a)
			lo=md;
		else
			up=md;
	}
	printf("%lld\n",up+b);

	return 0;
}