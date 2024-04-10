#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
char s[N];
int ans,n;
void cal(int i,int v){
	if(i<3||i>n)return;
	if(s[i-2]=='a'&&s[i-1]=='b'&&s[i]=='c')ans+=v;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int q,i,j,k;
	char c;
	cin>>n>>q;
	cin>>s+1;
	for(i=3;i<=n;++i){cal(i,1);
		
	}
	while(q--){
		cin>>i>>c;
		for(j=i-2;j<=i+2;++j)cal(j,-1);
		s[i]=c;
		for(j=i-2;j<=i+2;++j)cal(j,1);
		cout<<ans<<'\n'; 
	}
	return 0;
}