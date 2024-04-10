#include<bits/stdc++.h>
#define N 100100
using namespace std;
int f[N],sz[N];
deque<set<int>> vec[N];
vector<int> g[N];
vector<int> qnum[N],qdep[N];
int ans[N];
string s[N];
void init(int n){
	for(int i=1;i<=n;i++){
		f[i]=i;
		sz[i]=1;
	}
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void uni(int x,int y){
	int fx=find(x),fy=find(y);
	if(sz[fx]>sz[fy]) swap(fx,fy);
	if(vec[fx].size()>vec[fy].size()) vec[fy].resize(vec[fx].size());
	for(int i=0;i<vec[fx].size();i++){
		for(auto s: vec[fx][i]){
			vec[fy][i].insert(s);
		}
	}
	sz[fy]+=sz[fx];
	f[fx]=fy;
	vec[fx].clear();
}
void DFS(int u){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		DFS(v);
		vec[find(v)].push_front(set<int>());
		uni(u,v);
	}
	for(int j=0;j<qdep[u].size();j++){
		if(qdep[u][j]<vec[find(u)].size()) ans[qnum[u][j]]=vec[find(u)][qdep[u][j]].size();
	}
}
int main(){
	int n,m,x,y,cnt=0;
	map<string,int> id;
	int p;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>p;
		g[p].push_back(i);
		vec[i].resize(1);
		if(!id.count(s[i])) id[s[i]]=cnt++;
		vec[i][0].insert(id[s[i]]);
	}
	
	init(n);
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		qnum[x].push_back(i);
		qdep[x].push_back(y);
	}
	DFS(0);
	for(int i=0;i<m;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}