#include<bits/stdc++.h>
using namespace std;
#define int long long
int k,b,n,t;
int calc(){
	int ans=0,base=1;
	while(base<=t)base*=k,base+=b,ans++;
	return ans-1;
}
signed main(){
	scanf("%lld%lld%lld%lld",&k,&b,&n,&t);
	printf("%lld\n",max(n-calc(),0ll));
	return 0;
}