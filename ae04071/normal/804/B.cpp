#include <cstdio>
#include <algorithm>
#include <cstring>

char str[1001000];

int main() {
	scanf("%s",str);
	int n=strlen(str);
	const long long mod=1e9+7;
	long long b=0,res=0;
	for(int i=n-1;i>=0;i--) {
		if(str[i]=='b') b=(b+1)%mod;
		else {
			res=(res+b)%mod;
			b=(b*2)%mod;
		}
	}
	printf("%lld\n",res);
	return 0;
}