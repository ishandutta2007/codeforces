#include<bits/stdc++.h>
#define N 300100
using namespace std;
vector<int> g[N];
bool in[N];
int main(){
	priority_queue<int> pq;
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	in[1]=true;
	vector<int> ans;
	pq.push(-1);
	while(!pq.empty()){
		int u=-pq.top();
		pq.pop();
		ans.push_back(u);
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(!in[v]) pq.push(-v);
			in[v]=true;
		}
	}
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
}