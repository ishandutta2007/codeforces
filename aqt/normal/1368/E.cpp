
// Problem : E. Ski Accidents
// Contest : Codeforces - Codeforces Global Round 8
// URL : https://codeforces.com/contest/1368/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N, M;
vector<int> graph[200005];
int dist[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> M;
		for(int i = 1; i<=N; i++){
			graph[i].clear();
			dist[i] = 0;
		}
		while(M--){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}
		vector<int> ans;
		for(int i = 1; i<=N; i++){
			if(dist[i] == 2){
				ans.push_back(i);
			}
			else{
				for(int e : graph[i]){
					dist[e] = max(dist[e], dist[i] + 1);
				}
			}
		}
		cout << ans.size() << "\n";
		for(int n : ans){
			cout << n << " ";
		}
		cout << "\n";
	}
}