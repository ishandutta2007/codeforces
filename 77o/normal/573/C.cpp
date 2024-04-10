#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

vector<int> g[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> deg(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	vector<int> used(n + 1);
	queue<int> leaves;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 1) {
			leaves.push(i);
		}
	}
	vector<int> l3(n + 1);
	while (!leaves.empty()) {
		int v = leaves.front();
		leaves.pop();
		for (int u : g[v]) {
			if (deg[u] == 2) {
				deg[u]--;
				leaves.push(u);
				deg[v] = 0;
				used[v] = 1;
			} else if (deg[u]) {
				l3[u]++;
			}
		}
	}
	vector<int> l2(n + 1);
	for (int i = 1; i <= n; i++) {
		if (deg[i] != 3) continue;
		l2[i] = l3[i] == 2;
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int u : g[i]) {
			if (deg[u] > 1)
				cnt += 1 - l2[u];
		}
		if (cnt > 2) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}