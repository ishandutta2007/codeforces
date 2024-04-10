#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int,int> pii;

int n,m,a[100001];
vector<int> adj[100001];
int ans=0;

void dfs(int cur,int p,int c){ 
	c+=a[cur];
	if(!a[cur]) c=0;
	if(c>m) return;

	if(cur!=1 && (int)adj[cur].size()==1) ans++;

	for(auto &it:adj[cur]) if(it!=p) {
		dfs(it,cur,c);
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);

	for(int i=1,u,v;i<n;i++) {
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0,0);
	printf("%d\n",ans);
	
	return 0;
}