#include<bits/stdc++.h>
#define int long long
#define P 998244353
using namespace std;
int T,n,ans1,ans2;
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		ans1=ans2=0;
		for(int i=1;i<n/2;i++){
			ans1+=(1<<i);
		}
		ans1+=(1<<n);
		for(int i=n/2;i<n;i++){
			ans2+=(1<<i);
		}
		printf("%lld\n",ans1-ans2);
	}
	return 0;
}
/*

*/