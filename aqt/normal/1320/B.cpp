
// Problem : B. Navigation System
// Contest : Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round)
// URL : https://codeforces.com/contest/1320/problem/B
// Memory Limit : 512.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<int> rgraph[200005];
vector<int> graph[200005];
int dist[200005];
int arr[200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int a, b;		
		cin >> a >> b;
		graph[a].push_back(b);
		rgraph[b].push_back(a);
	}
	cin >> K;
	for(int i =1; i<=K; i++){
		cin >> arr[i];
	}
	queue<int> qu;
	qu.push(arr[K]);
	fill(dist+1, dist+1+N, INT_MAX/2);
	dist[arr[K]] = 0;
	while(qu.size()){
		int n = qu.front();
		qu.pop();
		for(int e : rgraph[n]){
			if(dist[e] > dist[n] + 1){
				dist[e] = dist[n] + 1;
				qu.push(e);
			}
		}
	}
	int mn = 0, mx = 0;
	for(int i = 1; i<K; i++){
		int cnt = 0, md = INT_MAX/2;
		for(int e : graph[arr[i]]){
			if(dist[e] < md){
				md = dist[e];
				cnt = 1;
			}
			else if(dist[e] == md){
				cnt++;
			}
		}
		if(dist[arr[i+1]] != md){
			mx++, mn++;
		}
		else if(dist[arr[i+1]] == md && cnt == 1){
			
		}
		else {
			mx++;
		}
	}
	cout << mn << " " << mx << "\n";
}