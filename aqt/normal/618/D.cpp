
// Problem : D. Hamiltonian Spanning Tree
// Contest : Codeforces - Wunder Fund Round 2016 (Div. 1 + Div. 2 combined)
// URL : https://codeforces.com/contest/618/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, X, Y;
int dgr[200005];
vector<int> graph[200005];

int dfs(int n, int p){
	int cnt = 0;
	dgr[n] = 0;
	for(int e : graph[n]){
		if(e != p){
			dgr[n]++;
			int t = dfs(e, n);
			cnt += t;
		}
	}
	if(dgr[n] > 2){
		cnt += dgr[n]-2;
	}
	if(dgr[n] >= 2 && p){
		cnt++;
		dgr[p]--;
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> X >> Y;
	long long ans = 0;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		dgr[a]++, dgr[b]++;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	if(X < Y){
		long long k = dfs(1, 0);
		cout << Y*k + (N-1-k)*X << "\n";
	}
	else{
		cout << 1LL*Y*(N-1) + (*max_element(dgr, dgr+1+N) == N-1)*(X-Y);
	}
}