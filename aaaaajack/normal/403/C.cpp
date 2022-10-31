#include<cstdio>
#include<vector>
using namespace std;
int DFS(vector<int> g[],bool visit[],int now){
	visit[now]=true;
	int i;
	for(i=0;i<g[now].size();i++){
		if(!visit[g[now][i]]) DFS(g,visit,g[now][i]);
	}
}
int main(){
	int n,i,j,x;
	bool flag=true;
	vector<int> g[2010],rg[2010];
	bool v[2010],rv[2010];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		g[i].clear();
		rg[i].clear();
		v[i]=false;
		rv[i]=false;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&x);
			if(x){
				g[i].push_back(j);
				rg[j].push_back(i);
			}
		}
	}
	DFS(g,v,0);
	DFS(rg,rv,0);
	for(i=0;i<n;i++) if(!v[i]||!rv[i]) flag=false;
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}