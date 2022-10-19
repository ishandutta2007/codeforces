#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,m;
int ural(int ip){
	int res=ip;
	for(int i=2;i*i<=ip;i++){
		if(ip%i)continue;
		res-=res/i;
		while(!(ip%i))ip/=i;
	}
	if(ip!=1)res-=res/ip;
	return res;
}
signed main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&m);
		m/=__gcd(n,m);
		printf("%I64d\n",ural(m));
	}
	return 0;
}