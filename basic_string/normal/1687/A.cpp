#include<bits/stdc++.h>
using namespace std;
long long s[200009];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k;
	long long ans;
	for(cin>>T;T--;){
		cin>>n>>m;ans=0;
		for(i=1;i<=n;++i)cin>>s[i],s[i]+=s[i-1];
		if(m<=n){
			for(i=m;i<=n;++i)ans=max(ans,s[i]-s[i-m]);
			cout<<ans+m*(m-1ll)/2<<'\n';
		}else{
			ans=s[n]+n*1ll*m-(n+1ll)*n/2;
			cout<<ans<<'\n';
		}
	}
}