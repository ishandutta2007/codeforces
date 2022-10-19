#include<bits/stdc++.h>
#define ll long long
#define N 1015
using namespace std;
int n,u,v,ind[N];
vector<int> edge[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n;
	for(int i = 1;i < n;++i){
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
		ind[u]++;ind[v]++;
	}
	for(int i = 1;i <= n/2;++i){
		vector<int> cur;
		for(int j = 1;j <= n;++j)
			if(ind[j]==1) cur.push_back(j);
		if(cur.size()<2) break;
		int u = cur[0],v = cur[1];
		cout << "? " << u << ' ' << v << endl;
		cout.flush();
		int w;
		cin >> w;
		if(w==u||w==v){
			cout << "! " << w << endl;
			cout.flush();
			return 0;
		}
		ind[u] = ind[v] = -1;
		for(int j = 0;j < edge[u].size();++j) ind[edge[u][j]]--;
		for(int j = 0;j < edge[v].size();++j) ind[edge[v][j]]--;
	}
	for(int i = 1;i <= n;++i){
		if(ind[i]>=0){
			cout <<"! " << i << endl;
			cout.flush();
			return 0;
		}
	}
	
	return 0;
}