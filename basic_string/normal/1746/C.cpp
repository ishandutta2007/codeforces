#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N],ans[N];
int main(){
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i];
		for(i=n-1;i;--i)ans[a[i]]=i+1;
		ans[a[n]]=1;
		for(i=1;i<=n;++i)cout<<ans[i]<<' ';
		cout<<'\n';
	}
}