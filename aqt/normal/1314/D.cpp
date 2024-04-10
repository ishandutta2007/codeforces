#include <bits/stdc++.h>

using namespace std;

int N, K;
int numtrials = 10000;
priority_queue<pair<int, pair<int, int>>> pq;
int dist[12][85];
int graph[85][85];
bool state[85];

mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());

int randint(){return uniform_int_distribution<int>(0, 1)(g1);}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			cin >> graph[i][j];
		}
	}
	int ans = 2000000000;
	while(numtrials--){
		for(int i = 2; i<=N; i++){
			state[i] = randint();
		}
		for(int k = 0; k<=K; k++){
			for(int n = 1; n<=N; n++){
				dist[k][n] = ans;
			}
		}
		dist[0][1] = 0;
		pq.push({0, {0, 1}});
		bool done = 1;
		while(pq.size() && done){
			auto p = pq.top();
			pq.pop();
			if(-p.first != dist[p.second.first][p.second.second]){
				continue;
			}
			int k = p.second.first, n = p.second.second;
			for(int e = 1; e<=N; e++){
				if(state[e] != state[n] && dist[k+1][e] > dist[k][n] + graph[n][e]){
					dist[k+1][e] = dist[k][n] + graph[n][e];
					if(k+1 == K && e == 1){
						ans = min(ans, dist[k+1][e]);
						done = 0;
						break;
					}
					if(k+1 != K){
						pq.push({-dist[k+1][e], {k+1, e}});
					}
				}
			}
		}
	}
	cout << ans << "\n";
}