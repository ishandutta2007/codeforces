#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;

int N;
pii dist[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &dist[i].first);
		dist[i].second = i;
	}
}

void add_edge(int a, int b) {
	printf("%d %d\n", a, b);
}

void solve() {
	sort(dist + 1, dist + N + 1, greater <pii> ());
	
	vector <int> chain;
	int mx = dist[1].first;
	for (int i = 1; i <= mx; i++) 
		chain.push_back(2 * dist[i].second - 1);
	chain.push_back(2 * dist[1].second);
	
	for (int i = 0; i < mx; i++)
		add_edge(chain[i], chain[i + 1]);
	
	for (int i = 2; i <= mx; i++) {
		int pos = i + dist[i].first - 2;
		assert(pos < chain.size());
		add_edge(chain[pos], chain[i - 1] + 1);
		if (pos + 1 == chain.size()) 
			chain.push_back(chain[i - 1] + 1);
	}
	
	for (int i = mx + 1; i <= N; i++) 
		if (dist[i].first >= 2) {
			add_edge(2 * dist[i].second - 1, chain[0]);
			add_edge(2 * dist[i].second, chain[dist[i].first - 2]);
		}
		else 
			for (int j = 0; j < 2; j++) {
				add_edge(chain.back(), 2 * dist[i].second - 1 + j);
				chain.push_back(2 * dist[i].second - 1 + j);
			}
}

int main() {
	load();
	solve();
	return 0;
}