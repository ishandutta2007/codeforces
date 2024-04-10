#include<bits/stdc++.h>
#define N 100010
#define all(x) begin(x),end(x)
using namespace std;
vector<int> g[N];
vector<pair<int,int>> ans;
void solve(int u,int p,int k,int t){
	ans.push_back(make_pair(u,t));
	int tp=p?1:0;
	int ct=t;
	for(int i=0;i<g[u].size();i++){
		if(ct==k){
			ct=t-1-(g[u].size()-tp-i);
			ans.push_back(make_pair(u,ct));
		}
		int v=g[u][i];
		if(v==p) tp=0;
		else{
			solve(v,u,k,++ct);
			ans.push_back(make_pair(u,ct));
		}
	}
	assert(!p || ct>=t-1);
	if(p&&ct>=t) ans.push_back(make_pair(u,t-1));	
}
int main(){
	int n,x,y,k=0;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(g[i].size()>k) k=g[i].size();
	}
	solve(1,0,k,0);
	printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d %d\n",x.first,x.second);
	return 0;
}