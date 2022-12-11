
// Problem : B. Tree Tag
// Contest : Codeforces - Codeforces Round #668 (Div. 1)
// URL : https://codeforces.com/contest/1404/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
vector<int> graph[100005];
int dist[100005];

void dfs(int n, int p){
	for(int e : graph[n]){
		if(e != p){
			dist[e] = dist[n] + 1;
			dfs(e, n);
		}
	}
}

void init(int n){
	dist[n] = 0;
	dfs(n, 0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		int A, B, dA, dB;
		cin >> A >> B >> dA >> dB;
		for(int i =1 ; i<=N; i++){
			graph[i].clear();
		}
		for(int i = 1; i<N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		if(dB <= 2*dA){
			cout << "Alice\n";
			continue;
		}
		init(A);
		if(dist[B] <= dA){
			cout << "Alice\n";
			continue;
		}
		int d1 = max_element(dist+1, dist+1+N) - dist;
		init(d1);
		int d2 = max_element(dist+1, dist+1+N) - dist;
		if(2*dA >= dist[d2]){
			cout << "Alice\n";
		}
		else{
			cout << "Bob\n";
		}
	}
}