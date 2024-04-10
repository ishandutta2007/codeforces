#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int t;
int n, m;
vector<int> v[300300];
bool used[300300];
bool upd[300300];
queue<int> q[2];

void dfs(int now){
	used[now] = 1;
	rep(i, (int)v[now].size()){
		if(!used[v[now][i]]) dfs(v[now][i]);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> m;
		rep(i, n) v[i].clear();
		rep(i, m){
			int a, b;
			cin >> a >> b;
			a--, b--;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		rep(i, n) used[i] = 0;
		dfs(0);
		bool ok = 1;
		rep(i, n) ok &= used[i];
		if(!ok){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		rep(i, n) used[i] = 0, upd[i] = 0;
		used[0] = 1;
		q[0].push(0);
		vector<int> ans;
		while(!q[0].empty() || !q[1].empty()){
			while(!q[0].empty()){
				int now = q[0].front(); q[0].pop();
				if(!upd[now]){
					ans.push_back(now);
					rep(i, (int)v[now].size()){
						if(!used[v[now][i]]) q[1].push(v[now][i]), used[v[now][i]] = 1; 
						upd[v[now][i]] = 1;
					}
				} else q[1].push(now);
			}
			while(!q[1].empty()){
				int now = q[1].front(); q[1].pop();
				rep(i, (int)v[now].size()) if(!used[v[now][i]]) q[0].push(v[now][i]), used[v[now][i]] = 1;
			}
		}
		cout << (int)ans.size() << endl;
		rep(i, (int)ans.size()) cout << ans[i]+1 << " "; cout << endl;
	}
	return 0;
}