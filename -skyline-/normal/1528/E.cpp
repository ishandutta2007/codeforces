#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  998244353
using namespace std;
ll f[1000005],sf[1000005],g[1000005],sg[1000005],ans;
int n;
ll c3(ll x){
	x%=orz;
	return x*(x-1ll)%orz*(x-2ll)%orz*166374059ll%orz;
}
	
	
int main(){
	scanf("%d",&n);
	f[0]=g[0]=1;
	sf[0]=sg[0]=1;
	for(int i=1;i<=n;++i){
		f[i]=(g[i-1]*sg[i-1]-g[i-1]*(g[i-1]-1ll)/2ll)%orz;
		g[i]=(g[i-1]+f[i])%orz;
		sf[i]=(sf[i-1]+f[i])%orz;
		sg[i]=(sg[i-1]+g[i])%orz;
	}
	for(int i=0;i<=n;++i)(ans+=f[i]*g[n-i])%=orz;
	for(int i=1;i<n;++i)(ans-=f[i]*f[n-i])%=orz;
	ans+=2ll*(c3(sg[n-1]+2)-c3(sg[n-1]-g[n-1]+2+orz));
	ans=(ans%orz+orz)%orz;
	printf("%I64d\n",ans);
    return 0;
}