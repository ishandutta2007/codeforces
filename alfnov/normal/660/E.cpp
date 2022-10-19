#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int powdv(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return ans;
}
int f[1000005];
int main(){
	int n,m;
	cin>>n>>m;
	if(m==1){
		cout<<n+1<<endl;
		return 0;
	}
	int mm=powdv(m-1,mod-2),sb=1;
	f[0]=1;
	int bs=1;
	int he=f[0];
	for(int i=1;i<=n;++i){
		int zz=1ll*m*bs%mod;
		f[i]=1ll*he*zz%mod;
		bs=1ll*bs*(m-1)%mod;
		sb=1ll*sb*mm%mod;
		he=(he+1ll*f[i]*sb)%mod;
	}
	int ans=0,bb=1;
	for(int i=n;i>=0;--i)
		ans=(ans+1ll*f[i]*bb)%mod,bb=1ll*bb*m%mod;
	cout<<ans<<endl;
	return 0;
}