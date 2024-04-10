#include <bits/stdc++.h>

std::mt19937 rnd(time(0));

const int N = 200005;
const int fib[] = {
	1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 
	144, 233, 377, 610, 987, 1597, 2584, 
	4181, 6765, 10946, 17711, 28657, 46368, 
	75025, 121393, 196418
};

int lev[N];

int n;
std::vector<int> E[N];

int sz[N];

void getsz(int u, int fa) {
	sz[u] = 1;
	for (int v : E[u]) {
		if (v != fa) {
			getsz(v, u);
			sz[u] += sz[v];
		}
	}
}

void find(int Sz, int u, int fa, std::vector<std::pair<int, int>> &res) {
	if (lev[sz[u]] && lev[Sz - sz[u]]) {
		res.emplace_back(u, fa);
	}
	for (int v : E[u]) {
		if (v != fa) {
			find(Sz, v, u, res);
		}
	}
}

bool check(int u) {
	getsz(u, 0);
	if (sz[u] <= 3) {
		return true;
	}
	std::vector<std::pair<int, int>> res;
	find(sz[u], u, 0, res);
	std::shuffle(res.begin(), res.end(), rnd);
	for (auto p : res) {
		int x = p.first, y = p.second;
		if (rnd() & 1) {
			std::swap(x, y);
		}
		auto ix = std::find(E[x].begin(), E[x].end(), y);
		auto iy = std::find(E[y].begin(), E[y].end(), x);
		E[x].erase(ix);
		E[y].erase(iy);
		bool flag = check(x) && check(y);
		E[x].push_back(y);
		E[y].push_back(x);
		return flag;
	}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	for (int i = 1; i < 27; ++i) {
		lev[fib[i]] = i;
	}

	std::cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
	    std::shuffle(E[i].begin(), E[i].end(), rnd);
	}

	if (lev[n] && check(1)) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}