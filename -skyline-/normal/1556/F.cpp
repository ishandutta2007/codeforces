#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,a[20];
ll f[22][22],g[22];
ll b[20005],c[20005];
ll fp(ll x,int k=orz-2){
	ll a=1;
	while(k){
		if(k&1)(a*=x)%=orz;
		k>>=1,(x*=x)%=orz;
	}
	return a;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",a+i);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)f[i][j]=a[i]*fp(a[i]+a[j])%orz;
	}
	int __=(1<<n)-1;
	for(int i=1;i<=__;++i)b[i]=1;
	for(int _=1;_<=__;++_){
		for(int i=0;i<n;++i){
			if(_&(1<<i)) continue;
			g[i]=1;
			for(int j=0;j<n;++j)if(_&(1<<j))(g[i]*=f[j][i])%=orz;
		}
		int ___=__^_;
		for(int t=___;t;t=(t-1)&___){
			ll o=1;
			for(int i=0;i<n;++i)if(t&(1<<i))(o*=g[i])%=orz;
			(b[_|t]-=o*b[_])%=orz;
		}
	}
	for(int _=1;_<=__;++_){
		for(int i=0;i<n;++i){
			if(_&(1<<i)){
				(c[_]+=b[_])%=orz;
				continue;
			}
			g[i]=1;
			for(int j=0;j<n;++j)if(_&(1<<j))(g[i]*=f[j][i])%=orz;
		}
		int ___=__^_;
		for(int t=___;t;t=(t-1)&___){
			ll o=1;
			for(int i=0;i<n;++i)if(t&(1<<i))(o*=g[i])%=orz;
			(c[_|t]+=o*c[_]%orz*b[t])%=orz;
		}
	}
	ll ans=c[__];
	ans=(ans%orz+orz)%orz;
	printf("%I64d\n",ans);
    return 0;
}