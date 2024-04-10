#include <stdio.h>

typedef long long lli;

int n;
lli k,arr[100000];


int main() {
	scanf("%d %lld",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%lld",arr+i);

	lli res=0;
	for(int i=0;i<n;i++) {
		res+=(arr[i]/k)*k+(arr[i]%k!=0)*k;
	}
	printf("%lld\n",res/(2*k)+(res%(2*k)!=0));

	return 0;
}