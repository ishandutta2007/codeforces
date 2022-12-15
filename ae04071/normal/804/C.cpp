#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
int n,m;
std::vector<int> arr[300001],adj[300001];
int color[300001],mcolor;

void DFS(int node, int p) {
	std::vector<int> notuse;
	std::set<int> ucolor;
	for(auto &it:arr[node]) {
		if(color[it]) ucolor.insert(color[it]);
		else notuse.push_back(it);
	}
	int cnt=1;
	int i=0;
	auto it=ucolor.begin();
	while(i<notuse.size()&&it!=ucolor.end()) {
		while(i<notuse.size()&&cnt<*it) color[notuse[i++]]=cnt++;
		it++; cnt++;
	}
	for(;i<notuse.size();i++) color[notuse[i]]=cnt++;

	for(auto &it:adj[node]) {
		if(it!=p) DFS(it,node);
	}
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) {
		int s,val;
		scanf("%d",&s);
		mcolor=std::max(mcolor,s);
		while(s--) {
			scanf("%d",&val);
			arr[i].push_back(val);
		}
	}
	int u,v;
	for(int i=0;i<n-1;i++) {
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS(1,0);
	if(mcolor==0) mcolor=1;
	printf("%d\n",mcolor);
	for(int i=1;i<=m;i++) {
		if(!color[i]) color[i]=1;
		printf("%d ",color[i]);
	}
	
	return 0;
}