#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
using namespace std;

vector<int> vis;
vector<vector<pair<int,int> > > e;
vector<vector<int> > f;
int dfs(int r,int c){
	vis[r]=c;
	for(auto h:e[r]){
		if(vis[h.fs]!=-1){
			if(vis[h.fs]==c){
				return 1;
			}
		}
		else{
			if(dfs(h.fs,c^1)){
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	AquA;
	int n,m;
	cin >> n >> m;
	vis.resize(n,-1);
	e.resize(n);
	for(int i=0;i<m;i++){
		int t,a,b;
		cin >> t >> a >> b;
		a--;
		b--;
		e[a].push_back({b,t});
		e[b].push_back({a,t});
	}
	for(int i=0;i<n;i++){
		if(vis[i]==-1){
			if(dfs(i,0)){
				cout << "NO\n";
				return 0;
			}
		}
	}
	f.resize(n);
	vector<int> in(n);
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			for(auto h:e[i]){
				if(h.sc==1){
					in[h.fs]++;
					f[i].push_back(h.fs);
				}
				else{
					in[i]++;
					f[h.fs].push_back(i);
				}
			}
		}
	}
	queue<int> q;
	int cnt=0;
	vector<int> ans(n,-1);
	for(int i=0;i<n;i++){
		if(in[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		auto h=q.front();
		q.pop();
		ans[h]=cnt;
		cnt++;
		for(auto y:f[h]){
			in[y]--;
			if(in[y]==0){
				q.push(y);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(ans[i]==-1){
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			cout << "L ";
		}
		else{
			cout << "R ";
		}
		cout << ans[i] << "\n";
	}
	return 0;
}