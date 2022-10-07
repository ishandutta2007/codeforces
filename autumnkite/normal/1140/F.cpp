#include <bits/stdc++.h>

class bigraph {
protected:
    int nA, nB, n;
    std::vector<int> fa, szA, szB;
    std::vector<int> sta;
    long long ans;

public:
    bigraph(int _nA, int _nB)
    : nA(_nA), nB(_nB), n(nA + nB), fa(n), szA(n), szB(n), ans(0) {
        for (int i = 0; i < n; ++i) {
            fa[i] = i;
        }
        for (int i = 0; i < nA; ++i) {
            szA[i] = 1;
        }
        for (int i = 0; i < nB; ++i) {
            szB[nA + i] = 1;
        }
    }

    int find(int x) const {
        return fa[x] == x ? x : find(fa[x]);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(nA + y);
        if (x == y) {
            sta.push_back(-1);
            return false;
        }
        if (szA[x] + szB[x] < szA[y] + szB[y]) {
            std::swap(x, y);
        }
        fa[y] = x;
        ans += 1ll * szA[x] * szB[y] + 1ll * szB[x] * szA[y];
        szA[x] += szA[y];
        szB[x] += szB[y];
        sta.push_back(y);
        return true;
    }

    void undo() {
        int y = sta.back();
        sta.pop_back();
        if (y == -1) {
            return;
        }
        int x = fa[y];
        fa[y] = y;
        szA[x] -= szA[y];
        szB[x] -= szB[y];
        ans -= 1ll * szA[x] * szB[y] + 1ll * szB[x] * szA[y];
    }

    long long get_ans() const {
        return ans;
    }
};

class seg_tree {
    static int enlarge(int n) {
        int res = 1;
        while (res < n) {
            res <<= 1;
        }
        return res;
    }

protected:
    int n, en;
    std::vector<std::vector<std::pair<int, int>>> edge;
    bigraph G;

    void insert(int u, int l, int r, 
                int L, int R, const std::pair<int, int> &e) {
        if (L <= l && r <= R) {
            edge[u].emplace_back(e);
            return;
        }
        int mid = (l + r) >> 1;
        if (L < mid) {
            insert(u << 1, l, mid, L, R, e);
        }
        if (mid < R) {
            insert(u << 1 | 1, mid, r, L, R, e);
        }
    }

    void solve(int u, int l, int r, std::vector<long long> &ans) {
        for (auto [x, y] : edge[u]) {
            G.merge(x, y);
        }
        if (l + 1 == r) {
            ans[l] = G.get_ans();
        } else {
            int mid = (l + r) >> 1;
            solve(u << 1, l, mid, ans);
            solve(u << 1 | 1, mid, r, ans);
        }
        for ([[maybe_unused]] auto tmp : edge[u]) {
            G.undo();
        }
    }

public:
    seg_tree(int _n, int nA, int nB)
    : n(_n), en(enlarge(n) << 1), edge(en), G(nA, nB) {}

    void insert(int l, int r, const std::pair<int, int> &e) {
        insert(1, 0, n, l, r, e);
    }

    std::vector<long long> get_ans() {
        std::vector<long long> ans(n);
        solve(1, 0, n, ans);
        return ans;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q;
    std::cin >> q;
    seg_tree T(q, 300000, 300000);
    std::map<std::pair<int, int>, int> lst;
    for (int i = 0; i < q; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        std::pair<int, int> tmp(x, y);
        if (lst.count(tmp)) {
            T.insert(lst[tmp], i, tmp);
            lst.erase(tmp);
        } else {
            lst[tmp] = i;
        }
    }
    for (auto [e, t] : lst) {
        T.insert(t, q, e);
    }

    for (auto v : T.get_ans()) {
        std::cout << v << " ";
    }
    std::cout << "\n";
}