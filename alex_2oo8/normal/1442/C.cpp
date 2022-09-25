#include <bits/stdc++.h>

using namespace std;

const int MX = 200000, LOG = 20, md = 998244353;

struct dist_t {
	int k, x;
	
	dist_t(int k = 2 * MX, int x = MX) : k(k), x(x) { }
	
	bool operator < (const dist_t& rhs) const {
		if (k != rhs.k) return k < rhs.k;
		return x < rhs.x;
	}
	
	long long get() const {
		if (k < 30) return (1 << k) + x;
		
		return ((long long)(k) << 40) + x;
	}
};

vector<int> G[2][MX];
dist_t dist[MX][LOG + 2];

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	for (int i = 0, u, v; i < m; i++) {
		ignore = scanf("%d %d", &u, &v);
		u--; v--;
		G[0][u].emplace_back(v);
		G[1][v].emplace_back(u);
	}
	
	set<tuple<long long, dist_t, int>> queue;
	
	auto f = [](int k) {
		if (k < LOG) return k;
		else return k % 2 == LOG % 2 ? LOG : LOG + 1;
	};
	
	auto update = [&](int v, int k, int x) {
		int kk = f(k);
		
		dist_t here(k, x);
		if (here.get() < dist[v][kk].get()) {
			dist[v][kk] = here;
			queue.emplace(here.get(), here, v);
		}
	};
	
	update(0, 0, 0);
	
	while (queue.empty() == false) {
		auto it = queue.begin();
		dist_t d;
		int v;
		tie(ignore, d, v) = *it;
		
		queue.erase(it);
		
		if (dist[v][f(d.k)].get() < d.get()) continue;
		
		update(v, d.k + 1, d.x);
		
		for (int u : G[d.k % 2][v]) {
			update(u, d.k, d.x + 1);
		}
	}
	
	dist_t ans;
	for (auto& here : dist[n - 1]) {
		if (here.get() < ans.get()) ans = here;
	}
	
	int val = 1;
	for (int i = 0; i < ans.k; i++) val = 2 * val % md;
	
	val += ans.x - 1;
	val %= md;
	
	printf("%d\n", val);
	
	return 0;
}