#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
//#define P 998244353
using namespace std;
int T,n,K,ffl;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>K;
		ffl=0;
		if(n%2==0){
			printf("%lld\n",n+2*K);
		}else{
			for(int i=2;i<=sqrt(n);i++){
				if(n%i==0){
					n+=i;
					K--;
					ffl=1;
					break;
				}
			}
			if(!ffl){
				n+=n;
				K--;
			}
			printf("%lld\n",n+2*K);
		}
	}
	return 0;
}
/*

*/