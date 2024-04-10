#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <tuple>
#include <vector>

#include <cassert>

#include <deque>
#include <vector>

namespace suisen {
    template <typename T, bool auto_extend = false>
    struct ObjectPool {
        using value_type = T;
        using value_pointer_type = T*;

        template <typename U>
        using container_type = std::conditional_t<auto_extend, std::deque<U>, std::vector<U>>;

        container_type<value_type> pool;
        container_type<value_pointer_type> stock;
        decltype(stock.begin()) it;

        ObjectPool() : ObjectPool(0) {}
        ObjectPool(int siz) : pool(siz), stock(siz) {
            clear();
        }

        int capacity() const { return pool.size(); }
        int size() const { return it - stock.begin(); }

        value_pointer_type alloc() {
            if constexpr (auto_extend) ensure();
            return *it++;
        }

        void free(value_pointer_type t) {
            *--it = t;
        }

        void clear() {
            int siz = pool.size();
            it = stock.begin();
            for (int i = 0; i < siz; i++) stock[i] = &pool[i];
        }

        void ensure() {
            if (it != stock.end()) return;
            int siz = stock.size();
            for (int i = siz; i <= siz * 2; ++i) {
                stock.push_back(&pool.emplace_back());
            }
            it = stock.begin() + siz;
        }
    };
} // namespace suisen

namespace suisen {
    template <typename T, T(*op)(T, T), T(*e)()>
    struct PersistentSegmentTree {
        struct Node;

        using value_type = T;

        using node_type = Node;
        using node_pointer_type = node_type*;

        struct Node {
            static inline ObjectPool<node_type> _pool;

            node_pointer_type _ch[2]{ nullptr, nullptr };
            value_type _dat;

            Node() : _dat(e()) {}

            static node_pointer_type clone(node_pointer_type node) {
                return &(*_pool.alloc() = *node);
            }

            static void update(node_pointer_type node) {
                node->_dat = op(node->_ch[0]->_dat, node->_ch[1]->_dat);
            }

            static bool is_leaf(node_pointer_type node) {
                return not node->_ch[0];
            }

            static node_pointer_type build(const std::vector<value_type>& dat) {
                auto rec = [&](auto rec, int l, int r) -> node_pointer_type {
                    node_pointer_type res = _pool.alloc();
                    if (r - l == 1) {
                        res->_dat = dat[l];
                    } else {
                        int m = (l + r) >> 1;
                        res->_ch[0] = rec(rec, l, m), res->_ch[1] = rec(rec, m, r);
                        update(res);
                    }
                    return res;
                };
                return rec(rec, 0, dat.size());
            }

            static value_type prod_all(node_pointer_type node) {
                return node ? node->_dat : e();
            }
            static value_type prod(node_pointer_type node, int tl, int tr, int ql, int qr) {
                if (tr <= ql or qr <= tl) return e();
                if (ql <= tl and tr <= qr) return node->_dat;
                int tm = (tl + tr) >> 1;
                return op(prod(node->_ch[0], tl, tm, ql, qr), prod(node->_ch[1], tm, tr, ql, qr));
            }

            template <bool do_update, typename F>
            static auto search_node(node_pointer_type node, int siz, int i, F &&f) {
                static std::vector<node_pointer_type> path;

                node_pointer_type res = node;
                if constexpr (do_update) res = clone(res);
                node_pointer_type cur = res;

                for (int l = 0, r = siz; r - l > 1;) {
                    if constexpr (do_update) path.push_back(cur);
                    int m = (l + r) >> 1;
                    if (i < m) {
                        if constexpr (do_update) cur->_ch[0] = clone(cur->_ch[0]);
                        cur = cur->_ch[0];
                        r = m;
                    } else {
                        if constexpr (do_update) cur->_ch[1] = clone(cur->_ch[1]);
                        cur = cur->_ch[1];
                        l = m;
                    }
                }
                f(cur);

                if constexpr (do_update) {
                    while (path.size()) update(path.back()), path.pop_back();
                    return res;
                } else {
                    return;
                }
            }

