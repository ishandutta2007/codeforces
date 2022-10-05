#include<bits/stdc++.h>
using namespace std;
enum{N=1000009,P=998244353};
int v[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,ans;
	for(cin>>T;T--;){
		cin>>n>>k;
		for(i=1;i<=n;++i)cin>>v[i];
		for(i=1;i<=k;++i){
			if(v[n-i+1]>0){cout<<0<<'\n';goto gg;}
		}
		ans=1;
		for(i=n-k;i;--i){
			if(v[i]==-1){
				ans=ans*1ll*(i+k)%P;
			}else if(v[i]==0){
				ans=ans*1ll*(k+1)%P;
			}
		}
		for(i=1;i<=k;++i)ans=ans*1ll*i%P;
		cout<<ans<<'\n';
		gg:;
	}
}