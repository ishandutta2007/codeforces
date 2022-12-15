#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;

vector<int> adj[1000001];
pii d[1000001];
int dp[1000001],n,k,de[1000001];

void dfs(int cur,int p,int h) {
	de[cur]=h;
	if(cur!=1 && sz(adj[cur])==0) {
		d[cur]=pii(de[cur]-k,1);
		return; 
	}

	d[cur].fi = n+1;
	for(auto &it:adj[cur]) if(it!=p) {
		dfs(it,cur,h+1);
		if(d[it].fi<=de[cur]) d[cur].se+=d[it].se;
		d[cur].fi=min(d[cur].fi,d[it].fi);
	}
}
int DP(int cur,int p) {
	int &ret=dp[cur];
	if(ret!=-1) return ret;

	ret=d[cur].se;
	for(auto &it:adj[cur]) if(it!=p) {
		if(d[it].fi > de[cur])
			ret = max(ret,d[cur].se+DP(it,cur));
		else
			ret = max(ret,d[cur].se+DP(it,cur)-d[it].se);
	} 
	return ret;
}
int main() {
	scanf("%d%d",&n,&k);

	for(int i=2,v;i<=n;i++) {
		scanf("%d",&v);
		adj[v].push_back(i);
	}

	dfs(1,0,0);
	memset(dp,-1,sizeof(dp));
	DP(1,0);
	printf("%d\n",dp[1]);

	return 0;
}