
// Problem : E. Tree Shuffling
// Contest : Codeforces - Codeforces Round #646 (Div. 2)
// URL : https://codeforces.com/contest/1363/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[200005];
long long cst[200005], init[200005], fin[200005];
long long ans = 0;

int dfs(int n, int p){
	int tot = (init[n] != fin[n]);
	tot *= 2*init[n]-1;
	for(int e : graph[n]){
		if(e != p){
			cst[e] = min(cst[n], cst[e]);
			int k = dfs(e, n);
			if(k < 0 && tot > 0){
				ans += min(abs(k), abs(tot)) * cst[n];
			}
			else if(k > 0 && tot < 0){
				ans += min(abs(k), abs(tot)) * cst[n];
			}
			tot += k;
		}
	}
	return tot;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> cst[i] >> init[i] >> fin[i];
	}	
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	if(dfs(1, 0)){
		cout << -1 << "\n";
	}
	else{
		cout << 2*ans << "\n";
	}
}