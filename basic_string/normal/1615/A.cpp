#include<bits/stdc++.h>
using namespace std;

int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,s;
	for(cin>>T;T--;){
		cin>>n;s=0;
		for(i=1;i<=n;++i)cin>>j,s+=j;
		if(s%n==0)cout<<0<<'\n';else cout<<1<<'\n';
	}
	return 0;
}