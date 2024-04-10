
// Problem : C. Graph Transpositions
// Contest : Codeforces - Codeforces Round #681 (Div. 1, based on VK Cup 2019-2020 - Final)
// URL : https://codeforces.com/problemset/problem/1442/C
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct diststore{
	int k, d;
	bool operator < (diststore o) const {
		if(k < 20 && o.k < 20){
			return (1<<k) + d < (1<<o.k) + o.d;
		}
		else if(k == o.k){
			return d < o.d;
		}
		return k < o.k;
	}
};

struct event{
	int pty, k, n;
	diststore d;
	bool operator < (event e) const {
		return e.d < d;
	}
};

int N, M;
vector<int> graph[2][200005];
diststore dist[2][25][200005];
const long long MOD = 998244353;
const int oo = INT_MAX/2;
priority_queue<event> pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= M; i++){
		int a, b;
		cin >> a >> b;
		graph[0][a].push_back(b);
		graph[1][b].push_back(a);
	}
	for(int k = 0; k<=20; k++){
		for(int n = 1; n<=N; n++){
			dist[0][k][n] = dist[1][k][n] = {oo, oo};
		}
	}
	dist[0][0][1] = {0, 0};
	pq.push({0, 0, 1, {0, 0}});
	while(pq.size()){
		auto n = pq.top();
		pq.pop();
		dist[n.pty][n.k][n.n].k++;
		if(dist[n.pty][n.k][n.n] < dist[n.pty^1][min(20, n.k+1)][n.n]){
			dist[n.pty^1][min(20, n.k+1)][n.n] = dist[n.pty][n.k][n.n];
			pq.push({n.pty^1, min(20, n.k+1), n.n, dist[n.pty][n.k][n.n]});
		}
		dist[n.pty][n.k][n.n].k--;
		dist[n.pty][n.k][n.n].d++;
		for(int e : graph[n.pty][n.n]){
			if(dist[n.pty][n.k][n.n] < dist[n.pty][n.k][e]){
				dist[n.pty][n.k][e] = dist[n.pty][n.k][n.n];
				pq.push({n.pty, n.k, e, dist[n.pty][n.k][n.n]});
			}
		}
		dist[n.pty][n.k][n.n].d--;
	}
	diststore bst = {oo, oo};
	for(int k = 0; k<=20; k++){
		if(dist[0][k][N] < bst){
			bst = dist[0][k][N];
		}
		if(dist[1][k][N] < bst){
			bst = dist[1][k][N];
		}
	}
	//cout << bst.k << " " << bst.d << endl;
	
	long long ans = 1;
	for(int k = 0; k<bst.k; k++){
		ans *= 2;
		ans %= MOD;
	}
	ans += MOD-1;
	ans %= MOD;
	ans += bst.d;
	ans %= MOD;
	cout << ans;
	
}