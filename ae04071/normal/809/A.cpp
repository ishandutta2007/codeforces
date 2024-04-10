#include <cstdio>
#include <algorithm>

typedef long long lli;
const int mod=1e9+7;
int n;
lli arr[300000];

lli power(lli a, lli p) {
	lli res=1;
	while(p) {
		if(p&1) res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) 
		scanf("%lld",arr+i);
	std::sort(arr, arr+n);

	lli res=0;
	for(int i=0;i<n;i++) {
		res=(res+arr[n-i-1]*(power(2,n-i-1)-1))%mod;
		res=(res-arr[n-i-1]*(power(2,i)-1))%mod;
	}
	while(res<0) res+=mod;
	printf("%lld\n",res);
	return 0;
}