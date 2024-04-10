#include <stdio.h>

using lli=long long;
lli n,l,r;
int arr[60];

lli power(lli val, lli a) {
	lli res=1;
	while(a) {
		if(a&1) res*=val;
		val*=val;
		a>>=1;
	}
	return res;
}

int main() {
	scanf("%lld %lld %lld",&n,&l,&r);
	l--;r--;

	int cnt=0;
	while(n) {
		arr[cnt++]=n&1;
		n>>=1;
	}

	lli res=0, t=1;
	for(int i=cnt-1;i>=0;i--,t++) {
		if(arr[i]) {
			lli d=power(2,t), a=power(2,t-1)-1;
			//printf("%lld %ld\n",a,d);
			if(a>r) continue;

			lli ll,rr;
			if(a<l) ll=((l-a+d-1)/d)*d+a;
			else ll=a;
			rr=(r-a)/d*d+a;
			//printf("%lld %lld\n\n", ll, rr);
			res+=(rr-ll)/d+1;
		}
	}
	printf("%lld\n",res);

	return 0;
}