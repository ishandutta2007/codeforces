#include <stdio.h>
#include <vector>
#include <algorithm>

int n,color[100001];
std::vector<int> adj[100001];

bool DFS(int node,int p)
{
	for(auto &it:adj[node]){
		if(it==p) continue;
		if(color[node]!=color[it]) return false;
		if(!DFS(it,node)) return false;
	}
	return true;
}

int main()
{
	scanf("%d",&n);
	int u,v;
	for(int i=0;i<n-1;i++){
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=1;i<=n;i++) 
		scanf("%d",color+i);

	for(int i=1;i<=n;i++) {
		for(auto &it:adj[i]) {
			if(color[it]!=color[i]) {
				bool chk=true;
				for(auto &jt:adj[i]) {
					chk=chk&DFS(jt, i);
				}
				if(chk) {
					printf("YES\n%d\n",i);
					return 0;
				}
				//printf("%d %d\n", it, i);

				chk=true;
				for(auto &jt:adj[it]) {
					chk=chk&DFS(jt, it);
				}
				if(chk) {
					printf("YES\n%d\n",it);
					return 0;
				}

				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n%d\n",1);

	return 0;
}