#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N],mx,c[N],n;
bool v[N],in[N],f;
basic_string<int>e[N];
void dfs(int x){
	if(v[x])return;
	in[x]=1;
	for(int i:e[x])if(in[i]&&!v[i])f=0;else dfs(i);
	v[x]=1;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,i,j;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)cin>>a[i],e[i]={},c[i]=v[i]=in[i]=0;
		for(i=mx=1;i<=n;++i)if(cin>>j,e[a[i]]+=j,++c[a[i]],c[a[i]]>c[mx])mx=a[i];
		for(v[mx]=i=f=1;i<=n;++i)dfs(i);
		if(f)cout<<"AC\n";else cout<<"WA\n";
	}
}