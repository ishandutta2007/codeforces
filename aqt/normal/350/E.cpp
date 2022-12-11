
// Problem : E. Wrong Floyd
// Contest : Codeforces - Codeforces Round #203 (Div. 2)
// URL : https://codeforces.com/contest/350/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int sp[305];
pair<int, int> srt[305];
bool issp[305];
vector<pair<int, int>> graph;
int oo = INT_MAX/4;
int dist1[305][305], dist2[305][305];

void addedge(int a, int b){
	if(M){
		graph.emplace_back(a, b);
		M--;
		dist1[a][b] = dist1[b][a] = 1;
		dist2[a][b] = dist2[b][a] = 1;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i<=K; i++){
		cin >> sp[i];
		issp[sp[i]] = 1;
	}
	for(int i = 1; i<=N; i++){
		if(!issp[i]){
			srt[i].first = 0;
		}
		else{
			srt[i].first = 1;
		}
		srt[i].second = i;
	}
	sort(srt+1, srt+1+N);
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			dist1[i][j] = dist2[i][j] = oo;
		}
	}
	for(int i = 1; i<=N; i++){
		dist1[i][i] = dist2[i][i] = 0;
	}
	for(int i = 2; i<=N; i++){
		addedge(srt[i].second, srt[1].second);
	}
	for(int i = 2; i<=N; i++){
		for(int j = 2; j<i; j++){
			addedge(srt[i].second, srt[j].second);
		}
	}
	for(int k = 1; k<=N; k++){
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=N; j++){
				dist1[i][j] = min(dist1[i][j], dist1[i][k]+dist1[k][j]);
			}
		}
	}
	for(int k = 1; k<=K; k++){
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=N; j++){
				dist2[i][j] = min(dist2[i][j], dist2[i][sp[k]]+dist2[sp[k]][j]);
			}
		}
	}
	bool pos = 0;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			pos |= (dist1[i][j] != dist2[i][j]);
		}
	}
	if(!pos){
		cout << -1 << "\n";
		return 0;
	}
	for(auto p : graph){
		cout << p.first << " " << p.second << "\n";
	}
}