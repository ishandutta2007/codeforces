#include<bits/stdc++.h>
#define N 300100
using namespace std;
int ans[N],sz[N];
vector<int> qry[N];
vector<int> g[N];
void build(int u){
	sz[u]=1;
	for(int i=0;i<g[u].size();i++){
		build(g[u][i]);
		sz[u]+=sz[g[u][i]];
	}
}
void decom(int u,vector<int>& v){
	int mx=-1;
	for(int i=0;i<g[u].size();i++){
		if(mx<0||sz[g[u][i]]>sz[mx]) mx=g[u][i];
	}
	vector<int> tmp;
	for(int i=0;i<g[u].size();i++){
		tmp.clear();
		if(g[u][i]!=mx) decom(g[u][i],tmp);
	}
	v.push_back(u);
	if(mx<0){
		int j=0;
		for(int i=0;i<v.size();i++){
			while(j+1<v.size()&&sz[v[j+1]]*2>sz[v[i]]) j++;
			for(int k=0;k<qry[v[i]].size();k++){
				ans[qry[v[i]][k]]=v[j];
			}
		}
	}
	else{
		decom(mx,v);
	}
}
int main(){
	int n,q,x;
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		g[x].push_back(i);
	}
	build(1);
	for(int i=0;i<q;i++){
		scanf("%d",&x);
		qry[x].push_back(i);
	}
	vector<int> tmp;
	decom(1,tmp);
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);
	return 0;
}