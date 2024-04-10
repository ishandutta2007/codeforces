
// Problem : F. Removing Leaves
// Contest : Codeforces - Codeforces Round #656 (Div. 3)
// URL : https://codeforces.com/contest/1385/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
set<int> graph[200005];
set<int> lst[200005];
bool leaf[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		for(int i = 1; i<=N; i++){
			leaf[i] = 0;
			graph[i].clear();
			lst[i].clear();
		}
		for(int i = 1; i<N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].insert(b);
			graph[b].insert(a);
		}
		if(K == 1){
			cout << N-1 << "\n";
			continue;
		}
		queue<int> qu;
		for(int i = 1; i<=N; i++){
			leaf[i] = (graph[i].size() == 1);
			if(leaf[i]){
				lst[*graph[i].begin()].insert(i);
				if(lst[*graph[i].begin()].size()%K == 0){
					qu.push(*graph[i].begin());
				}
			}
		}
		int ans = 0;
		while(qu.size()){
			int n = qu.front();
			qu.pop();
			if(lst[n].size() >= K){
				ans++;
				int T = K;
				for(auto it = lst[n].begin(); T--; it = lst[n].erase(lst[n].begin())){
					graph[n].erase(*it);
				}
				//cout << n << " " << graph[n].size() << "\n";
				if(graph[n].size() == 1){
					lst[*graph[n].begin()].insert(n);
					if(lst[*graph[n].begin()].size()%K == 0){
						qu.push(*graph[n].begin());
					}
				}
			}
		}
		cout << ans << "\n";
	}
}