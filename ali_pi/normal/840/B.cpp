#include<bits/stdc++.h>

using namespace std;

const int N=3*1e5+1;
int n,m,p[N],x,y,a[N],deg,neg,vis[N];
vector<pair<int,int>>g[N];
vector<int>ans;

int dfs(int u){
	vis[u]=1;
	int t=p[u];
	for(auto v:g[u])
		if(!vis[v.first]&&dfs(v.first))
			ans.push_back(v.second),t^=1;
	return t;	
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(~p[i])deg^=p[i];
		else p[i]=0,neg=i;
	}
	if(deg&&!neg)
                return puts("-1"),0;
	if(neg)p[neg]=deg;
	for(int i=1;i<=m;i++){ 
		cin>>x>>y;
		g[x].push_back({y,i});
		g[y].push_back({x,i});
	}
	dfs(1);
	cout<<ans.size()<<endl;
	for(auto x:ans)
                cout<<x<<endl;
	
}