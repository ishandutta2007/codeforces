#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,m,a,b,g,aa[N],bb[N],gg[N],val[N],ans;
struct edge{
	int v,id;
};
vector <edge> e[N];
bool dfs(int id,int f){
	if(id==b)return 1;
	bool p=0;
	for(auto i:e[id]){
		int to=i.v;
		if(to!=f)if(dfs(to,id))val[i.id]=max(val[i.id],g),p=1;
	}
	return p;
}
int query(int id,int f){
	if(id==b)return 1;
	bool p=0;
	for(auto i:e[id]){
		int to=i.v;
		if(to!=f)if(query(to,id))ans=min(ans,val[i.id]),p=1;
	}
	return p;
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back({v,i});
		e[v].push_back({u,i});
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>g;
		aa[i]=a,bb[i]=b,gg[i]=g;
		dfs(a,0);
	}
	for(int i=1;i<=m;i++){
		a=aa[i],b=bb[i],g=gg[i];
		ans=1e7;
		query(a,0);
		if(ans!=g)puts("-1"),exit(0);
	}
	for(int i=1;i<n;i++)cout<<(val[i]==0?1000000:val[i])<<" ";
	return 0;
}