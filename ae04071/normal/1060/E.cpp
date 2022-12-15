#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const lli inf=1e15;

pll cnt[200001];
lli ds[200001],ans;
int n;
vector<int> adj[200001];

void dfs(int cur,int p) {
	for(auto &it:adj[cur]) if(it!=p) {
		dfs(it,cur);
		cnt[cur].first += cnt[it].second;
		cnt[cur].second += cnt[it].first;
		ds[cur] += ds[it] + cnt[it].second;
	}
	cnt[cur].second+=1;
}
void check(int cur,int p, pll c,lli d) {
	ans+=d+ds[cur];

	c.first += cnt[cur].first;
	c.second += cnt[cur].second;
	d+=ds[cur];
	
	for(auto &it:adj[cur]) if(it!=p) {
		check(it,cur, pll(c.second-cnt[it].first,c.first-cnt[it].second),d-ds[it]-cnt[it].second+(c.second-cnt[it].first));
	}
}

int main() {
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) {
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	check(1,0,pll(0,0),0);
	printf("%lld\n",ans/2);
	
	return 0;
}