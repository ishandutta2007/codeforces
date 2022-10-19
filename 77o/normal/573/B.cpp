#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> h(n + 2);
	map<int, vector<int>> mp;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		mp[h[i]].push_back(i);
	}
	vector<int> dist(n + 2, 1e9);
	dist[0] = 0;
	dist[n + 1] = 0;
	queue<int> q;
	q.push(0);
	q.push(n + 1);
	auto it = mp.begin();
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (it != mp.end() && it->first == dist[v]) {
			for (int u : it->second) {
				if (dist[u] == 1e9) {
					q.push(u);
					dist[u] = dist[v];	
				}
			}
			it++;
		}
		if (v - 1 >= 0 && dist[v - 1] == 1e9) {
			dist[v - 1] = dist[v] + 1;
			q.push(v - 1);
		}
		if (v + 1 <= n + 1 && dist[v + 1] == 1e9) {
			dist[v + 1] = dist[v] + 1;
			q.push(v + 1);
		}
	}
	cout << *max_element(dist.begin(), dist.end()) << endl;
	return 0;
}