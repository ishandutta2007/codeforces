#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 205;

int N;
vector <ll> a;
int edge[MAXN][MAXN];
vector <int> adj[MAXN];

void load() {
	scanf("%d", &N);
	while (N--) {
		ll x;
		scanf("%lld", &x);
		if (x)
			a.push_back(x);
	}
}

int bfs(int x, int y) {
	queue <int> Q;
	vector <int> dist(N, -1);
	dist[x] = 0;
	Q.push(x);
	while (!Q.empty()) {
		int tmp = Q.front();
		Q.pop();
		if (tmp == y)
			return dist[tmp];
		for (auto it : adj[tmp])
			if ((tmp != x || it != y) && dist[it] == -1) {
				dist[it] = dist[tmp] + 1;
				Q.push(it);
			}
	}
	return MAXN;
}

int solve() {
	N = a.size();
	
	if (N > 130)
		return 3;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			edge[i][j] = !!(a[i] & a[j]);
			if (i != j && edge[i][j])
				adj[i].push_back(j);
		}
		
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			for (int k = 0; k < j; k++)
				if (edge[i][j] && edge[j][k] && edge[k][i])
					return 3;
					
	int sol = MAXN;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			if (edge[i][j]) 
				sol = min(sol, bfs(i, j) + 1);
	
	return sol == MAXN ? -1 : sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}