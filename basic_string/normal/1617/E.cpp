#include<bits/stdc++.h>
using namespace std;
enum{N=7000009};
int get(int x){
	if(x==1)return 0;
	return (1<<__lg(x-1)+1)-x;
}
int ax,ay,m,t,a[N];
bool b[N];
basic_string<int>g[N];
unordered_map<int,int>mp;
int id(int x){
	if(!mp[x])mp[x]=++t;
	return mp[x];
}
#define fi first
#define se second
pair<int,int>dfs(int x){
	pair<int,int>now={-N,0},o;
	if(b[x]=1,a[x])now={0,a[x]};
	for(int i:g[x])if(!b[i]){
		o=dfs(i);
		if(o.fi+now.fi>m)m=o.fi+now.fi,ax=o.se,ay=now.se;
		if(o.fi>now.fi)now=o;
	}
	return++now.fi,now;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,i,o,f;
	for(cin>>n,i=1;i<=n;++i){
		cin>>o,a[id(o)]=i;
		for(;o;o=f)f=get(o),g[id(f)]+=id(o);
	}
	dfs(id(0)),cout<<ax<<' '<<ay<<' '<<m;
	return 0;
}