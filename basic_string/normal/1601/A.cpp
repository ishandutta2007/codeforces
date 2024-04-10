#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[33];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;memset(a,0,sizeof a);
		for(i=1;i<=n;++i){
			cin>>j;
			for(k=0;k<31;++k)if(j>>k&1)++a[k];
		}
		for(i=1;i<=n;++i){
			for(j=0;j<31;++j)if(a[j]%i)goto gg;
			cout<<i<<' ';
			gg:;
		}cout<<'\n';
	}
	return 0;
}