# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100051;
int T, n, k;
int b[MAXN];
int a1[MAXN], sz1;
int a2[MAXN], sz2;
int a[MAXN], asz;
int wrkk(){
	for (int i = 1; i <= n; i++){
		if (b[i] < i) return i - 1;
	}
	return n;
}
int d[MAXN];
vector<int> adj[MAXN];
int sz[MAXN];
int q[MAXN], ql, qr;
int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> b[i];
		k = wrkk();
		for (int i = 0; i <= n + 1; i++) adj[i].clear();
		for (int i = 1; i <= n; i++) adj[b[i]].push_back(i);
		for (int i = 0; i <= n + 1; i++) sz[i] = adj[i].size();
		for (int i = 0; i <= n + 1; i++) sort(adj[i].begin(), adj[i].end(), [&](int u, int v){ return sz[u] < sz[v]; });
		ql = 1; qr = 0;
		q[++qr] = 0; q[++qr] = n + 1;
		asz = 0;
		while (ql <= qr){
			int nw = q[ql++];
			if (nw != 0 && nw != n + 1) a[++asz] = nw;
			for (int nxtn : adj[nw]) q[++qr] = nxtn;
		}
		cout << k << '\n';
		for (int i = 1; i <= asz; i++) cout << a[i] << ' ';
		cout << '\n';
	}
	return 0;
}