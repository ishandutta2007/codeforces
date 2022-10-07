#include <bits/stdc++.h>

class disjoint_set {
public:
	typedef std::size_t size_type;

protected:
	std::vector<size_type> fa;

public:
	disjoint_set(size_type n = 0) : fa(n) {
		std::iota(fa.begin(), fa.end(), 0);
	}

	size_type find(size_type x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	bool merge(size_type x, size_type y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		fa[y] = x;
		return true;
	}
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, q, s, d;
    std::cin >> n >> q >> s >> d;
    --s;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::pair<int, int>> edges;
    auto add = [&](int i, int j) {
        if (0 <= j && j < n) {
            edges.emplace_back(i, j);
        }
        if (0 <= j - 1 && j - 1 < n) {
            edges.emplace_back(i, j - 1);
        }
        if (0 <= j + 1 && j + 1 < n) {
            edges.emplace_back(i, j + 1);
        }
    };
    for (int i = 0, p = 0, q = 0; i < n; ++i) {
        while (p < n && a[i] - a[p] > d) {
            ++p;
        }
        while (q < n && a[q] - a[i] < d) {
            ++q;
        }
        add(i, p);
        add(i, q);
    }
    std::sort(edges.begin(), edges.end(), 
    [&](std::pair<int, int> x, std::pair<int, int> y) {
        return abs(abs(a[x.first] - a[x.second]) - d)
             < abs(abs(a[y.first] - a[y.second]) - d);
    });

    disjoint_set D(n);
    std::vector<std::vector<int>> E(n);
    for (auto [u, v] : edges) {
        if (D.merge(u, v)) {
            E[u].push_back(v);
            E[v].push_back(u);
        }
    }

    std::vector<int> mx(n);

    auto dfs = [&](auto self, int u, int fa) -> void {
        for (int v : E[u]) {
            if (v != fa) {
                mx[v] = std::max(mx[u], abs(abs(a[u] - a[v]) - d));
                self(self, v, u);
            }
        }
    };

    dfs(dfs, s, -1);
    
    while (q--) {
        int u, k;
        std::cin >> u >> k;
        --u;
        if (mx[u] <= k) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
}