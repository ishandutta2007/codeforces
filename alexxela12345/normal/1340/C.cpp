// #define _GLIBCXX_DEBUG
#ifndef DEBUG
#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
typedef long double ldb;

const int MAXN = (1e4 + 228) * (1e3 + 228);

int dist[MAXN];
char in[MAXN];

int Q[MAXN];
int head = 0;
int tail = 0;

inline int pop() {
	int x = Q[tail++];
	if (tail == MAXN)
		tail = 0;
	in[x] = 0;
	return x;
}

inline void push(int v) {
	if (in[v])
		return;
	Q[head++] = v;
	in[v] = 1;
	if (head == MAXN)
		head = 0;
}

int d[10000 + 228];

signed main() {
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(12);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &d[i]);
	}
	sort(d, d + m);
	int  green, red;
	cin >> green >> red;
	for (int i = 0; i < MAXN; i++) {
		dist[i] = 1e9;
	}
	dist[0] = 0;
	/*set<pair<int, int>>  s;
	s.insert({0, 0});
	while (!s.empty()) {
		auto pp = *s.begin();
		s.erase(s.begin());
		int v = pp.second;
		if (v / (green + 1) == m - 1)
			break;

		int d = pp.first;
		for (auto pp2 : g[v]) {
			if (dist[pp2.first] > d + pp2.second) {
				s.erase({dist[pp2.first], pp2.first});
				dist[pp2.first] = d + pp2.second;
				s.insert({dist[pp2.first], pp2.first});
			}
		}
	}*/
	push(0);
	while (head != tail) {
		int v = pop();
		int i = v / (green + 1);
		int time = v - i * (green + 1);
		vector<pair<int, int>> gg;
		if (time == green) {
			int u = i * (green + 1);
			int ddist = red;
			if (dist[v] + ddist < dist[u]) {
				dist[u] = dist[v] + ddist;
				push(u);
			}
		} else {
			if (i != 0) {
				if (time + d[i] - d[i - 1] <= green) {
					int u = (i - 1) * (green + 1) + time + d[i] - d[i - 1];
					int ddist = d[i] - d[i - 1];
					if (dist[v] + ddist < dist[u]) {
						dist[u] = dist[v] + ddist;
						push(u);
					}
				}
			}
			if (i != m - 1) {
				if (time + d[i + 1] - d[i] <= green) {
					int u = (i + 1) * (green + 1) + time + d[i + 1] - d[i];
					int ddist = d[i + 1] - d[i];
					if (dist[v] + ddist < dist[u]) {
						dist[u] = dist[v] + ddist;
						push(u);
					}
				}
			}
		}
	}

	int min_time = 1e9;
	for (int t = 0; t <= green; t++) {
		min_time = min(min_time, dist[(m - 1) * (green + 1) + t]);
	}
	if (min_time == 1e9) {
		min_time = -1;
	}
	cout << min_time << endl;
}

// If interactive problem remove #define endl '\n'
// CopyPasted part from BenQ:

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/