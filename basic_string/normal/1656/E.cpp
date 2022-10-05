#include<bits/stdc++.h>
using namespace std;
enum{N=100009};
basic_string<int>g[N];
int ans[N],d[N];
void dfs(int x,int y){
	for(int i:g[x])if(i^y){
		dfs(i,x),++d[x];
	}
}
void dfs2(int x,int y,int z){
	ans[x]=z*(1+d[x]);
	for(int i:g[x])if(i^y){
		dfs2(i,x,-z);
	}
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,i,j,k,n;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)g[i]={},d[i]=0;
		for(i=1;i<n;++i)cin>>j>>k,g[j]+=k,g[k]+=j;
		dfs(1,0);
		ans[1]=-d[1];
		for(int i:g[1])dfs2(i,1,1);
		for(i=1;i<=n;++i)cout<<ans[i]<<' ';cout<<'\n';
	}
}