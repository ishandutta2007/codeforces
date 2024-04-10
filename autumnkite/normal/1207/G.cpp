#include <bits/stdc++.h>

class AC_automaton {
public:
    static const int C = 26;

    struct node {
        node *trans[C];
        node *fail;

        std::vector<node *> son;

        int st, ed;

        node() : trans(), fail(nullptr), st(-1), ed(-1) {}
    };

protected:
    int n;
    node *rt;

    int idx;

    void dfs(node *u) {
        u->st = idx++;
        for (auto v : u->son) {
            dfs(v);
        }
        u->ed = idx;
    }

public:
    AC_automaton() : n(0), rt(nullptr), idx(0) {}

    node *insert(const std::string &s) {
        if (rt == nullptr) {
            rt = new node();
            ++n;
        }
        node *u = rt;
        for (char c : s) {
            node *&v = u->trans[c - 'a'];
            if (v == nullptr) {
                v = new node();
                ++n;
            }
            u = v;
        }
        return u;
    }

    void build() {
        std::vector<node *> Q;
        rt->fail = rt;
        for (int i = 0; i < C; ++i) {
            if (rt->trans[i] == nullptr) {
                rt->trans[i] = rt;
            } else {
                rt->trans[i]->fail = rt;
                Q.push_back(rt->trans[i]);
            }
        }
        for (int k = 0; k < (int)Q.size(); ++k) {
            node *u = Q[k];
            u->fail->son.push_back(u);
            for (int i = 0; i < C; ++i) {
                if (u->trans[i] == nullptr) {
                    u->trans[i] = u->fail->trans[i];
                } else {
                    u->trans[i]->fail = u->fail->trans[i];
                    Q.push_back(u->trans[i]);
                }
            }
        }
        idx = 0;
        dfs(rt);
    }

    node *root() const {
        return rt;
    }

    int size() const {
        return n;
    }
};

template<typename _Val, typename _VV = std::plus<_Val>>
class fenwick_tree {
public:
    typedef std::size_t size_type;

protected:
    const _Val _E;

    size_type n;
    std::vector<_Val> val;

    _VV fun;

public:
    fenwick_tree(size_type _n = 0, const _Val &E = _Val())
    : _E(E), n(_n), val(n + 1, _E) {}

    size_type size() const {
        return n;
    }

    void modify(size_type x, _Val v) {
        for (++x; x <= n; x += x & -x) {
            val[x] = fun(val[x], v);
        }
    }

    _Val query(size_type x) {
        _Val s = _E;
        for (; x; x ^= x & -x) {
            s = fun(s, val[x]);
        }
        return s;
    }
};

typedef AC_automaton::node *anode;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<std::pair<int, char>>> son(n + 1);
    for (int i = 1; i <= n; ++i) {
        int op;
        std::cin >> op;
        int fa;
        char c;
        if (op == 1) {
            std::cin >> c;
            fa = 0;
        } else {
            std::cin >> fa >> c;
        }
        son[fa].emplace_back(i, c);
    }

    int m;
    std::cin >> m;
    AC_automaton A;
    std::vector<std::vector<std::pair<anode, int>>> Q(n + 1);
    for (int i = 0; i < m; ++i) {
        int x;
        std::string s;
        std::cin >> x >> s;
        Q[x].emplace_back(A.insert(s), i);
    }

    A.build();

    fenwick_tree<int> T(A.size());
    std::vector<int> ans(m);
    
    auto dfs = [&](auto self, int u, anode now) -> void {
        T.modify(now->st, 1);
        for (auto [v, id] : Q[u]) {
            ans[id] = T.query(v->ed) - T.query(v->st);
        }
        for (auto [v, c] : son[u]) {
            self(self, v, now->trans[c - 'a']);
        }
        T.modify(now->st, -1);
    };

    dfs(dfs, 0, A.root());
    
    for (int i = 0; i < m; ++i) {
        std::cout << ans[i] << "\n";
    }
}