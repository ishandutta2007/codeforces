#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)

int main(){
	long long n, ans = 1;
	scanf("%lld",&n);
	for(int i = 2; (long long)i*i <= n; ++i){
		if(n % i == 0){
			ans *= i;
			while(n % i == 0)
				n /= i;
		}
	}
	printf("%lld\n",ans*n);
}