#include<bits/stdc++.h>
#define N 500100
#define M 1001000
using namespace std;
vector<int> g[N];
vector<int> gp[N];
int gc=0;
int gn[N],cur[N];
set<int> in;
void DFS(int u, int c){
	gn[u]=c;
	gp[c].push_back(u);
	in.erase(u);
	auto it=in.lower_bound(cur[u]);
	while(it!=in.end()){
		cur[u]=*it+1;
		if(!binary_search(g[u].begin(),g[u].end(),*it)){
			DFS(*it,c);
		}
		it=in.lower_bound(cur[u]);
	}
}
int main(){
	int n,m,a,b,sz;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) in.insert(i);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end());
	}
	for(int i=1;i<=n;i++){
		if(gn[i]==0) DFS(i,++gc);
	}
	printf("%d\n",gc);
	for(int i=1;i<=gc;i++){
		printf("%d",(int)gp[i].size());
		for(int j=0;j<gp[i].size();j++) printf(" %d",gp[i][j]);
		puts("");
	}
	return 0;
}