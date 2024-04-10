#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
int s[25][N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,l,r,i,j,k,n;
	for(i=0;i<25;++i){
		for(j=1;j<N;++j)if(j>>i&1)s[i][j]=s[i][j-1]+1;
		else s[i][j]=s[i][j-1];
	}
	for(cin>>T;T--;){
		cin>>l>>r;
		k=0;
		for(i=0;i<25;++i)k=max(k,s[i][r]-s[i][l-1]);
		cout<<(r-l+1)-k<<'\n';
	}
	return 0;
}