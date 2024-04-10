#include <stdio.h>
#include <vector>
#include <stack>

int n, m,arr[200001];
std::vector<int> adj[400011], radj[400011], sw[200001];
int door[200001][2];

std::stack<int> stk;
bool vis[400010];
int gr[400010], gn;
void DFS1(int node) {
	vis[node]=true;
	for(auto &it:adj[node]) 
		if(!vis[it]) DFS1(it);
	stk.push(node);
}

void DFS2(int node) {
	gr[node]=gn;
	vis[node]=true;
	for(auto &it:radj[node]) 
		if(!vis[it]) DFS2(it);
}

int main() {
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",arr+i);
	for(int i=1;i<=m;i++) {
		int val;
		scanf("%d",&val);
		sw[i].resize(val);
		for(int j=0;j<val;j++) {
			scanf("%d",&sw[i][j]);
			if(door[sw[i][j]][0]==0) door[sw[i][j]][0]=i;
			else door[sw[i][j]][1]=i;
		}
	}

	for(int i=1;i<=n;i++) {
		if(arr[i]) {
			adj[door[i][0]*2].push_back(door[i][1]*2);
			adj[door[i][1]*2+1].push_back(door[i][0]*2+1);
			radj[door[i][0]*2+1].push_back(door[i][1]*2+1);
			radj[door[i][1]*2].push_back(door[i][0]*2);

			
			adj[door[i][0]*2+1].push_back(door[i][1]*2+1);
			adj[door[i][1]*2].push_back(door[i][0]*2);
			radj[door[i][0]*2].push_back(door[i][1]*2);
			radj[door[i][1]*2+1].push_back(door[i][0]*2+1);
			
		}
		else {
			adj[door[i][0]*2+1].push_back(door[i][1]*2);
			adj[door[i][1]*2+1].push_back(door[i][0]*2);
			radj[door[i][1]*2].push_back(door[i][0]*2+1);
			radj[door[i][0]*2].push_back(door[i][1]*2+1);

			
			adj[door[i][0]*2].push_back(door[i][1]*2+1);
			adj[door[i][1]*2].push_back(door[i][0]*2+1);
			radj[door[i][1]*2+1].push_back(door[i][0]*2);
			radj[door[i][0]*2+1].push_back(door[i][1]*2);
			
		}
	}

	for(int i=2;i<m*2+2;i++) {
		if(!vis[i]) DFS1(i);
	}
	std::fill(vis, vis+m*2+2, false);
	while(!stk.empty()) {
		int now=stk.top(); stk.pop();
		if(!vis[now]){
			++gn;
			DFS2(now);
		}
	}

	for(int i=1;i<=m;i++) {
		if(gr[i*2]==gr[i*2+1]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}