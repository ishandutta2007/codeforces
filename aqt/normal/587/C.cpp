
// Problem : C. Duff in the Army
// Contest : Codeforces - Codeforces Round #326 (Div. 1)
// URL : https://codeforces.com/problemset/problem/587/C
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
vector<int> graph[100005];
vector<int> pq[17][100005];
int tbl[17][100005];
int dep[100005];
priority_queue<int> ppq;
vector<int> vec;

void dfs(int n){
	for(int e : graph[n]){
		if(e != tbl[0][n]){
			tbl[0][e] = n;
			dep[e] = dep[n] + 1;
			dfs(e);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 1; i<=M; i++){
		int n;
		cin >> n;
		pq[0][n].emplace_back(i);
	}
	dep[1] = 1;
	dfs(1);
	for(int n = 1; n<=N; n++){
		sort(pq[0][n].begin(), pq[0][n].end());
		while(pq[0][n].size() > 10){
			pq[0][n].pop_back();
		}
	}
	for(int d = 1; d<=16; d++){
		for(int n = 1; n<=N; n++){
			tbl[d][n] = tbl[d-1][tbl[d-1][n]];
			for(int t : pq[d-1][n]){
				pq[d][n].emplace_back(t);
			}
			for(int t : pq[d-1][tbl[d-1][n]]){
				pq[d][n].emplace_back(t);
			}
			sort(pq[d][n].begin(), pq[d][n].end());
			while(pq[d][n].size() > 10){
				pq[d][n].pop_back();
			}
		}
	}
	while(Q--){
		int n, u, v;
		cin >> u >> v >> n;
		if(dep[u] < dep[v]){
			swap(u, v);
		}
		for(int d = 16; d>=0; d--){
			if(dep[tbl[d][u]] >= dep[v]){
				for(int t : pq[d][u]){
					ppq.push(t);
					if(ppq.size() > n){
						ppq.pop();
					}
				}
				u = tbl[d][u];
			}
		}
		if(u == v){
			for(int t : pq[0][v]){
				ppq.push(t);
				if(ppq.size() > n){
					ppq.pop();
				}
			}
		}
		else{
			for(int d = 16; d>=0; d--){
				if(tbl[d][u] != tbl[d][v]){
					for(int t : pq[d][u]){
						ppq.push(t);
						if(ppq.size() > n){
							ppq.pop();
						}						
					}
					for(int t : pq[d][v]){
						ppq.push(t);
						if(ppq.size() > n){
							ppq.pop();
						}					
					}
					u = tbl[d][u];
					v = tbl[d][v];
				}
			}
			for(int t : pq[1][u]){
				ppq.push(t);
				if(ppq.size() > n){
					ppq.pop();
				}			
			}
			for(int t : pq[0][v]){
				ppq.push(t);
				if(ppq.size() > n){
					ppq.pop();
				}			
			}
		}
		while(ppq.size()){
			vec.emplace_back(ppq.top());
			ppq.pop();
		}
		cout << vec.size() << " ";
		for(int i = (vec.empty() ? -1 : vec.size()-1); i>=0; i--){
			cout << vec[i] << " ";
		}
		cout << "\n";
		vec.clear();
	}
}