
// Problem : D. Useful Edges
// Contest : Codeforces - Codeforces Round #709 (Div. 1, based on Technocup 2021 Final Round)
// URL : https://codeforces.com/contest/1483/problem/D
// Memory Limit : 512 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
long long graph[605][605];
long long dist[605][605];
long long qu[605][605];
const long long oo = LLONG_MAX / 10;
long long mx[605][605];

void mymn(long long & a, long long b){
	if(b < a){
		a = b;
	}
}

void mymx(long long & a, long long b){
	if(b > a){
		a = b;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			graph[i][j] = dist[i][j] = oo;
		}
		graph[i][i] = dist[i][i] = 0;
	}
	while(M--){
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = graph[b][a] = c;
		dist[a][b] = dist[b][a] = graph[a][b];
	}
	int Q;
	cin >> Q;
	while(Q--){
		int a, b, c;
		cin >> a >> b >> c;
		qu[a][b] = qu[b][a] = c;
	}
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				mymn(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for(int u = 1; u <= N; u++){
		for(int b = 1; b <= N; b++){
			mx[u][b] = -oo;
			for(int a = 1; a <= N; a++){
				mymx(mx[u][b], qu[b][a] - dist[u][a]);
			}
		}
	}
	int ans = 0;
	for(int u = 1; u <= N; u++){
		for(int v = u + 1; v <= N; v++){
			bool good = 0;
			for(int b = 1; b <= N && !good; b++){
				good |= (graph[u][v] + dist[v][b] <= mx[u][b]);
			}
			ans += good;
		}
	}
	cout << ans;
}