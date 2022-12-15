#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <ctype.h>
#include <cstring>
#include <string>
#include <iostream>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;

typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const lli inf=1e16;

int n,m,s,t;
int u[100001],v[100001],w[100001];
vector<pii> adj[100001],radj[100001];
pli dist[100001],rdist[100001];
int vis[100001];

vector<pii> arr[100001];
int g[100001],gn=1,low[100001],dfn=1;
stack<int> stk;

int dfs(int cur,int ei) {
	stk.push(cur);
	int cd = low[cur] = dfn++;
	for(auto &it:arr[cur]) if(it.se != ei) {
		if(low[it.fi]) low[cur] = min(low[cur], low[it.fi]);
		else low[cur] = min(low[cur], dfs(it.fi, it.se));
	}
	if(low[cur] == cd) {
		while(!stk.empty()) {
			int now=stk.top();stk.pop();
			g[now] = gn;
			if(now == cur) break;
		}
		gn++;
	}
	return low[cur];
}

void dijk(int f,pli *dist) {
	fill(dist,dist+n+1,pli(inf,0));
	fill(vis,vis+n+1,0);

	int cur = !f ? s : t;
	priority_queue<pli,vector<pli>,greater<pli>> que;
	que.push(pli(0,cur));
	dist[cur] = pli(0,1);
	
	while(!que.empty()) {
		lli cost=que.top().first;
		int cur=que.top().se;
		que.pop();
		
		if(vis[cur]) continue;
		vis[cur] = 1;

		for(auto &it:(f ? radj[cur] : adj[cur])){
			if(dist[it.se].fi > cost + it.fi) {
				dist[it.se].fi = cost + it.fi;
				dist[it.se].se = dist[cur].se;
				que.push(pli(dist[it.se].fi, it.se));
			} else if(dist[it.se].fi == cost + it.fi) {
				dist[it.se].se = 2;
			}
		}
	}
}

int main() {
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=0;i<m;i++) {
		scanf("%d%d%d",u+i,v+i,w+i);
		adj[u[i]].push_back(pii(w[i],v[i]));
		radj[v[i]].push_back(pii(w[i],u[i]));
	}

	dijk(0,dist);
	dijk(1,rdist);

	lli cost = dist[t].first;

	for(int i=0;i<m;i++) {
		int a=u[i],b=v[i];
		lli c = dist[a].fi + rdist[b].fi + w[i] - cost;

		if(c==0) {
			arr[a].push_back(pii(b,i));
			arr[b].push_back(pii(a,i));
		}
	}
	dfs(s,-1);

	for(int i=0;i<m;i++) {
		int a=u[i],b=v[i];
		lli c = dist[a].fi + rdist[b].fi + w[i] - cost;

		if(c==0) {
			if(g[a]!=g[b]) puts("YES");
			else if(w[i] > 1) puts("CAN 1");
			else puts("NO");
		} else {
			if(w[i] - c - 1 < 1) puts("NO");
			else printf("CAN %lld\n",c+1);
		}
	}
	
	return 0;
}