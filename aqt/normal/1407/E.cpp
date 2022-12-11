
// Problem : E. Egor in the Republic of Dagestan
// Contest : Codeforces - Codeforces Round #669 (Div. 2)
// URL : https://codeforces.com/contest/1407/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> graph[500005];
int dist[2][500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		graph[b].emplace_back(a, c);
	}
	for(int i = 1; i<=N; i++){
		dist[0][i] = INT_MAX/2;
		dist[1][i] = INT_MAX/2;
	}
	dist[0][N] = dist[1][N] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, N));
	while(pq.size()){
		auto p = pq.top();
		pq.pop();
		if(max(dist[0][p.second], dist[1][p.second]) != p.first){
			continue;
		}
		swap(p.first, p.second);
		for(auto e : graph[p.first]){
			if(dist[e.second][e.first] > max(dist[0][p.first], dist[1][p.first]) + 1){
				dist[e.second][e.first] = max(dist[0][p.first], dist[1][p.first]) + 1;
				if(max(dist[0][e.first], dist[1][e.first]) != INT_MAX/2){
					pq.push(make_pair(max(dist[0][e.first], dist[1][e.first]), e.first));
				}
			}
		}
	}
	cout << (max(dist[0][1], dist[1][1]) == INT_MAX/2 ? -1 : max(dist[0][1], dist[1][1])) << "\n";
	for(int n = 1; n<=N; n++){
		if(dist[0][n] > dist[1][n]){
			cout << 0;
		}
		else{
			cout << 1;
		}
	}
}