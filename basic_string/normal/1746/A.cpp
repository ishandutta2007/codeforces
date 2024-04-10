#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N],ans[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>k;
		int ans=0;
		for(i=1;i<=n;++i)cin>>j,ans|=j;
		if(ans)cout<<"YES\n";else cout<<"NO\n";
	}
}