            static value_type get(node_pointer_type node, int siz, int i) {
                value_type res;
                search_node</* do_update = */false>(node, siz, i, [&](node_pointer_type i_th_node) { res = i_th_node->_dat; });
                return res;
            }
            template <typename F>
            static node_pointer_type apply(node_pointer_type node, int siz, int i, F&& f) {
                return search_node</* do_update = */true>(node, siz, i, [&](node_pointer_type i_th_node) { i_th_node->_dat = f(i_th_node->_dat); });
            }
            static node_pointer_type set(node_pointer_type node, int siz, int i, const value_type& dat) {
                return apply(node, siz, i, [&](const value_type&) { return dat; });
            }

            template <typename F>
            static int max_right(node_pointer_type node, int siz, int l, F&& f) {
                assert(f(e()));
                auto rec = [&](auto rec, node_pointer_type cur, int tl, int tr, value_type& sum) -> int {
                    if (tr <= l) return tr;
                    if (l <= tl) {
                        value_type nxt_sum = op(sum, cur->_dat);
                        if (f(nxt_sum)) {
                            sum = std::move(nxt_sum);
                            return tr;
                        }
                        if (tr - tl == 1) return tl;
                    }
                    int tm = (tl + tr) >> 1;
                    int res_l = rec(rec, cur->_ch[0], tl, tm, sum);
                    return res_l != tm ? res_l : rec(rec, cur->_ch[1], tm, tr, sum);
                };
                value_type sum = e();
                return rec(rec, node, 0, siz, sum);
            }
            template <typename F>
            static int min_left(node_pointer_type node, int siz, int r, F&& f) {
                assert(f(e()));
                auto rec = [&](auto rec, node_pointer_type cur, int tl, int tr, value_type& sum) -> int {
                    if (r <= tl) return tl;
                    if (tr <= r) {
                        value_type nxt_sum = op(cur->_dat, sum);
                        if (f(nxt_sum)) {
                            sum = std::move(nxt_sum);
                            return tl;
                        }
                        if (tr - tl == 1) return tr;
                    }
                    int tm = (tl + tr) >> 1;
                    int res_r = rec(rec, cur->_ch[1], tm, tr, sum);
                    return res_r != tm ? res_r : rec(rec, cur->_ch[0], tl, tm, sum);
                };
                value_type sum = e();
                return rec(rec, node, 0, siz, sum);
            }

            template <typename OutputIterator>
            static void dump(node_pointer_type node, OutputIterator it) {
                if (not node) return;
                auto rec = [&](auto rec, node_pointer_type cur) -> void {
                    if (is_leaf(cur)) {
                        *it++ = cur->_dat;
                    } else {
                        rec(rec, cur->_ch[0]), rec(rec, cur->_ch[1]);
                    }
                };
                rec(rec, node);
            }
            static std::vector<value_type> dump(node_pointer_type node) {
                std::vector<value_type> res;
                dump(node, std::back_inserter(res));
                return res;
            }
        };

        PersistentSegmentTree() : _n(0), _root(nullptr) {}
        explicit PersistentSegmentTree(int n) : PersistentSegmentTree(std::vector<value_type>(n, e())) {}
        PersistentSegmentTree(const std::vector<value_type>& dat) : _n(dat.size()), _root(node_type::build(dat)) {}

        static void init_pool(int siz) {
            node_type::_pool = ObjectPool<node_type>(siz);
        }
        static void clear_pool() {
            node_type::_pool.clear();
        }

        value_type prod_all() {
            return node_type::prod_all(_root);
        }
        value_type prod(int l, int r) {
            assert(0 <= l and l <= r and r <= _n);
            return node_type::prod(_root, 0, _n, l, r);
        }
        value_type operator()(int l, int r) {
            return prod(l, r);
        }

        value_type get(int i) {
            assert(0 <= i and i < _n);
            return node_type::get(_root, _n, i);
        }
        value_type operator[](int i) {
            return get(i);
        }

        template <typename F>
        PersistentSegmentTree apply(int i, F&& f) {
            assert(0 <= i and i < _n);
            return PersistentSegmentTree(_n, node_type::apply(_root, _n, i, std::forward<F>(f)));
        }
        PersistentSegmentTree set(int i, const value_type& v) {
            assert(0 <= i and i < _n);
            return PersistentSegmentTree(_n, node_type::set(_root, _n, i, v));
        }

