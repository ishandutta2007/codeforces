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

    void modify(size_type x, _Val v) {
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

    int n, t;
    std::cin >> n >> t;
    std::vector<int> sum(n + 1, -1);
    fenwick_tree<int> T(n);
    for (int i = 0; i < t; ++i) {
        int k;
        std::cin >> k;
        int l = 0, r = n;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (sum[mid] == -1) {
                std::cout << "? " << 1 << " " << mid << std::endl;
                std::cin >> sum[mid];
                sum[mid] -= T.query(mid);
            }
            int v = mid - (sum[mid] + T.query(mid));
            if (v >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        std::cout << "! " << r << std::endl;
        T.modify(r - 1, 1);
    }
}