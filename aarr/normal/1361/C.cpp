#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 20) + 7;
int n, t;

int a[N];
int b[N];
vector <pair <int, int> > adj[N];
vector <int> vec;
bool mark[N];

void tur(int v, int pr = 0) {
	while (adj[v].size()) {
		int u = adj[v].back().first, id = adj[v].back().second;
		adj[v].pop_back();
		if (mark[id]) {
			continue;
		}
		mark[id] = true;
		tur(u, id);
	}
	
//	cout << "72 " << v << endl;
	if (pr) {
		vec.push_back(pr);
	}
}

int get(int x) {
	vec.clear();
	for (int i = 0; i < N; i++) {
		adj[i].clear();
	}
	fill(mark, mark + n + 1, false);
	for (int i = 1; i <= n; i++) {
		int u = a[i] % (1 << x), v = b[i] % (1 << x);
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	int v = 0;
	for (int i = 0; i < N; i++) {
		if (adj[i].size() % 2) {
			return false;
		}
		if (adj[i].size()) {
			v = i;
		}
	}
	t = v;
//	cout << "71 " << v << " " << x << endl;
	tur(v);
	if (vec.size() == n) {
		return true;
	}
	return false;
}

int main() {
	ios :: sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	int ans = 0;
	for (int i = 1; i <= 20; i++) {
		if (get(i)) {
			ans = i;
		}
	}
	cout << ans << '\n';
	if (ans == 0) {
		for (int i = 1; i <= n * 2; i++) {
			cout << i << " ";
		}
	}
	
	else {
		get(ans);
		for (auto p : vec) {
			if (a[p] % (1 << ans) == t) {
				cout << p * 2 - 1 << " " << p * 2 << " ";
				t = b[p] % (1 << ans);
			} 
			else {
				cout << p * 2 << " " << p * 2 - 1 << " ";
				t = a[p] % (1 << ans);
			}
		}
	}
	
	return 0;
}