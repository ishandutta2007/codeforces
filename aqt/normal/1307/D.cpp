
// Problem : D. Cow and Fields
// Contest : Codeforces Round #621 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1307/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<int> graph[200005];
bool arr[200005];
int dist[2][200005];
pair<pair<int, int>, pair<int, int>> mx;

void bfs(int s, int t){
	queue<int> qu;
	qu.push(s);
	for(int i = 1; i<=N; i++){
		dist[t][i] = INT_MAX/3;
	}
	dist[t][s] = 0;
	while(qu.size()){
		int n = qu.front();
		//cout << t << " " << n << endl;
		qu.pop();
		for(int e : graph[n]){
			//cout << e << endl;
			if(dist[t][e] > dist[t][n] + 1){
				qu.push(e);
				dist[t][e] = dist[t][n] + 1;
			}
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i<=K; i++){
		int n;
		cin >> n;
		arr[n] = 1;
	}
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs(1, 0);
	bfs(N, 1);
	vector<pair<int, int>> v;
	for(int i = 1; i<=N; i++){
		if(arr[i]){
			pair<int, int> p = {dist[0][i], dist[1][i]};
			p.second -= p.first;
			swap(p.first, p.second);
			v.push_back(p);
		}
	}
	sort(v.begin(), v.end(), greater<pair<int ,int>>());
	int ans = 0, mx = 0;
	bool b = 0;
	for(auto p : v){
		//cout << p.first << " " << p.second << endl;
		if(b) ans = max(ans, p.first+p.second+mx);
		mx = max(mx, p.second);
		b = 1;
	}
	cout << min(dist[0][N], ans+1) << endl;
}