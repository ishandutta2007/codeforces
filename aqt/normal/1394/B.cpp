
// Problem : B. Boboniu Walks on Graph
// Contest : Codeforces - Codeforces Round #664 (Div. 1)
// URL : https://codeforces.com/contest/1394/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
vector<pair<int, int>> graph[200005];
vector<int> bs[10][10];
unordered_map<bitset<200005>, int> mp[10];
int tot[10];
bitset<200005> init;

int solve(int k, bitset<200005> state){
	if(k == K+1){
		return ((int)(state.count()) == N);
	}
	if(mp[k].count(state)){
		return mp[k][state];
	}
	int tot = 0;
	for(int d = 0; d<k; d++){
		int good = bs[k][d].size();
		for(int i = 0; i<bs[k][d].size(); i++){
			if(state[bs[k][d][i]]){
				good = i;
				break;
			}
			state[bs[k][d][i]] = 1;
		}
		if(good == bs[k][d].size()){
			tot += solve(k+1, state);
		}
		for(int i =0 ; i<good; i++){
			state[bs[k][d][i]] = 0;
		}
	}
	//return tot;
	return mp[k][state] = tot;
	//return tot;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i<=M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].emplace_back(c, b);
	}
	for(int i = 1; i<=N; i++){
		sort(graph[i].begin(), graph[i].end());
		tot[graph[i].size()]++;
	}
	for(int k = 1; k<=K; k++){
		for(int d = 0; d<k; d++){
			for(int i = 1; i<=N; i++){
				if(graph[i].size() == k){
					bs[k][d].emplace_back(graph[i][d].second);
				}
			}
		}
	}
	cout << solve(1, init);
}