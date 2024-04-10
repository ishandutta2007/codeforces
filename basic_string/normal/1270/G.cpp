#include<bits/stdc++.h>
using namespace std;
enum{N=1000009};
int to[N];
bool f[N];
basic_string<int>ans;
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int T,n,i,j;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>j,to[i]=i-j,f[i]=0;
		for(i=1;!f[i];i=to[i])f[i]=1;
		for(ans={},j=i;j=to[j],ans+=j,j^i;);
		cout<<ans.size()<<'\n';
		for(int o:ans)cout<<o<<' ';cout<<'\n';
	}
	return 0;
}