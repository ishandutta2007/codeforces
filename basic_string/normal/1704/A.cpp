#include<bits/stdc++.h>
using namespace std;

int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k;
	for(cin>>T;T--;){
		cin>>n>>m;
		string a,b;
		cin>>a>>b;
		for(i=1;i<m;++i)if(a[n-m+i]!=b[i]){cout<<"NO\n";goto gg;}
		for(i=0;i<=n-m;++i)if(a[i]==b[0]){cout<<"YES\n";goto gg;}
		cout<<"NO\n";
		gg:;
	}
}