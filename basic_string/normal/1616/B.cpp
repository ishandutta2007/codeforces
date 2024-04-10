#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
char s[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k,l;
	for(cin>>T;T--;){
		cin>>n>>s+1;
		if(n>=2&&s[1]==s[2]){
			cout<<s[1]<<s[1]<<'\n';
			continue;
		}
		for(i=1;i<n;++i)if(s[i]<s[i+1])break;
		for(j=1;j<=i;++j)cout<<s[j];
		 for(j=i;j;--j)cout<<s[j];cout<<'\n';
	}
	return 0;
}