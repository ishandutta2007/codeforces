#include<bits/stdc++.h>
using namespace std;

int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>k;
		int ans=0;
		for(i=1;i<=n;++i)cin>>j,ans=max(ans,j|k);
		cout<<ans<<'\n';
	}
}