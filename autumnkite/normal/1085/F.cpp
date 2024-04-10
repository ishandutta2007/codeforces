#include <bits/stdc++.h>

template<typename _Val, typename _VV = std::plus<_Val>>
class fenwick_tree {
public:
    typedef std::size_t size_type;

protected:
    const _Val E;

    size_type n;
    std::vector<_Val> val;

    _VV fun;

public:
    fenwick_tree() : fenwick_tree(0) {}

    fenwick_tree(size_type _n)
    : E(), n(_n), val(n + 1, E) {}

    fenwick_tree(size_type _n, const _Val &_E)
    : E(_E), n(_n), val(n + 1, E) {}

    size_type size() const {
        return n;
    }

    void modify(size_type x, const _Val &v) {
        for (++x; x <= n; x += x & -x) {
            val[x] = fun(val[x], v);
        }
    }

    _Val query(size_type x) {
        _Val s = E;
        for (; x; x ^= x & -x) {
            s = fun(s, val[x]);
        }
        return s;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;

    auto get_id = [&](char c) {
        if (c == 'R') {
            return 0;
        } else if (c == 'P') {
            return 1;
        } else {
            return 2;
        }
    };

    std::vector<fenwick_tree<int>> T(3, n);
    std::vector<std::set<int>> S(3);

    for (int i = 0; i < n; ++i) {
        T[get_id(s[i])].modify(i, 1);
        S[get_id(s[i])].insert(i);
    }

    auto get_ans = [&]() {
        int ans = 0;
        for (int i = 0; i < 3; ++i) {
            int x = (i + 1) % 3, y = (i + 2) % 3;
            if (S[x].empty()) {
                ans += T[i].query(n);
                continue;
            }
            if (!S[y].empty()) {
                int l = *S[y].begin(), r = *S[y].rbegin();
                ans += T[i].query(r) - T[i].query(l);
                ans += T[i].query(std::min(l, *S[x].begin()));
                ans += T[i].query(n) - T[i].query(std::max(r, *S[x].rbegin()));
            }
        }
        return ans;
    };

    std::cout << get_ans() << "\n";

    for (int i = 0; i < q; ++i) {
        int x;
        char c;
        std::cin >> x >> c;
        --x;
        T[get_id(s[x])].modify(x, -1);
        S[get_id(s[x])].erase(x);
        s[x] = c;
        T[get_id(s[x])].modify(x, 1);
        S[get_id(s[x])].insert(x);
        std::cout << get_ans() << "\n";
    }
}