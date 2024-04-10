#include <bits/stdc++.h>

const int N = 1000005;
const int INF = 0x3f3f3f3f;
const long long LIM = 2e8;

int cnt, prime[N];
bool vis[N];
int minp[N];

void init() {
	vis[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) {
			prime[++cnt] = i;
			minp[i] = i;
		}
		for (int j = 1; j <= cnt && 1ll * i * prime[j] < N; ++j) {
			vis[i * prime[j]] = 1;
			minp[i * prime[j]] = prime[j];
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}

std::vector<std::vector<int>> st;

void dfs(std::vector<int> now, long long val) {
	st.push_back(now);
	int lst = !now.empty() ? now.back() : N, k = now.size() + 1;
	now.push_back(0);
	for (int i = 1; i <= lst; ++i) {
		if (val > LIM / prime[k]) {
			break;
		}
		val *= prime[k];
		now.back() = i;
		dfs(now, val);
	}
}

int get_d(const std::vector<int> &d) {
	int s = 1;
	for (int v : d) {
		s *= v + 1;
	}
	return s;
}

std::vector<int> d;

int add(std::vector<int> v, int p, int ad) {
	v.push_back(0);
	v[p] += ad;
	if (v[p] < 0) {
		return -1;
	}
	if (p > 0 && v[p] > v[p - 1]) {
		return -1;
	}
	if (p < (int)v.size() - 1 && v[p] < v[p + 1]) {
		return -1;
	}
	while (!v.empty() && v.back() == 0) {
		v.pop_back();
	}
	auto it = std::lower_bound(st.begin(), st.end(), v);
	if (it == st.end() || *it != v) {
		return -1;
	}
	return it - st.begin();
}

std::vector<std::vector<int>> E;
std::vector<std::vector<int>> dis;
std::vector<std::vector<int>> disd;

void BFS(int s, std::vector<int> &dis) {
	std::vector<int> Q;
	std::fill(dis.begin(), dis.end(), INF);
	dis[s] = 0;
	Q.push_back(s);
	for (int i = 0; i < (int)Q.size(); ++i) {
		int u = Q[i];
		for (int v : E[u]) {
			if (dis[v] == INF) {
				dis[v] = dis[u] + 1;
				Q.push_back(v);
			}
		}
	}
}

int getid(int v) {
	std::vector<int> p;
	while (v > 1) {
		int f = minp[v], c = 0;
		while (v % f == 0) {
			v /= f;
			++c;
		}
		p.push_back(c);
	}
	std::sort(p.begin(), p.end(), std::greater<int>());
	auto it = std::lower_bound(st.begin(), st.end(), p);
	return it - st.begin();
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	init();
	dfs({}, 1);
	std::sort(st.begin(), st.end());

	std::vector<int> vd;
	d.resize(st.size());
	for (int i = 0; i < (int)st.size(); ++i) {
		d[i] = get_d(st[i]);
		vd.push_back(d[i]);
	}
	std::sort(vd.begin(), vd.end());
	vd.erase(std::unique(vd.begin(), vd.end()), vd.end());
	for (int i = 0; i < (int)st.size(); ++i) {
		d[i] = std::lower_bound(vd.begin(), vd.end(), d[i]) - vd.begin();
	}

	E.resize(st.size());
	for (int i = 0; i < (int)st.size(); ++i) {
		for (int j = 0; j <= (int)st[i].size(); ++j) {
			int v1 = add(st[i], j, 1), v2 = add(st[i], j, -1);
			if (~v1) {
				E[i].push_back(v1);
			}
			if (~v2) {
				E[i].push_back(v2);
			}
		}
	}

	dis.resize(st.size(), std::vector<int>(st.size()));
	disd.resize(st.size(), std::vector<int>(vd.size(), INF));
	for (int i = 0; i < (int)st.size(); ++i) {
		BFS(i, dis[i]);
		for (int j = 0; j < (int)st.size(); ++j) {
			disd[i][d[j]] = std::min(disd[i][d[j]], dis[i][j]);
		}
	}

	int T = 1;
	std::cin >> T;
	while (T--) {
		int a, b;
		std::cin >> a >> b;
		a = getid(a);
		b = getid(b);
		int ans = INF;
		for (int i = 0; i < (int)vd.size(); ++i) {
			ans = std::min(ans, disd[a][i] + disd[b][i]);
		}
		std::cout << ans << "\n";
	}
}