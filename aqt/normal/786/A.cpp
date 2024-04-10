
// Problem : A. Berzerk
// Contest : Codeforces - Codeforces Round #406 (Div. 1)
// URL : https://codeforces.com/contest/786/problem/A
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int state[2][7005];
bool graph[2][7005][7005];
int indgr[2][7005];
queue<pair<int, int>> qu;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int k = 0; k<2; k++){
		int n;
		cin >> n;
		vector<int> v;
		while(n--){
			int t;
			cin >> t;
			v.push_back(t);
		}
		for(int i = 0; i<N; i++){
			for(int t : v){
				graph[k][i][(i+t)%N] = 1;
				indgr[k][(i+t)%N]++;
			}
		}
	}
	state[0][0] = state[1][0] = 2;
	qu.push({0, 0});
	qu.push({1, 0});
	indgr[0][0] = indgr[1][0] = 0;
	while(qu.size()){
		auto p = qu.front();
		qu.pop();
		int k = p.first, i = p.second;
		if(state[k][i] == 1){
			for(int n = 0; n<N; n++){
				if(graph[k^1][n][i]){
					indgr[k^1][n]--;
					if(!state[k^1][n] && indgr[k^1][n] == 0){
						state[k^1][n] = 2;
						qu.push({k^1, n});
					}
				}
			}
		}
		else{
			for(int n = 0; n<N; n++){
				if(graph[k^1][n][i]){
					if(!state[k^1][n]){
						state[k^1][n] = 1;
						qu.push({k^1, n});
					}
				}
			}
		}
	}
	for(int k = 0; k<2; k++){
		for(int n = 1; n<N; n++){
			if(state[k][n] == 0){
				cout << "Loop ";
			}
			else if(state[k][n] == 1){
				cout << "Win ";
			}
			else{
				cout << "Lose ";
			}
		}
		cout << "\n";
	}
}