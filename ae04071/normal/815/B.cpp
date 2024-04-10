#include <cstdio>

const int mod=1e9+7;
int n;
int arr[2000000],tmp[2000000];

long long power(long long val, int a) {
	long long res=1;
	while(a) {
		if(a&1) res=res*val%mod;
		val=val*val%mod;
		a>>=1;
	}
	return res;
}
long long inv(long long val) {
	return power(val, mod-2);
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	if(n==1) {printf("%d\n",arr[0]);return 0;}
	
	int m=1;
	if((n&1)) {
		for(int i=0;i<n-1;i++) tmp[i]=arr[i]+m*arr[i+1],m*=-1;
		for(int i=0;i<n-1;i++) arr[i]=tmp[i]%mod;
		n--;
	}

	long long res=0,c=1,nu=(n/2)-1,de=1;
	bool flag=((n/2&1)==0);
	for(int i=0;i<n;i+=2) {
		res=(res+c*arr[i])%mod;
		if(flag) res=(res-c*arr[i+1])%mod;
		else res=(res+c*arr[i+1])%mod;
		c=c*nu%mod;
		c=c*inv(de)%mod;
		nu--;de++;
	}
	while(res<0) res+=mod;
	printf("%lld\n",res);
	
	return 0;
}