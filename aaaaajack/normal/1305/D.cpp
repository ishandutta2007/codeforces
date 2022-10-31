#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int deg[1010]={};
	scanf("%d",&n);
	int x,y,ans=-1;
	vector<int> g[1010];
	queue<int> q;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}
	for(int i=1;i<=n;i++){
		if(deg[i]==1) q.push(i);
	}
	while(q.size()>1){
		int u=q.front();
		q.pop();
		int v=q.front();
		q.pop();
		printf("? %d %d\n",u,v);
		fflush(stdout);
		scanf("%d",&x);
		if(x==u||x==v){
			ans=x;
			break;
		}
		for(int i=0;i<g[u].size();i++){
			deg[g[u][i]]--;
			if(deg[g[u][i]]==1) q.push(g[u][i]);
		}
		for(int j=0;j<g[v].size();j++){
			deg[g[v][j]]--;
			if(deg[g[v][j]]==1) q.push(g[v][j]);
		}
	}
	if(ans<0) printf("! %d\n",q.front());
	else printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}