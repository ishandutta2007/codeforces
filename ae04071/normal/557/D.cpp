#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long lli;

vector<int> adj[100001];
int n,m,vis[100001];

bool dfs(int cur,int c,int &c1,int &c2) {
	if(c==1) c1++;
	else c2++;
	vis[cur]=c;
	for(auto &it:adj[cur]){
		if(!vis[it]) {
			if(!dfs(it,c^2,c1,c2)) return false;
		} else if(vis[it]==c) return false;
	}
	return true;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	if(!m) {
		printf("3 %lld\n",1ll*n*(n-1)*(n-2)/6);
		return 0;
	}

	lli ans=0;
	int f=1;
	for(int i=1;i<=n;i++) if(!vis[i]) {
		int c1=0,c2=0;
		if(!dfs(i,1,c1,c2)) {
			puts("0 1");
			return 0;
		}
		ans += 1ll*c1*(c1-1)/2 + 1ll*c2*(c2-1)/2;
	}
	if(!ans) ans = 1ll*m*(n-2),f=2;
	printf("%d %lld\n",f,ans);

	return 0;
}