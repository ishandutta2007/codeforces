// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int N = 1001;
const int M = 1e6;
vector<pair<int, int>> g[M + 1];
int d[M + 1], cnt[M + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = M; i >= 2; i--) {
		for (int j = i; j <= M; j += i) {
			d[j] = i;
		}
	}
	int sz = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vector<int> divs;
		while (a > 1) {
			if (!divs.empty() && d[a] == divs.back()) {
				divs.pop_back();
			} else {
				divs.push_back(d[a]);
			}
			a /= d[a];
		}
		if (divs.empty()) {
			cout << 1 << endl;
			return 0;
		}
		if (divs.size() == 1) {
			cnt[divs[0]]++;
		}
		if (divs.size() == 2) {
			g[divs[0]].emplace_back(divs[1], ++sz);
			g[divs[1]].emplace_back(divs[0], sz);
		}
	}
	for (int i = 2; i <= M; i++) {
		if (cnt[i] >= 2) {
			cout << 2 << endl;
			return 0;
		}
	}

	int ans = 1e9;
	for (int i = 2; i < N; i++) {
		vector<int> dist(M + 1, 1e9);
		dist[i] = 0;
		queue<pair<int, int>> q;
		q.push({i, -1});
		pair<int, int> lulw{1e9, 1e9};
		while (!q.empty()) {
			int v = q.front().first;
			int from = q.front().second;
			if (dist[v] >= ans - 1) {
				break;
			}
			if (cnt[v]) {
				if (dist[v] < lulw.first) {
					lulw.second = lulw.first;
					lulw.first = dist[v];
				} else if (dist[v] < lulw.second) {
					lulw.second = dist[v];
				}
			}
			q.pop();
			for (auto e : g[v]) {
				if (e.second == from) {
					continue;
				}
				ans = min(ans, dist[v] + dist[e.first] + 1);
				if (dist[v] + 1 < dist[e.first]) {
					dist[e.first] = dist[v] + 1;
					q.push(e);
				}
			}
		}
		ans = min(ans, lulw.first + lulw.second + 2);
	}
	if (ans == 1e9) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}