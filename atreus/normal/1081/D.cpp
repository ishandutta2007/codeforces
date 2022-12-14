#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> pii;
const int maxn = 1e5 + 10;

int par[maxn], sz[maxn];

int get_par(int v){
	if (par[v] < 0)
		return v;
	return par[v] = get_par(par[v]);
}

int k;

bool merge(int v, int u){
	v = get_par(v), u = get_par(u);
	if (v == u)
		return 0;
	sz[v] += sz[u];
	par[u] = v;
	if (sz[v] == k)
		return 1;
	return 0;
}

pair <int, pii> edge[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	memset(par, -1, sizeof par);
	int n, m;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++){
		int x;
		cin >> x;
		sz[x] ++;
	}
	for (int i = 0; i < m; i++){
		int v, u, w;
		cin >> v >> u >> w;
		edge[i] = {w, {v, u}};
	}
	sort(edge, edge + m);
	for (int i = 0; i < m; i++){
		int v = edge[i].S.F, u = edge[i].S.S;
		if (merge(v, u)){
			for (int j = 0; j < k; j++){
				cout << edge[i].F << " ";
			}
			cout << endl;
			return 0;
		}
	}
}