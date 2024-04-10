#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10;

vector<int> g[maxn];
int Q[maxn], head = 0, tail = 0;
int h[maxn], cnt[maxn], p[maxn];

void bfs(int src){
	memset(h, -1, sizeof h);
	h[src] = 0;
	Q[head ++] = src;
	while (tail < head){
		int v = Q[tail ++];
		for (auto u : g[v]){
			if (h[u] == -1){
				h[u] = h[v] + 1;
				Q[head ++] = u;
				cnt[u] = 1;
			}
			else if (h[u] == h[v] + 1)
				cnt[u] ++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u;
		cin >> v >> u;
		g[u].push_back(v);
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> p[i];
	bfs(p[k-1]);
	int mnm = 0, mxm = 0;
	for (int i = 0; i < k - 1; i++){
		int v = p[i], u = p[i+1];
		if (h[v] != h[u] + 1)
			mnm ++, mxm ++;
		else if (cnt[v] > 1)
			mxm ++;
	}
	cout << mnm << " " << mxm << endl;
}