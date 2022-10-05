#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j,k;
	string s; 
	for(cin>>T;T--;){
		cin>>s;
		i=s.size();
		if(s[0]!=s[i-1]){
			if(s[0]=='a')cout<<'b';else cout<<'a';
			for(j=1;j<i;++j)cout<<s[j];
		}else cout<<s;
		cout<<'\n';
	}
	return 0;
}