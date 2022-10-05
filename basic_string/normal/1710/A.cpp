#include<bits/stdc++.h>
using namespace std;
int a[100009];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>m>>k;
		for(i=1;i<=k;++i)cin>>a[i];
		long long ans=0;
		bool c=0;
		for(i=1;i<=k;++i)if(a[i]>=m*2){
			ans+=a[i]/m;
			if(a[i]/m>=3)c=1;
		}
		if(ans>=n&&(c||(ans-n)%2==0)){
		cout<<"Yes\n";continue;}
		ans=0;c=0;
		for(i=1;i<=k;++i)if(a[i]>=n*2){
			ans+=a[i]/n;
			if(a[i]/n>=3)c=1;
		}
		if(ans>=m&&(c||(ans-m)%2==0))cout<<"Yes\n";
		else cout<<"No\n";
	}
}