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

    int n, m;
    std::cin >> n >> m;
    std::vector<std::tuple<int, long long, long long>> q;
    std::vector<long long> v;
    v.push_back(0);
    v.push_back(1ll << n);
    for (int i = 0; i < m; ++i) {
        std::string op;
        std::cin >> op;
        if (op == "block") {
            long long l, r;
            std::cin >> l >> r;
            ++r;
            v.push_back(l);
            v.push_back(r);
            q.emplace_back(0, l, r);
        } else {
            long long x, y;
            std::cin >> x >> y;
            q.emplace_back(1, x, y);
        }
    }
    std::reverse(q.begin(), q.end());

    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    for (int i = 0, tmp = v.size(); i + 1 < tmp; ++i) {
        long long l = v[i], r = v[i + 1] - 1, x = 0;
        for (int j = n - 1; j >= 0; --j) {
            if ((l & 1ll << j) == (r & 1ll << j)) {
                x |= l & (1ll << j);
            } else {
                x |= 1ll << j;
                break;
            }
        }
        v.push_back(x);
    }
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    int tot = (int)v.size() - 1;
    std::vector<std::vector<int>> E(tot);
    for (int i = 0; i < n; ++i) {
        for (int w = 0; w < 2; ++w) {
            for (int j = 0, p = 0; j < tot; ++j) {
                if ((v[j] >> i & 1) == w) {
                    long long x = v[j] ^ (1ll << i);
                    while (p < tot && x >= v[p + 1]) {
                        ++p;
                    }
                    E[j].push_back(p);
                    E[p].push_back(j);
                }
            }
        }
    }
    
    std::vector<bool> vis(tot, true);
    disjoint_set D(tot);
    auto add = [&](int u) {
        vis[u] = true;
        for (int v : E[u]) {
            if (vis[v]) {
                D.merge(u, v);
            }
        }
    };
    for (auto [op, l, r] : q) {
        if (op == 0) {
            int pl = std::lower_bound(v.begin(), v.end(), l) - v.begin();
            int pr = std::lower_bound(v.begin(), v.end(), r) - v.begin();
            for (int i = pl; i < pr; ++i) {
                vis[i] = false;
            }
        }
    }
    for (int i = 0; i < tot; ++i) {
        if (vis[i]) {
            add(i);
        }
    }
    std::vector<bool> ans;
    for (auto [op, l, r] : q) {
        if (op == 0) {
            int pl = std::lower_bound(v.begin(), v.end(), l) - v.begin();
            int pr = std::lower_bound(v.begin(), v.end(), r) - v.begin();
            for (int i = pl; i < pr; ++i) {
                add(i);
            }
        } else {
            int pl = std::upper_bound(v.begin(), v.end(), l) - v.begin() - 1;
            int pr = std::upper_bound(v.begin(), v.end(), r) - v.begin() - 1;
            ans.push_back(D.find(pl) == D.find(pr));
        }
    }
    std::reverse(ans.begin(), ans.end());
    for (auto v : ans) {
        std::cout << (int)v << "\n";
    }
}