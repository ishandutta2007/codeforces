#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
typedef vector<int> vi;
const int mx = 123456;

vector<vi> cost(mx), extra(mx), gr(mx), back(mx);
vi deg(mx, 0);

int dfs(int v, int ix){
	if(cost[v][ix] == -1){
		cost[v][ix] = 0;
		rep(j,0,gr[v].size()){
			int u = gr[v][j];
			if(j == ix || deg[u] <= 1) continue;
			cost[v][ix] += 2 + dfs(u, back[v][j]);
			extra[v][ix] = max(extra[v][ix], 1+extra[u][back[v][j]]); 
		}
	}
	return cost[v][ix];
}

int main(){
	int n,m,u,v,c;
	scanf("%d%d",&n,&m);
	rep(_,0,n-1){
		scanf("%d%d",&u,&v);
		--u,--v;
		++deg[u], ++deg[v];
		back[u].push_back(gr[v].size());
		back[v].push_back(gr[u].size());
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	rep(i,0,n){
		cost[i].resize(gr[i].size(), -1);
		extra[i].resize(gr[i].size(), 0);
	}
	rep(_,0,m){
		scanf("%d",&c);
		--c;
		deg[c] = 1e6;
	}
	stack<int> lov;
	rep(i,0,n)
		if(deg[i] == 1)
			lov.push(i);
	while(!lov.empty()){
		c = lov.top();
		lov.pop();
		for(auto v : gr[c])
			if(--deg[v] == 1)
				lov.push(v);
	}
	int rek = 1e8, ans = -1;
	rep(i,0,n){
		if(deg[i] > 1){
			int cur = 0, save = 0;
			rep(j,0,gr[i].size()){
				if(deg[gr[i][j]] > 1){
					cur += 2+dfs(gr[i][j],back[i][j]);
					save = max(save, extra[gr[i][j]][back[i][j]]);
				}
			}
			if(cur-save-1 < rek){
				rek = cur - save - 1;
				ans = i;
			}
		}
	}
	printf("%d\n%d\n",ans+1,max(0,rek));
}