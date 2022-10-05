#include<bits/stdc++.h>
using namespace std;
bool b[199];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,l,ans;
	string s;
	for(cin>>T;T--;){
		cin>>s;memset(b,0,sizeof b);
		n=s.size();
		for(i=n-1;~i;--i){
			if(!b[s[i]])ans=i,b[s[i]]=1;
		}
		for(i=ans;i<n;++i)cout<<s[i];cout<<'\n';
	}
}