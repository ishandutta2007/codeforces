#include<bits/stdc++.h>
using namespace std;
int a[2009];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		int ans=a[n]-a[1];
		for(i=1;i<n;++i)ans=max(ans,a[i]-a[i+1]);
		int mx=0,mn=999999;
		for(i=1;i<=n;++i)mx=max(mx,a[i]),
		mn=min(mn,a[i]);
		ans=max(ans,max(mx-a[1],a[n]-mn));
		cout<<ans<<'\n';
	}
}