#include<bits/stdc++.h>
#define N 1100
#define Q 998244353
using namespace std;
int main(){
	long long n,r=1,ans=0;
	scanf("%lld",&n);
	while(n>1){
		ans+=n/2*r;
		n=(n+1)/2;
		r<<=1;
	}
	printf("%lld\n",ans);
	return 0;
}