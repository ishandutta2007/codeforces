#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;

int a[maxn];
vector<int> g[maxn];
int h[maxn][2];
int Q[maxn];

void bfs(int v, bool w){
	h[v][w] = 0;
	int st = 0, en = 0;
	Q[en ++] = v;
	while (st < en){
		v = Q[st ++];
		for (auto u : g[v]){
			if (h[u][w] == -1){
				h[u][w] = h[v][w] + 1;
				Q[en ++] = u;
			}
		}
	}
}

bool cmp(int v, int u){
	return h[v][0] < h[u][0];
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);	
	}
	memset(h, -1, sizeof h);
	bfs(1, 0);
	bfs(n, 1);
	int answer = 0;
	sort(a, a + k, cmp);
	int now = -n;
	for (int i = 0; i < k; i++){
		answer = max(answer, now + h[a[i]][1] + 1);
		now = max(now, h[a[i]][0]);
	}
	answer = min(answer, h[n][0]);
	cout << answer << '\n';
}