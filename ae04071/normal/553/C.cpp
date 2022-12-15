#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <utility>
#include <queue>
#include <functional>
#include <assert.h>

#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
#define double long double
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;

const lli mod=1e9+7;

int n,m;
vector<pii> adj[100001];
int vis[1000001];

bool dfs(int cur,int c) {
	vis[cur]=c;
	for(auto &it:adj[cur]) {
		if(vis[it.se]!=-1){
			if(vis[it.se]!=(vis[cur]^it.fi)) return false;
		} else if(!dfs(it.se, c^it.fi)) return false;
	}
	return true;
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		c^=1;
		adj[a].push_back(pii(c,b));
		adj[b].push_back(pii(c,a));
	}

	lli val=1,cnt=0;
	fill(vis,vis+n+1,-1);
	for(int i=1;i<=n;i++) if(vis[i]==-1) {
		if(!dfs(i,0)) val=0;
		else cnt++;
	}
	for(int i=0;i<cnt-1;i++) val=val*2%mod;
	printf("%lld\n",val);
	
	return 0;
}