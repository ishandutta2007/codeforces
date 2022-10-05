#include<bits/stdc++.h>
using namespace std;
enum{N=509};
long long a[N][N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	long long ans=0,mn;
	for(cin>>T;T--;){
		cin>>n;mn=1e18;ans=0;
		for(i=1;i<=n*2;++i)for(j=1;j<=n*2;++j)cin>>a[i][j];
		for(i=n+1;i<=n*2;++i)
		for(j=n+1;j<=n*2;++j)ans+=a[i][j];
		 
		 mn=min(mn,a[1][n+1]);
		 mn=min(mn,a[1][n*2]);
		 mn=min(mn,a[n][n+1]);
		 mn=min(mn,a[n][n*2]);
		 mn=min(mn,a[n+1][1]);
		 mn=min(mn,a[n+1][n]);
		 mn=min(mn,a[n*2][1]);
		 mn=min(mn,a[n*2][n]);
		cout<<ans+mn<<'\n';
	}
	return 0;
}