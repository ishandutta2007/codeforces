#include<bits/stdc++.h>
#define N 1010
using namespace std;
int sz[N];
int num[N];
int inf=1e6;
vector<int> g[N];
int DFS(int u,int p){
	sz[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p) continue;
		DFS(v,u);
		sz[u]+=sz[v];
	}
}
int find_cen(int u, int n){
	int p=0;
	while(1){
		int nxt=-1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(v==p) continue;
			if(sz[v]>n/2){
				nxt=v;
				break;
			}
		}
		if(nxt<0) return u;
		p=u;
		u=nxt;
	}
}
void solve(int u, int p,int &cur, int st){
	num[u]=cur;
	cur+=st;
	printf("%d %d %d\n",u,p,min(inf,num[u]-num[p]));
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p) continue;
		solve(v,u,cur,st);
	}
}
int main(){
	int n,x,y;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	DFS(1,0);
	int c=find_cen(1,n);
	DFS(c,0);
	int mx=-1;
	for(int i=0;i<g[c].size();i++){
		if(mx<0 || sz[g[c][i]]>sz[mx]) mx=g[c][i];
	}
	int cur=1,st=1;
	bool giant=false;
	if(mx>0){
		solve(mx,c,cur,st);
	}
	for(int i=0;i<g[c].size();i++){
		if(g[c][i]==mx) continue;
		if(cur>n/3 && !giant){
			st=cur;
			giant=true;
		}
		solve(g[c][i],c,cur,st);
	}
	return 0;
}