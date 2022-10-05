#include<bits/stdc++.h>
using namespace std;
enum{N=100009};
basic_string<int>g[N],v;
bool c[N],b[N],f[N],a[N];
int r;
void dfs(int x){
	if(b[x]=1,a[x])f[r]=1;
	for(int i:g[x])if(!b[i])dfs(i);
}
void get(int x,int y){
	c[x]=1,a[x]^=1,v+=x;
	for(int i:g[x])if(!c[i])get(i,x),a[x]^=1,v+=x;
	if(a[x]){
		if(y)v+=y,a[y]^=1,v+=x;
		else y=g[x][0],v+=y,v+=x,v+=y;
	}
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,m,i,j;
	cin>>n>>m;
	while(m--)cin>>i>>j,g[i]+=j,g[j]+=i;
	for(i=1;i<=n;++i)cin>>a[i];
	for(i=1,j=0;i<=n;++i)if(!b[i])r=i,dfs(i),j+=f[i];
	if(j>1)cout<<-1,exit(0);else if(!j)cout<<0,exit(0);
	for(i=1;i<=n;++i)if(f[i]){
		get(i,0),cout<<v.size()<<'\n';
		for(int o:v)cout<<o<<' ';
	}
	return 0;
}