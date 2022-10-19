#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
int powdv(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%mod;
		y>>=1,x=1ll*x*x%mod;
	}
	return ans;
}
int v[1000005];
int main(){
	int T=1;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;++i)scanf("%d",&v[i]);
		int ans=1;
		for(int i=1;i<=k;++i)ans=1ll*ans*i%mod;
		for(int i=k+1;i<=n;++i){
			int zz=v[i-k],L=1,R=0;
			if(zz==-1)L=0,R=i-1;
			else if(zz==0)L=0,R=k;
			else L=zz+k,R=zz+k;
			ans=1ll*ans*max(0,min(R,i-1)-max(L,0)+1)%mod;
		}
		for(int i=n-k+1;i<=n;++i)if(v[i]>0)ans=0;
		cout<<ans<<endl;
	}
	return 0;
}