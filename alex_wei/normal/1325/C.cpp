#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,u[N],v[N],ans[N],vis[N];
vector <pair<int,int> > e[N];
void bfs(int id){
	queue <int> q;
	q.push(id);
	int cnt=0;
	while(!q.empty()){
		int t=q.front(); q.pop();
		vis[t]=1;
		for(auto to:e[t]){
			if(!vis[to.first])
				q.push(to.first),ans[to.second]=cnt++;
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		e[u[i]].push_back({v[i],i});
		e[v[i]].push_back({u[i],i});
	}
	for(int i=1;i<=n;i++)if(e[i].size()>2){
		bfs(i);
		for(int i=1;i<n;i++)cout<<ans[i]<<endl;
		exit(0);
	}
	for(int i=0;i<n-1;i++)cout<<i<<endl;
	
	return 0;
}