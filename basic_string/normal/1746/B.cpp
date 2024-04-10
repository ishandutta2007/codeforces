#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N],ans[N];
int main(){
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;int w=0,ans=0;
		for(i=1;i<=n;++i)cin>>a[i],w+=a[i];
		for(i=n-w+1;i<=n;++i)if(!a[i])++ans;
		cout<<ans<<'\n';
	}
}