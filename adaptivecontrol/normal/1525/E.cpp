#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int T,n,a[23],ans;
long long f[23],inv[23];
bool cmp(int x,int y){return x>y;}
long long mypow(long long x,long long times){
	if(times==0)return 1;
	long long ret=mypow(x,times/2);
	ret=ret*ret%mod;if(times%2)ret=ret*x%mod;
	return ret;
}int calc(){
	for(int i=0;i<n;i++)
		a[i]=n-a[i]+1;
	sort(a,a+n,cmp);
	long long F=1,ret=0;
	for(int i=0;i<n;i++){
		ret+=(1ll*a[i]*f[n-i-1]%mod)*(inv[n]*F%mod)%mod;
		F=F*(n-i-a[i])%mod;
	}
	return ret%mod;
}
int x[23][50003];
int main(){
	f[0]=1;inv[0]=1;
	for(int i=1;i<=20;i++){
		f[i]=f[i-1]*i%mod;
		inv[i]=mypow(f[i],mod-2);
	}
	cin>>n>>T;
	for(int i=0;i<n;i++)
		for(int j=0;j<T;j++)
			scanf("%d",&x[i][j]);
	while(T--){
		for(int i=0;i<n;i++)
			a[i]=x[i][T];
		ans+=calc();
		if(ans>=mod)ans-=mod;
	}
	cout<<ans;
}