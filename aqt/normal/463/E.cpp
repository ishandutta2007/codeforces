
// Problem : E. Caisa and Tree
// Contest : Codeforces - Codeforces Round #264 (Div. 2)
// URL : https://codeforces.com/contest/463/problem/E
// Memory Limit : 256 MB
// Time Limit : 10000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
const int M = 2000000;
vector<int> pr[2000005];
int ans[2000005];
vector<int> stk[2000005];
int arr[2000005];
vector<int> graph[100005];
int dep[100005];

void dfs(int n, int p){
	ans[n] = 0;
	for(int k : pr[arr[n]]){
		if(stk[k].size()){
			//cout << n << " " << k << endl;
			if(dep[stk[k].back()] >= dep[ans[n]]){
				ans[n] = stk[k].back();
			}
		}
		stk[k].emplace_back(n);
	}
	for(int e : graph[n]){
		if(e != p){
			dep[e] = dep[n] + 1;
			dfs(e, n);
		}
	}
	for(int k : pr[arr[n]]){
		stk[k].pop_back();
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 2; i<=M; i++){
		if(pr[i].empty()){
			for(int j = i; j<=M; j+=i){
				pr[j].emplace_back(i);
			}
		}
	}
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1, 0);
	while(Q--){
		int c, n;
		cin >> c >> n;
		if(c == 1){
			cout << (ans[n] ? ans[n] : -1) << "\n";
		}
		else{
			cin >> arr[n];
			dfs(1, 0); 
		}
	}
}