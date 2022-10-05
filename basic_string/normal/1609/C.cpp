#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+3;
int a[N],f[N],g[N];
bool isp(int x){
	for(int i=2;i*i<=x;++i)if(x%i==0)return 0;
	return 1;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,i,j,k,n,e;
	cin>>T;
	ll ans=0; 
	while(T--){
		cin>>n>>e;ans=0;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=n;i;--i){
			if(a[i]==1){
				if(i+e>n)f[i]=g[i]=1;
				else f[i]=f[i+e]+1,g[i]=g[i+e]+1;
				ans+=g[i]-1;
			}else if(isp(a[i])){
				if(i+e<=n)ans+=f[i+e],g[i]=f[i+e]+1,f[i]=0;
				else g[i]=1,f[i]=0;
			}else f[i]=g[i]=0;
		}
		for(i=n;i;--i){
			if(a[i]==1){
				if(i+e>n)f[i]=1;
				else f[i]=f[i+e]+1;
				ans-=f[i]-1; 
			}else f[i]=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}