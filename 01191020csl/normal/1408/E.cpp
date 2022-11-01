#include<bits/stdc++.h>
using namespace std;
int fa[200001], a[100001], b[100001];
struct edge {
	int u, v;
	edge(int a, int b):u(a),v(b){}
};
bool operator<(const edge &x, const edge &y) {
	return a[x.u] + b[x.v] > a[y.u] + b[y.v];
}
vector<edge> e;
int getfa(int x) {
	if (!fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int j = 1; j <= n; j++) cin >> b[j];
	for (int i = 1; i <= m; i++) {
		int s;
		cin >> s;
		for (int j = 1; j <= s; j++) {
			int x;
			cin >> x;
			e.push_back(edge(i, x));
		}
	}
	sort(e.begin(), e.end());
	long long ans = 0;
	for (int i = 0; i < e.size(); i++) {
		int u = e[i].u, v = e[i].v;
		int p = getfa(u), q = getfa(v + m);
		if (p == q) {
			ans += a[u] + b[v];
			continue;
		}
		fa[p] = q;
	}
	cout << ans << endl;
}