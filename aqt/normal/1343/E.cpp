
// Problem : E. Weights Distributing
// Contest : Codeforces - Codeforces Round #636 (Div. 3)
// URL : https://codeforces.com/problemset/problem/1343/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
vector<int> graph[200005];
long long arr[600005];
long long dist[3][200005];
int N, M, A, B, C;

void bfs(int s, int t){
	queue<int> qu;
	qu.push(s);
	fill(dist[t], dist[t]+1+N, LLONG_MAX/2);
	dist[t][s] = 0;
	while(qu.size()){
		int n = qu.front();
		qu.pop();
		for(int e : graph[n]){
			if(dist[t][e] > dist[t][n] + 1){
				dist[t][e] = dist[t][n] + 1;
				qu.push(e);
			}
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> M >> A >> B >> C;
		for(int i = 1; i<=N; i++){
			graph[i].clear();
		}
		for(int i = 1; i<=M; i++){
			cin >> arr[i];
			arr[i+M] = 0;
			arr[i+2*M] = 0;
		}
		for(int i = 1; i<=M; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		sort(arr+1, arr+1+M);
		partial_sum(arr, arr+1+3*M, arr);
		bfs(B, 0);
		bfs(A, 1);
		bfs(C, 2);
		long long ans = LLONG_MAX;
		for(int i =1 ; i<=N; i++){
			int a = dist[0][i];
			int b = dist[1][i] + dist[2][i];
			//cout << a << " " << b << endl;
			//cout << " " << arr[a] << " " << arr[b+a] << endl;
			if(a+b <= M){
				ans = min(ans, 2*arr[a] + arr[b+a] - arr[a]);
			}
		}
		cout << ans << "\n";
	}
}