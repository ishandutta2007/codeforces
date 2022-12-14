#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 50;

ll d[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u, w;
		cin >> v >> u >> w;
		d[v] += w;
		d[u] -= w;
	}
	set<pair<ll, int> > s1, s2;
	for (int i = 1; i <= n; i++){
		if (d[i] > 0)
			s1.insert({d[i], i});
		if (d[i] < 0)
			s2.insert({-d[i], i});
	}
	vector<pair<pair<int, int>, ll> > ops;
	while (!s1.empty()){
		int v = (*s1.begin()).second;
		int u = (*s2.begin()).second;
		s1.erase(s1.begin());
		s2.erase(s2.begin());
		d[u] = -d[u];
		ll tmp = min(d[v], d[u]);
		ops.push_back({{v, u}, min(d[v], d[u])});
		d[v] -= tmp, d[u] -= tmp;
		d[u] = -d[u];
		if (d[v] != 0)
			s1.insert({d[v], v});
		if (d[u] != 0)
			s2.insert({d[u], u});
	}
	cout << ops.size() << endl;
	for (auto it : ops)
		cout << it.first.first << " " << it.first.second << " " << it.second << endl;
}