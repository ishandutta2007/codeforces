#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> adj[100001];
int n,vis[100001],dp[100001][2],sz[100001];

void make(int cur,int p) {
	sz[cur] = (int)adj[cur].size() > 2;
	for(auto &it:adj[cur]) if(it!=p) {
		make(it,cur);
		sz[cur] += sz[it];
	}
}
int dfs(int cur,int p,int s) {
	int &ret=dp[cur][s];
	if(ret!=-1) return ret;

	if(!s) {
		if((int)adj[cur].size() > 3 || sz[cur] - ((int)adj[cur].size()==3) != 0) ret = 0;
		else ret = 1;
	} else {
		vector<int> na;
		for(auto &it:adj[cur]) if(it!=p) {
			dfs(it,cur,0); dfs(it,cur,1);
			if(!dp[it][0]) na.push_back(it);
		}
		if((int)na.size() > 1) ret=0;
		else {
			for(auto &val : na) if(!dp[val][1]) ret=0;
			if(ret==-1) ret=1;
		}
	}
	return ret;
}

int main() {
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) {
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> arr;
	int root=-1;

	for(int i=1;i<=n;i++) if((int)adj[i].size() > 3) arr.push_back(i);
	if(!arr.empty()) {
		root = arr[0];
	} else {
		for(int i=1;i<=n;i++) if((int)adj[i].size() > 2) arr.push_back(i);
		for(auto &val : arr) {
			int c=0;
			for(auto &it : adj[val]) if((int)adj[it].size() > 2) c++;
			if(c>=2){
				root = val;
				break;
			} else if((int)arr.size() - c - 1 != 0) {
				make(val,0);
				for(auto &it:adj[val]) if(sz[it] - ((int)adj[it].size()>2) != 0) {
					root = it;
					break;
				}
			}
		}
	}

	memset(dp,-1,sizeof(dp));
	if(root==-1) puts("Yes");
	else {
		vector<int> na;
		make(root,0);
		for(auto &it:adj[root]) {
			dfs(it,root,0); dfs(it,root,1);
			if(!dp[it][0]) na.push_back(it);
		}
		if((int)na.size() > 2) puts("No");
		else {
			for(auto &it:na) if(!dp[it][1]) {
				puts("No");
				return 0;
			}
			puts("Yes");
		}
	}

	return 0;
}