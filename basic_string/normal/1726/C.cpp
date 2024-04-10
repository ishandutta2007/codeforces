#include<bits/stdc++.h>
using namespace std;
int a[2009];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,m,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		string s;
		cin>>s;
		int ans=n;
		for(i=1;i<2*n;++i)if(s[i-1]==')'&&s[i]=='(')--ans;
		cout<<ans<<'\n';
	}
}