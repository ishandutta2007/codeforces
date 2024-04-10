#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long n;
		scanf("%lld",&n);
		if(n%2050) puts("-1");
		else{
			int ans=0;
			n/=2050;
			while(n){
				ans+=n%10;
				n/=10;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}