#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
using ar=int[N];
ar sn,fa,sz,d,tp,ed,p,q;
int id;
basic_string<int>g[N];
void dfs1(int x,int y){
	sz[x]=1,fa[x]=y,d[x]=d[y]+1;
	for(int i:g[x])if(i!=y)if(dfs1(i,x),sz[x]+=sz[i],sz[i]>sz[sn[x]])sn[x]=i;
}
void dfs2(int x,int y){
	if(tp[x]=y,q[p[x]=++id]=x,ed[y]=x,sn[x])dfs2(sn[x],y);
	for(int i:g[x])if(!tp[i])dfs2(i,i);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j,k;
	for(cin>>n,i=1;i<n;++i)cin>>j>>k,g[j]+=k,g[k]+=j;
	dfs1(1,0),dfs2(1,1),cout<<"d 1"<<endl,cin>>k,++k;
	for(i=1;;){
		cout<<"d "<<ed[i]<<endl,cin>>j;
		if(i=q[p[i]+(d[ed[i]]+k-j)/2-d[i]],d[i]==k)cout<<"! "<<i<<endl,exit(0);
		cout<<"s "<<i<<endl,cin>>i;
	}
	return 0;
}