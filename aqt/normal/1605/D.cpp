
// Problem : D. Treelabeling
// Contest : Codeforces - Codeforces Round #754 (Div. 2)
// URL : https://codeforces.com/contest/1605/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

vector<int> graph[200005];
int clr[200005];

void dfs(int n){
	for(int e : graph[n]){
		if(clr[e] == 2){
			clr[e] = clr[n] ^ 1;
			dfs(e);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		for(int i = 1; i <= N; i++){
			graph[i].clear();
			clr[i] = 2;		
		}
		for(int i = 1; i < N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		clr[1] = 0;
		dfs(1);
		int cnt = 0;
		for(int i = 1; i <= N; i++){
			cnt += clr[i];
		}
		if(N - cnt < cnt){
			for(int i= 1; i <= N; i++){
				clr[i] ^= 1;
			}
			cnt = N - cnt;
		}
		vector<int> ones;
		vector<int> zero;
		for(int b = 0; b < 20; b++){
			if(cnt>>b&1){
				for(int i = (1<<b); i < 2*(1<<b); i++){
					ones.push_back(i);
				}
			}
			else{
				for(int i = (1<<b); i < min(2*(1<<b), N+1); i++){
					zero.push_back(i);
				}
			}
		}
		for(int i = 1; i <= N; i++){
			if(clr[i] == 0){
				cout << zero.back() << " ";
				zero.pop_back();
			}
			else{
				cout << ones.back() << " ";
				ones.pop_back();
			}
		}
		cout << "\n";
	}
}