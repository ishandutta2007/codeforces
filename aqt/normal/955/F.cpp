
// Problem : F. Heaps
// Contest : Codeforces - Codeforces Round #471 (Div. 2)
// URL : https://codeforces.com/contest/955/problem/F
// Memory Limit : 512 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[300005];
int mdp[20][300005];
int cdp[20][300005];
int mdep[300005];
int fre[300005];
long long ans = 0;

void dfs(int n){
	cdp[1][n] = N;
	mdep[n] = 1;
	for(int e : graph[n]){
		graph[e].erase(find(graph[e].begin(), graph[e].end(), n));
		dfs(e);
		mdep[n] = max(mdep[n], mdep[e] + 1);
		for(int k = 1; k<20; k++){
			mdp[k][n] = max(mdp[k][n], mdp[k][e]);
		}
	}
	int dgr = graph[n].size();
	for(int k = 2; k<20; k++){
		fill(fre, fre+dgr+2, 0);
		for(int e : graph[n]){
			fre[min(dgr, cdp[k-1][e])]++;
		}
		for(int d = dgr; d; d--){
			fre[d] += fre[d+1];
			if(fre[d] >= d){
				cdp[k][n] = d;
				break;
			}
		}
	}
	ans += mdep[n];
	for(int k = 1; k<20; k++){
		mdp[k][n] = max(mdp[k][n], cdp[k][n]);
		//cout << mdp[k][n] << "\n";
		if(mdp[k][n] >= 2){
			//ans += 1LL*(mdp[k][n]+2)*(mdp[k][n]-1)/2;
			ans += mdp[k][n] - 1;
		}
	}
	//cout << ans << " " << n << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	cout << ans;
}