        template <typename F>
        int max_right(int l, F&& f) {
            assert(0 <= l and l <= _n);
            return node_type::max_right(_root, _n, l, std::forward<F>(f));
        }
        template <bool(*pred)(value_type)>
        static int max_right(int l) {
            return max_right(l, pred);
        }
        template <typename F>
        int min_left(int r, F&& f) {
            assert(0 <= r and r <= _n);
            return node_type::min_left(_root, _n, r, std::forward<F>(f));
        }
        template <bool(*pred)(value_type)>
        static int min_left(int r) {
            return min_left(r, pred);
        }

        template <typename OutputIterator>
        void dump(OutputIterator it) {
            node_type::dump(_root, it);
        }
        std::vector<value_type> dump() {
            return node_type::dump(_root);
        }

    private:
        int _n;
        node_pointer_type _root;
        PersistentSegmentTree(int n, node_pointer_type root) : _n(n), _root(root) {}
    };
}

struct Data {
    long long csum, rsum;
 
    long long sum(long long time) const {
        return csum + rsum * time;
    }
};
Data op(Data x, Data y) {
    return Data { x.csum + y.csum, x.rsum + y.rsum };
}
Data e() {
    return Data { 0, 0 };
}
 
using Tree = suisen::PersistentSegmentTree<Data, op, e>;

constexpr int T = 200010;
 
int main() {
    Tree::init_pool(6000000);
 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n;
    std::cin >> n;
    std::vector<long long> r(n), c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> c[i] >> r[i];
    }
 
    int m;
    std::cin >> m;
    std::vector<long long> t(m), h(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> t[i] >> h[i];
    }
 
    std::vector<std::vector<int>> upd(T);
    for (int i = 0; i < n; ++i) {
        long long time = (c[i] + r[i] - 1) / r[i];
        if (time < T) {
            upd[time].push_back(i);
        }
    }
 
    std::vector<Tree> ts(T);
 
    std::vector<Data> init;
    for (int i = 0; i < n; ++i) init.push_back(Data { 0, r[i] });
 
    std::reverse(init.begin(), init.end());
 
    ts[0] = Tree(init);
    for (int time = 1; time < T; ++time) {
        ts[time] = ts[time - 1];
        for (int i : upd[time]) ts[time] = ts[time].set(n - i - 1, Data { c[i], 0 });
    }
 
    std::deque<std::tuple<int, int, int, long long>> blocks;
    for (int i = 0; i < n; ++i) {
        blocks.emplace_back(i, i + 1, 0, c[i]);
    }
 
    long long ans = 0;
    for (int j = 0; j < m; ++j) {
        while (h[j] and blocks.size()) {
            auto [fr, to, s, x] = blocks.front();
            blocks.pop_front();
            if (to - fr == 1) {
                long long cx = std::min(c[fr], x + (t[j] - s) * r[fr]);
                if (cx <= h[j]) {
                    h[j] -= cx;
                    continue;
                }
                blocks.emplace_front(fr, to, t[j], cx - h[j]);
                h[j] = 0;
                break;
            }
            assert(x == 0);
            int elapsed = t[j] - s;
            long long all_sum = ts[elapsed].prod(n - to, n - fr).sum(elapsed);
            if (all_sum <= h[j]) {
                h[j] -= all_sum;
                continue;
            }
            int i = n - ts[elapsed].min_left(n - fr, [&](const Data &data) { return data.sum(elapsed) <= h[j]; });
            h[j] -= ts[elapsed].prod(n - i, n - fr).sum(elapsed);
            long long cx = std::min(c[i], (t[j] - s) * r[i]);
            assert(cx >= h[j]);
            if (i + 1 < to) blocks.emplace_front(i + 1, to, s, x);
            blocks.emplace_front(i, i + 1, t[j], cx - h[j]);
            h[j] = 0;
            break;
        }
        int to = blocks.empty() ? n : std::get<0>(blocks.front());
        if (to) {
            blocks.emplace_front(0, to, t[j], 0);
        }
        if (h[j]) ans += h[j];
    }
 
    std::cout << ans << std::endl;
 
    return 0;
}