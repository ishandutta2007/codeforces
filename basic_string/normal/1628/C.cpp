#include<bits/stdc++.h>
using namespace std;
int a[1009][1009],ans;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,mn;
	bool b;
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		for(i=1;i<=n;++i)for(j=1;j<=n;++j)cin>>a[i][j];
		for(i=2;i<=n+n;i+=4){
			if(i<=n)mn=1;
			else mn=i-n;
			for(j=mn,k=i-j,b=1;k>=mn;++j,--k,b^=1)if(b){
				ans^=a[j][k]^a[j][n-k+1];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}