#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int powdv(int x,int y=mod-2){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return ans;
}
int di[200005],id[200005];
int ans[200005];
int main(){
	int n;
	cin>>n;
	di[0]=1;
	for(int i=1;i<=n;++i)di[i]=1ll*i*di[i-1]%mod;
	id[n]=powdv(di[n]);
	for(int i=n-1;i>=0;--i)id[i]=1ll*id[i+1]*(i+1)%mod;
	int k1=(n-1)/2,k2=(n+1)/2;
	int he=0;
	for(int i=k2;i>=1;--i){
		int f=1ll*di[k1]*id[k2-i]%mod*di[n-i]%mod;
		ans[i]=(0ll+f-1ll*he*(1ll*di[i-1]*id[i]%mod)%mod+mod)%mod;
		he=(he+ans[i])%mod;
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}