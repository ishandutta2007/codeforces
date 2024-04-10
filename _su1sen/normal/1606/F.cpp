// #pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>

#include <limits>
#include <type_traits>

namespace suisen {
// ! utility
template <typename ...Types>
using constraints_t = std::enable_if_t<std::conjunction_v<Types...>, std::nullptr_t>;
template <bool cond_v, typename Then, typename OrElse>
constexpr decltype(auto) constexpr_if(Then&& then, OrElse&& or_else) {
    if constexpr (cond_v) {
        return std::forward<Then>(then);
    } else {
        return std::forward<OrElse>(or_else);
    }
}

// ! function
template <typename ReturnType, typename Callable, typename ...Args>
using is_same_as_invoke_result = std::is_same<std::invoke_result_t<Callable, Args...>, ReturnType>;
template <typename F, typename T>
using is_uni_op = is_same_as_invoke_result<T, F, T>;
template <typename F, typename T>
using is_bin_op = is_same_as_invoke_result<T, F, T, T>;

template <typename Comparator, typename T>
using is_comparator = std::is_same<std::invoke_result_t<Comparator, T, T>, bool>;

// ! integral
template <typename T, typename = constraints_t<std::is_integral<T>>>
constexpr int bit_num = std::numeric_limits<std::make_unsigned_t<T>>::digits;
template <typename T, unsigned int n>
struct is_nbit { static constexpr bool value = bit_num<T> == n; };
template <typename T, unsigned int n>
static constexpr bool is_nbit_v = is_nbit<T, n>::value;

// ?
template <typename T>
struct safely_multipliable {};
template <>
struct safely_multipliable<int> { using type = long long; };
template <>
struct safely_multipliable<long long> { using type = __int128_t; };
template <>
struct safely_multipliable<float> { using type = float; };
template <>
struct safely_multipliable<double> { using type = double; };
template <>
struct safely_multipliable<long double> { using type = long double; };
template <typename T>
using safely_multipliable_t = typename safely_multipliable<T>::type;

} // namespace suisen

// ! type aliases
using i128 = __int128_t;
using u128 = __uint128_t;
using ll = long long;
using uint = unsigned int;
using ull  = unsigned long long;

template <typename T> using vec  = std::vector<T>;
template <typename T> using vec2 = vec<vec <T>>;
template <typename T> using vec3 = vec<vec2<T>>;
template <typename T> using vec4 = vec<vec3<T>>;

template <typename T>
using pq_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T, typename U>
using umap = std::unordered_map<T, U>;

// ! macros (capital: internal macro)
#define OVERLOAD2(_1,_2,name,...) name
#define OVERLOAD3(_1,_2,_3,name,...) name
#define OVERLOAD4(_1,_2,_3,_4,name,...) name

#define REP4(i,l,r,s)  for(std::remove_reference_t<std::remove_const_t<decltype(r)>>i=(l);i<(r);i+=(s))
#define REP3(i,l,r)    REP4(i,l,r,1)
#define REP2(i,n)      REP3(i,0,n)
#define REPINF3(i,l,s) for(std::remove_reference_t<std::remove_const_t<decltype(l)>>i=(l);;i+=(s))
#define REPINF2(i,l)   REPINF3(i,l,1)
#define REPINF1(i)     REPINF2(i,0)
#define RREP4(i,l,r,s) for(std::remove_reference_t<std::remove_const_t<decltype(r)>>i=(l)+fld((r)-(l)-1,s)*(s);i>=(l);i-=(s))
#define RREP3(i,l,r)   RREP4(i,l,r,1)
#define RREP2(i,n)     RREP3(i,0,n)

#define rep(...)    OVERLOAD4(__VA_ARGS__, REP4   , REP3   , REP2   )(__VA_ARGS__)
#define rrep(...)   OVERLOAD4(__VA_ARGS__, RREP4  , RREP3  , RREP2  )(__VA_ARGS__)
#define repinf(...) OVERLOAD3(__VA_ARGS__, REPINF3, REPINF2, REPINF1)(__VA_ARGS__)

#define CAT_I(a, b) a##b
#define CAT(a, b) CAT_I(a, b)
#define UNIQVAR(tag) CAT(tag, __LINE__)
#define loop(n) for (std::remove_reference_t<std::remove_const_t<decltype(n)>> UNIQVAR(loop_variable) = n; UNIQVAR(loop_variable) --> 0;)

#define all(iterable) (iterable).begin(), (iterable).end()
#define input(type, ...) type __VA_ARGS__; read(__VA_ARGS__)

// ! I/O utilities

// pair
template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U> &a) {
    return out << a.first << ' ' << a.second;
}
// tuple
template <unsigned int N = 0, typename ...Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...> &a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return out;
    } else {
        out << std::get<N>(a);
        if constexpr (N + 1 < std::tuple_size_v<std::tuple<Args...>>) {
            out << ' ';
        }
        return operator<<<N + 1>(out, a);
    }
}
// vector
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> &a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}
inline void print() { std::cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head &head, const Tail &...tails) {
    std::cout << head;
    if (sizeof...(tails)) std::cout << ' ';
    print(tails...);
}
template <typename Iterable>
auto print_all(const Iterable& v, std::string sep = " ", std::string end = "\n") -> decltype(std::cout << *v.begin(), void()) {
    for (auto it = v.begin(); it != v.end();) {
        std::cout << *it;
        if (++it != v.end()) std::cout << sep;
    }
    std::cout << end;
}

// pair
template <typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T, U> &a) {
    return in >> a.first >> a.second;
}
// tuple
template <unsigned int N = 0, typename ...Args>
std::istream& operator>>(std::istream& in, std::tuple<Args...> &a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return in;
    } else {
        return operator>><N + 1>(in >> std::get<N>(a), a);
    }
}
// vector
template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T> &a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}
template <typename ...Args>
void read(Args &...args) {
    ( std::cin >> ... >> args );
}

// ! integral utilities

// Returns pow(-1, n)
template <typename T>
constexpr inline int pow_m1(T n) {
    return -(n & 1) | 1;
}
// Returns pow(-1, n)
template <>
constexpr inline int pow_m1<bool>(bool n) {
    return -int(n) | 1;
}

// Returns floor(x / y)
template <typename T>
constexpr inline T fld(const T x, const T y) {
    return (x ^ y) >= 0 ? x / y : (x - (y + pow_m1(y >= 0))) / y;
}
template <typename T>
constexpr inline T cld(const T x, const T y) {
    return (x ^ y) <= 0 ? x / y : (x + (y + pow_m1(y >= 0))) / y;
}

template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcountll(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int count_lz(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int count_lz(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int count_tz(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int count_tz(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int floor_log2(const T x) { return suisen::bit_num<T> - 1 - count_lz(x); }
template <typename T>
constexpr inline int ceil_log2(const T x)  { return floor_log2(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int kth_bit(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }

struct all_subset {
    struct all_subset_iter {
        const int s; int t;
        constexpr all_subset_iter(int s) : s(s), t(s + 1) {}
        constexpr auto operator*() const { return t; }
        constexpr auto operator++() {}
        constexpr auto operator!=(std::nullptr_t) { return t ? (--t &= s, true) : false; }
    };
    int s;
    constexpr all_subset(int s) : s(s) {}
    constexpr auto begin() { return all_subset_iter(s); }
    constexpr auto end()   { return nullptr; }
};

// ! container

template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto priqueue_comp(const Comparator comparator) {
    return std::priority_queue<T, std::vector<T>, Comparator>(comparator);
}

template <typename Iterable>
auto isize(const Iterable &iterable) -> decltype(int(iterable.size())) {
    return iterable.size();
}

template <typename T, typename Gen, suisen::constraints_t<suisen::is_same_as_invoke_result<T, Gen, int>> = nullptr>
auto generate_vector(int n, Gen generator) {
    std::vector<T> v(n);
    for (int i = 0; i < n; ++i) v[i] = generator(i);
    return v;
}

template <typename T>
void sort_unique_erase(std::vector<T> &a) {
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}

// ! other utilities

// x <- min(x, y). returns true iff `x` has chenged.
template <typename T>
inline bool chmin(T &x, const T &y) {
    if (y >= x) return false;
    x = y;
    return true;
}
// x <- max(x, y). returns true iff `x` has chenged.
template <typename T>
inline bool chmax(T &x, const T &y) {
    if (y <= x) return false;
    x = y;
    return true;
}

namespace suisen {}
using namespace suisen;
using namespace std;

struct io_setup {
    io_setup(int precision = 20) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(precision);
    }
} io_setup_ {};

// ! code from here

#include <cassert>
#include <tuple>

namespace suisen {

template <typename T, typename UpdateFunc, constraints_t<std::is_invocable<UpdateFunc>> = nullptr>
struct UpdateProxyObject {
    public:
        UpdateProxyObject(T &v, UpdateFunc update) : v(v), update(update) {}
        operator T() const { return v; }
        auto& operator++() && { ++v, update(); return *this; }
        auto& operator--() && { --v, update(); return *this; }
        auto& operator+=(const T &val) && { v += val, update(); return *this; }
        auto& operator-=(const T &val) && { v -= val, update(); return *this; }
        auto& operator*=(const T &val) && { v *= val, update(); return *this; }
        auto& operator/=(const T &val) && { v /= val, update(); return *this; }
        auto& operator%=(const T &val) && { v %= val, update(); return *this; }
        auto& operator =(const T &val) && { v  = val, update(); return *this; }
        auto& operator<<=(const T &val) && { v <<= val, update(); return *this; }
        auto& operator>>=(const T &val) && { v >>= val, update(); return *this; }
        template <typename F, constraints_t<is_uni_op<F, T>> = nullptr>
        auto& apply(F f) && { v = f(v), update(); return *this; }
    private:
        T &v;
        UpdateFunc update;
};

} // namespace suisen

#include <cstddef>
#include <vector>
#include <utility>

namespace suisen {
namespace internal::splay_tree_map {

template <typename Key, typename Val, typename Derived>
struct MapNodeBase {
    using node_ptr_t = Derived *;

    Key key;
    Val val;
    int siz;
    node_ptr_t ch[2] {nullptr, nullptr};

    MapNodeBase() : key(), val(), siz(1) {}
    MapNodeBase(const Key &key, const Val &val) : key(key), val(val), siz(1) {}

    ~MapNodeBase() {
        delete ch[0];
        delete ch[1];
    }

    void update() {
        siz = 1 + size(ch[0]) + size(ch[1]);
    }
    void push() {}

    static int size(node_ptr_t node) {
        return node == nullptr ? 0 : node->siz;
    }

    static node_ptr_t rotate(node_ptr_t node, bool is_right) {
        node_ptr_t root = node->ch[is_right ^ true];
        node->ch[is_right ^ true] = root->ch[is_right];
        root->ch[is_right] = node;
        node->update(), root->update();
        return root;
    }

    static node_ptr_t splay_by_index(node_ptr_t node, int index) {
        std::vector<node_ptr_t> path;
        node_ptr_t work_root = new Derived();
        node_ptr_t work_leaf[2] { work_root, work_root };
        while (true) {
            node->push();
            int size_l = size(node->ch[0]);
            bool is_right = index > size_l;
            node_ptr_t next_node = node->ch[is_right];
            if (index == size_l or next_node == nullptr) { // found the target node
                break;
            }
            if (is_right) {
                index -= size_l + 1;
            }
            int size_l_ch = size(next_node->ch[0]);
            if (index != size_l_ch) {
                bool is_right_ch = index > size_l_ch;
                if (is_right_ch == is_right) { // zig-zig
                    if (is_right_ch) {
                        index -= size_l_ch + 1;
                    }
                    next_node->push();
                    node = rotate(node, is_right ^ true);
                    next_node = node->ch[is_right];
                    if (next_node == nullptr) { // found the target node
                        break;
                    }
                }
            }
            path.push_back(node);
            work_leaf[is_right]->ch[is_right] = node;
            work_leaf[is_right] = node;
            node = next_node;
        }
        work_leaf[0]->ch[0] = node->ch[1];
        work_leaf[1]->ch[1] = node->ch[0];
        node->ch[0] = work_root->ch[1];
        node->ch[1] = work_root->ch[0];
    
        work_root->ch[0] = work_root->ch[1] = nullptr;
        delete work_root;

        while (path.size()) {
            path.back()->update(), path.pop_back();
        }
        node->update();

        return node;
    }

    static node_ptr_t splay_by_key(node_ptr_t node, const Key &x) {
        if (node == nullptr) return node;
        std::vector<node_ptr_t> path;
        node_ptr_t work_root = new Derived();
        node_ptr_t work_leaf[2] { work_root, work_root };
        while (true) {
            node->push();
            if (x == node->key) {
                break;
            }
            bool is_right = x > node->key;
            node_ptr_t next_node = node->ch[is_right];
            if (next_node == nullptr) {
                break;
            }
            if (x != next_node->key) {
                bool is_right_ch = x > next_node->key;
                if (is_right_ch == is_right) { // zig-zig
                    next_node->push();
                    node = rotate(node, is_right ^ true);
                    next_node = node->ch[is_right];
                    if (next_node == nullptr) { // found the target node
                        break;
                    }
                }
            }
            path.push_back(node);
            work_leaf[is_right]->ch[is_right] = node;
            work_leaf[is_right] = node;
            node = next_node;
        }
        work_leaf[0]->ch[0] = node->ch[1];
        work_leaf[1]->ch[1] = node->ch[0];
        node->ch[0] = work_root->ch[1];
        node->ch[1] = work_root->ch[0];

        work_root->ch[0] = work_root->ch[1] = nullptr;
        delete work_root;

        while (path.size()) {
            path.back()->update(), path.pop_back();
        }
        node->update();

        return node;
    }
    static std::pair<node_ptr_t, bool> find_key(node_ptr_t node, const Key &key) {
        if (node == nullptr) return { node, false };
        node = splay_by_key(node, key);
        return { node, node->key == key };
    }
    static std::pair<node_ptr_t, node_ptr_t> split_by_index(node_ptr_t node, int k) {
        if (k == 0) return { nullptr, node };
        if (k == size(node)) return { node, nullptr };
        node_ptr_t r = splay_by_index(node, k);
        node_ptr_t l = r->ch[0];
        r->ch[0] = nullptr;
        r->update();
        return { l, r };
    }
    static std::tuple<node_ptr_t, node_ptr_t, node_ptr_t> split_by_index(node_ptr_t node, int l, int r) {
        auto [tl, tmr] = split_by_index(node, l);
        auto [tm, tr] = split_by_index(tmr, r - l);
        return { tl, tm, tr };
    }
    static std::pair<node_ptr_t, node_ptr_t> split_by_key(node_ptr_t node, const Key &key) {
        if (node == nullptr) return { nullptr, nullptr };
        node_ptr_t r = splay_by_key(node, key);
        if (r->key >= key) {
            node_ptr_t l = r->ch[0];
            r->ch[0] = nullptr;
            r->update();
            return { l, r };
        } else {
            node_ptr_t l = r->ch[1];
            r->ch[1] = nullptr;
            r->update();
            return { r, l };
        }
    }
    static std::tuple<node_ptr_t, node_ptr_t, node_ptr_t> split_by_key(node_ptr_t node, const Key &l, const Key &r) {
        auto [tl, tmr] = split_by_key(node, l);
        auto [tm, tr] = split_by_key(tmr, r);
        return { tl, tm, tr };
    }
    static node_ptr_t merge(node_ptr_t l, node_ptr_t r) {
        if (l == nullptr) return r;
        if (r == nullptr) return l;
        node_ptr_t new_root = splay_by_index(r, 0);
        new_root->ch[0] = l;
        new_root->update();
        return new_root;
    }
    static node_ptr_t merge(node_ptr_t tl, node_ptr_t tm, node_ptr_t tr) {
        return merge(merge(tl, tm), tr);
    }
    static node_ptr_t insert(node_ptr_t node, const Key &key, const Val &val, bool overwrite = true) {
        auto [l, r] = split_by_key(node, key);
        if (r != nullptr and r->key == key) {
            if (overwrite) {
                r->val = val;
                r->update();
            }
            return merge(l, r);
        }
        node_ptr_t new_node = new Derived(key, val);
        new_node->ch[0] = l;
        new_node->ch[1] = r;
        new_node->update();
        return new_node;
    }
    static node_ptr_t erase_index(node_ptr_t node, int index) {
        auto [l, r] = split(index ? node : splay(node, 0), index);
        assert(r->ch[0] == nullptr);
        node_ptr_t res = merge(l, r->ch[1]);
        r->ch[1] = nullptr;
        delete r;
        return res;
    }
    static std::pair<node_ptr_t, bool> erase_key(node_ptr_t node, const Key &key) {
        auto [l, r] = split_by_key(node, key);
        if (r == nullptr or r->key != key) return { merge(l, r), false };
        assert(r->ch[0] == nullptr);
        node_ptr_t res = merge(l, r->ch[1]);
        r->ch[1] = nullptr;
        delete r;
        return { res, true };
    }
    static Val get_or_default(node_ptr_t node, const Key &key, const Val &default_value) {
        auto [new_root, found] = find_key(node, key);
        node = new_root;
        return found ? new_root->val : default_value;
    }
};

template <typename Key, typename Val>
struct SplayTreeMapNode : public MapNodeBase<Key, Val, SplayTreeMapNode<Key, Val>> {
    using Base = MapNodeBase<Key, Val, SplayTreeMapNode<Key, Val>>;
    using Base::MapNodeBase;
    using node_ptr_t = typename Base::node_ptr_t;
};
}

template <typename Key, typename Val>
class SplayTreeMap {
    protected:
        using Node = internal::splay_tree_map::SplayTreeMapNode<Key, Val>;
        using node_ptr_t = typename Node::node_ptr_t;
    public:
        SplayTreeMap() : root(nullptr) {}
        ~SplayTreeMap() {
            delete root;
        }

        SplayTreeMap& operator=(const SplayTreeMap&) = delete;
        SplayTreeMap& operator=(SplayTreeMap&& other) {
            if (other.root == root) return *this;
            delete root;
            root = other.root;
            other.root = nullptr;
            return *this;
        }

        int size() {
            return Node::size(root);
        }
        bool contains(const Key &key) {
            auto [new_root, found] = Node::find_key(root, key);
            root = new_root;
            return found;
        }
        void insert(const Key &key, const Val &val) {
            root = Node::insert(root, key, val, true);
        }
        void insert_if_absent(const Key &key, const Val &val) {
            root = Node::insert(root, key, val, false);
        }
        bool erase_key(const Key &key) {
            auto [new_root, is_erased] = Node::erase_key(root, key);
            root = new_root;
            return is_erased;
        }
        void erase_index(int k) {
            index_bounds_check(k, size() + 1);
            root = Node::erase_index(root, k);
        }
        Val& get_or_create(const Key &key, const Val &val) {
            root = Node::insert(root, key, val, false);
            return root->val;
        }
        Val& operator[](const Key &key) {
            return get_or_create(key, Val{});
        }
        Val get_or_default(const Key &key, const Val &default_value) {
            auto [new_root, res] = Node::get_or_default(root, key, default_value);
            root = new_root;
            return res;
        }
        std::pair<Key, Val> kth_entry(int k) {
            index_bounds_check(k, size());
            root = Node::splay_by_index(root, k);
            return { root->key, root->val };
        }
        SplayTreeMap split_by_index(int k) {
            index_bounds_check(k, size() + 1);
            auto [l, r] = Node::split_by_index(root, k);
            root = l;
            return SplayTreeMap<Key, Val>(r);
        }
        SplayTreeMap split_by_key(const Key &key) {
            auto [l, r] = Node::split_by_key(root, key);
            root = l;
            return SplayTreeMap<Key, Val>(r);
        }
        void merge(SplayTreeMap &&r) {
            assert(root != r.root);
            root = Node::merge(root, r.root);
            r.root = nullptr;
        }
        void swap(SplayTreeMap &r) {
            std::swap(root, r.root);
        }

    protected:
        Node *root;

        SplayTreeMap(node_ptr_t root) : root(root) {}
    
        static void index_bounds_check(unsigned int k, unsigned int n) {
            assert(k < n);
        }
        static void range_bounds_check(unsigned int l, unsigned int r, unsigned int n) {
            assert(l <= r and r <= n);
        }
};

}

namespace suisen {
namespace internal::range_foldable_map {

template <typename Key, typename Val, Val(*op)(Val, Val), Val (*e)(), typename Derived>
struct RangeFoldableMapNodeBase : public internal::splay_tree_map::MapNodeBase<Key, Val, Derived> {
    using Base = internal::splay_tree_map::MapNodeBase<Key, Val, Derived>;
    using node_ptr_t = typename Base::node_ptr_t;
    Val dat;
    RangeFoldableMapNodeBase() : RangeFoldableMapNodeBase(Key{}, e()) {}
    RangeFoldableMapNodeBase(const Key &key, const Val &val) : Base::MapNodeBase(key, val), dat(val) {}
    void update() {
        Base::update();
        dat = op(op(prod_all(this->ch[0]), this->val), prod_all(this->ch[1]));
    }
    static Val prod_all(node_ptr_t node) {
        return node == nullptr ? e() : node->dat;
    }
    static std::pair<node_ptr_t, Val> prod_by_index(node_ptr_t node, int l, int r) {
        auto [tl, tm, tr] = Base::split_by_index(node, l, r);
        Val res = prod_all(tm);
        return { Base::merge(tl, tm, tr), res };
    }
    static std::pair<node_ptr_t, Val> prod_by_key(node_ptr_t node, const Key &l, const Key &r) {
        auto [tl, tm, tr] = Base::split_by_key(node, l, r);
        Val res = prod_all(tm);
        return { Base::merge(tl, tm, tr), res };
    }
};

template <typename Key, typename Val, Val(*op)(Val, Val), Val (*e)()>
struct RangeFoldableMapNode : public RangeFoldableMapNodeBase<Key, Val, op, e, RangeFoldableMapNode<Key, Val, op, e>> {
    using Base = RangeFoldableMapNodeBase<Key, Val, op, e, RangeFoldableMapNode<Key, Val, op, e>>;
    using Base::RangeFoldableMapNodeBase;
    using node_ptr_t = typename Base::node_ptr_t;
};
}

template <typename Key, typename Val, Val(*op)(Val, Val), Val (*e)()>
class RangeFoldableMap {
    using Node = internal::range_foldable_map::RangeFoldableMapNode<Key, Val, op, e>;
    using node_ptr_t = typename Node::node_ptr_t;
    public:
        RangeFoldableMap() : root(nullptr) {}
        ~RangeFoldableMap() {
            delete root;
        }

        RangeFoldableMap& operator=(const RangeFoldableMap&) = delete;
        RangeFoldableMap& operator=(RangeFoldableMap&& other) {
            if (other.root == root) return *this;
            delete root;
            root = other.root;
            other.root = nullptr;
            return *this;
        }

        int size() {
            return Node::size(root);
        }
        bool contains(const Key &key) {
            auto [new_root, found] = Node::find_key(root, key);
            root = new_root;
            return found;
        }
        void insert(const Key &key, const Val &val) {
            root = Node::insert(root, key, val, true);
        }
        void insert_if_absent(const Key &key, const Val &val) {
            root = Node::insert(root, key, val, false);
        }
        bool erase_key(const Key &key) {
            auto [new_root, is_erased] = Node::erase_key(root, key);
            root = new_root;
            return is_erased;
        }
        void erase_index(int k) {
            index_bounds_check(k, size() + 1);
            root = Node::erase_index(root, k);
        }
        Val& get_or_create(const Key &key, const Val &val) {
            root = Node::insert(root, key, val, false);
            return root->val;
        }

        auto operator[](const Key &key) {
            get_or_create(key, e());
            return UpdateProxyObject { root->val, [this]{ root->update(); } };
        }
        Val operator()(const Key &l, const Key &r) {
            return prod(l, r);
        }
        Val prod_by_key(const Key &l, const Key &r) {
            auto [new_root, res] = Node::prod_by_key(root, l, r);
            root = new_root;
            return res;
        }
        Val prod_by_index(int l, int r) {
            auto [new_root, res] = Node::prod_by_index(root, l, r);
            root = new_root;
            return res;
        }
        Val prod_all() {
            return Node::prod_all(root);
        }

        Val get_or_default(const Key &key, const Val &default_value) {
            auto [new_root, res] = Node::get_or_default(root, key, default_value);
            root = new_root;
            return res;
        }
        std::pair<Key, Val> kth_entry(int k) {
            index_bounds_check(k, size());
            root = Node::splay_by_index(root, k);
            return { root->key, root->val };
        }
        RangeFoldableMap split_by_index(int k) {
            index_bounds_check(k, size() + 1);
            auto [l, r] = Node::split_by_index(root, k);
            root = l;
            return RangeFoldableMap(r);
        }
        RangeFoldableMap split_by_key(const Key &key) {
            auto [l, r] = Node::split_by_key(root, key);
            root = l;
            return RangeFoldableMap(r);
        }
        void merge(RangeFoldableMap &&r) {
            assert(root == nullptr or root != r.root);
            root = Node::merge(root, r.root);
            r.root = nullptr;
        }
        void swap(RangeFoldableMap &r) {
            std::swap(root, r.root);
        }

    protected:
        Node *root;

        RangeFoldableMap(node_ptr_t root) : root(root) {}
    
        static void index_bounds_check(unsigned int k, unsigned int n) {
            assert(k < n);
        }
        static void range_bounds_check(unsigned int l, unsigned int r, unsigned int n) {
            assert(l <= r and r <= n);
        }
};

}

namespace suisen {
namespace internal::lazy_eval_map {

template <typename Key, typename Val, Val(*op)(Val, Val), Val (*e)(), typename F, Val(*mapping)(F, Val), F(*composition)(F, F), F(*id)(), typename Derived>
struct LazyEvalMapNodeBase : public internal::range_foldable_map::RangeFoldableMapNodeBase<Key, Val, op, e, Derived> {
    using Base = internal::range_foldable_map::RangeFoldableMapNodeBase<Key, Val, op, e, Derived>;
    using node_ptr_t = typename Base::node_ptr_t;
    F laz;

    LazyEvalMapNodeBase() : LazyEvalMapNodeBase(Key{}, e()) {}
    LazyEvalMapNodeBase(const Key &key, const Val &val) : Base::RangeFoldableMapNodeBase(key, val), laz(id()) {}

    void push() {
        Base::push();
        apply_all(this->ch[0], laz), apply_all(this->ch[1], laz);
        laz = id();
    }
    static void apply_all(node_ptr_t node, const F &f) {
        if (node == nullptr) return;
        node->val = mapping(f, node->val);
        node->dat = mapping(f, node->dat);
        node->laz = composition(f, node->laz);
    }
    static node_ptr_t apply_by_key(node_ptr_t node, const Key &l, const Key &r, const F &f) {
        auto [tl, tm, tr] = Base::split_by_key(node, l, r);
        apply_all(tm, f);
        return Base::merge(tl, tm, tr);
    }
    static node_ptr_t apply_by_index(node_ptr_t node, int l, int r, const F &f) {
        auto [tl, tm, tr] = Base::split_by_index(node, l, r);
        apply_all(tm, f);
        return Base::merge(tl, tm, tr);
    }
};

template <typename Key, typename Val, Val(*op)(Val, Val), Val (*e)(), typename F, Val(*mapping)(F, Val), F(*composition)(F, F), F(*id)()>
struct LazyEvalMapNode : public LazyEvalMapNodeBase<Key, Val, op, e, F, mapping, composition, id, LazyEvalMapNode<Key, Val, op, e, F, mapping, composition, id>> {
    using Base = LazyEvalMapNodeBase<Key, Val, op, e, F, mapping, composition, id, LazyEvalMapNode<Key, Val, op, e, F, mapping, composition, id>>;
    using Base::LazyEvalMapNodeBase;
    using node_ptr_t = typename Base::node_ptr_t;
};
}

template <typename Key, typename Val, Val(*op)(Val, Val), Val (*e)(), typename F, Val(*mapping)(F, Val), F(*composition)(F, F), F(*id)()>
class LazyEvalMap {
    using Node = internal::lazy_eval_map::LazyEvalMapNode<Key, Val, op, e, F, mapping, composition, id>;
    using node_ptr_t = typename Node::node_ptr_t;
    public:
        LazyEvalMap() : root(nullptr) {}
        ~LazyEvalMap() {
            delete root;
        }

        LazyEvalMap& operator=(const LazyEvalMap&) = delete;
        LazyEvalMap& operator=(LazyEvalMap&& other) {
            if (other.root == root) return *this;
            delete root;
            root = other.root;
            other.root = nullptr;
            return *this;
        }

        int size() {
            return Node::size(root);
        }
        bool contains(const Key &key) {
            auto [new_root, found] = Node::find_key(root, key);
            root = new_root;
            return found;
        }
        void insert(const Key &key, const Val &val) {
            root = Node::insert(root, key, val, true);
        }
        void insert_if_absent(const Key &key, const Val &val) {
            root = Node::insert(root, key, val, false);
        }
        bool erase_key(const Key &key) {
            auto [new_root, is_erased] = Node::erase_key(root, key);
            root = new_root;
            return is_erased;
        }
        void erase_index(int k) {
            index_bounds_check(k, size() + 1);
            root = Node::erase_index(root, k);
        }
        Val& get_or_create(const Key &key, const Val &val) {
            root = Node::insert(root, key, val, false);
            return root->val;
        }

        auto operator[](const Key &key) {
            get_or_create(key, e());
            return UpdateProxyObject { root->val, [this]{ root->update(); } };
        }
        Val operator()(const Key &l, const Key &r) {
            return prod(l, r);
        }
        Val prod_by_key(const Key &l, const Key &r) {
            auto [new_root, res] = Node::prod_by_key(root, l, r);
            root = new_root;
            return res;
        }
        Val prod_by_index(int l, int r) {
            auto [new_root, res] = Node::prod_by_index(root, l, r);
            root = new_root;
            return res;
        }
        Val prod_all() {
            return Node::prod_all(root);
        }
        void apply_by_key(const Key &l, const Key &r, const F &f) {
            root = Node::apply_by_key(root, l, r, f);
        }
        void apply_by_index(int l, int r, const F &f) {
            root = Node::apply_by_index(root, l, r, f);
        }
        void apply_all(const F &f) {
            Node::apply_all(root, f);
        }

        Val get_or_default(const Key &key, const Val &default_value) {
            auto [new_root, res] = Node::get_or_default(root, key, default_value);
            root = new_root;
            return res;
        }
        std::pair<Key, Val> kth_entry(int k) {
            index_bounds_check(k, size());
            root = Node::splay_by_index(root, k);
            return { root->key, root->val };
        }
        LazyEvalMap split_by_index(int k) {
            index_bounds_check(k, size() + 1);
            auto [l, r] = Node::split_by_index(root, k);
            root = l;
            return LazyEvalMap(r);
        }
        LazyEvalMap split_by_key(const Key &key) {
            auto [l, r] = Node::split_by_key(root, key);
            root = l;
            return LazyEvalMap(r);
        }
        void merge(LazyEvalMap &&r) {
            assert(root != r.root);
            root = Node::merge(root, r.root);
            r.root = nullptr;
        }
        void swap(LazyEvalMap &r) {
            std::swap(root, r.root);
        }

    protected:
        Node *root;

        LazyEvalMap(node_ptr_t root) : root(root) {}
    
        static void index_bounds_check(unsigned int k, unsigned int n) {
            assert(k < n);
        }
        static void range_bounds_check(unsigned int l, unsigned int r, unsigned int n) {
            assert(l <= r and r <= n);
        }
};

}

namespace suisen {
class HeavyLightDecomposition {
    public:
        template <typename Q>
        using is_point_update_query = std::is_invocable<Q, int>;
        template <typename Q>
        using is_range_update_query = std::is_invocable<Q, int, int>;
        template <typename Q, typename T>
        using is_point_get_query  = std::is_same<std::invoke_result_t<Q, int>, T>;
        template <typename Q, typename T>
        using is_range_fold_query = std::is_same<std::invoke_result_t<Q, int, int>, T>;

        using Graph = std::vector<std::vector<int>>;

        HeavyLightDecomposition(Graph &g, int root = 0) : n(g.size()), root(root), visit(n), leave(n), head(n), ord(n), siz(n), par(n) {
            dfs(g, root, -1);
            int time = 0;
            hld(g, root, -1, time);
        }
        int lca(int u, int v) {
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) return u;
            }
        }
        int la(int u, int k, int default_value = -1) {
            for (int h = head[u]; u >= 0; u = par[h], h = head[u]) {
                if (visit[u] - k >= visit[h]) return ord[visit[u] - k];
                k -= visit[u] - visit[h] + 1;
            }
            return default_value;
        }
        template <typename T, typename Q, typename F, constraints_t<is_range_fold_query<Q, T>, is_bin_op<F, T>> = nullptr>
        T fold_path(int u, int v, T identity, F bin_op, Q fold_query, bool is_edge_query = false) {
            T res = identity;
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) break;
                res = bin_op(fold_query(visit[head[v]], visit[v] + 1), res);
            }
            return bin_op(fold_query(visit[u] + is_edge_query, visit[v] + 1), res);
        }
        template <
            typename T, typename Q1, typename Q2, typename F,
            constraints_t<is_range_fold_query<Q1, T>, is_range_fold_query<Q2, T>, is_bin_op<F, T>> = nullptr
        >
        T fold_path_noncommutative(int u, int v, T identity, F bin_op, Q1 fold_query, Q2 fold_query_rev, bool is_edge_query = false) {
            T res_u = identity, res_v = identity;
            // a := lca(u, v)
            // res = fold(u -> a) + fold(a -> v)
            while (head[u] != head[v]) {
                if (visit[u] < visit[v]) { // a -> v
                    res_v = bin_op(fold_query(visit[head[v]], visit[v] + 1), res_v);
                    v = par[head[v]];
                } else { // u -> a
                    res_u = bin_op(res_u, fold_query_rev(visit[head[u]], visit[u] + 1));
                    u = par[head[u]];
                }
            }
            if (visit[u] < visit[v]) { // a = u
                res_v = bin_op(fold_query(visit[u] + is_edge_query, visit[v] + 1), res_v);
            } else { // a = v
                res_u = bin_op(res_u, fold_query_rev(visit[v] + is_edge_query, visit[u] + 1));
            }
            return bin_op(res_u, res_v);
        }
        template <typename Q, constraints_t<is_range_update_query<Q>> = nullptr>
        void update_path(int u, int v, Q update_query, bool is_edge_query = false) {
            for (;; v = par[head[v]]) {
                if (visit[u] > visit[v]) std::swap(u, v);
                if (head[u] == head[v]) break;
                update_query(visit[head[v]], visit[v] + 1);
            }
            update_query(visit[u] + is_edge_query, visit[v] + 1);
        }
        template <typename T, typename Q, constraints_t<is_range_fold_query<Q, T>> = nullptr>
        T fold_subtree(int u, Q fold_query, bool is_edge_query = false) {
            return fold_query(visit[u] + is_edge_query, leave[u]);
        }
        template <typename Q, constraints_t<is_range_update_query<Q>> = nullptr>
        void update_subtree(int u, Q update_query, bool is_edge_query = false) {
            update_query(visit[u] + is_edge_query, leave[u]);
        }
        template <typename T, typename Q, constraints_t<is_point_get_query<Q, T>> = nullptr>
        T get_point(int u, Q get_query) {
            return get_query(visit[u]);
        }
        template <typename Q, constraints_t<is_point_update_query<Q>> = nullptr>
        void update_point(int u, Q update_query) {
            update_query(visit[u]);
        }
        std::vector<int> inv_ids() const {
            std::vector<int> inv(n);
            for (int i = 0; i < n; ++i) inv[visit[i]] = i;
            return inv;
        }
        int get_head(int u) const {
            return head[u];
        }
    private:
        const int n, root;
        std::vector<int> visit, leave, head, ord, siz, par;
        int dfs(Graph &g, int u, int p) {
            par[u] = p;
            siz[u] = 1;
            int max_size = 0;
            for (int &v : g[u]) {
                if (v == p) continue;
                siz[u] += dfs(g, v, u);
                if (max_size < siz[v]) {
                    max_size = siz[v];
                    std::swap(g[u].front(), v);
                }
            }
            return siz[u];
        }
        void hld(Graph &g, int u, int p, int &time) {
            visit[u] = time, ord[time] = u, ++time;
            head[u] = p >= 0 and g[p].front() == u ? head[p] : u;
            for (int v : g[u]) {
                if (v != p) hld(g, v, u, time);
            }
            leave[u] = time;
        }
};
} // namespace suisen

using S = pair<long long, long long>;
using F = S;

constexpr S op(S, S) { return S{}; }
constexpr S e() { return S{ 0, 0 }; }

constexpr S mapping(F f, S x) { return S { f.first + x.first, f.second + x.second }; }
constexpr F composition(F f, F g) { return F { f.first + g.first, f.second + g.second }; }
constexpr F id() { return F { 0, 0 }; }

constexpr int inf = 1000000;

int main() {
    input(int, n);
    vector<vector<int>> g(n);
    rep(i, n - 1) {
        input(int, x, y);
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    HeavyLightDecomposition hld(g);
    vector<int> head(n);
    rep(i, n) head[i] = hld.get_head(i);

    input(int, q);
    vector<vector<pair<int, int>>> qs(n);
    rep(i, q) {
        input(int, v, k);
        qs[--v].emplace_back(k, i);
    }

    vector<LazyEvalMap<int, S, op, e, F, mapping, composition, id>> fs(n);
    rep(i, n) {
        fs[i].insert(-inf, { 0, 0 });
    }

    auto interpolate = [&](LazyEvalMap<int, S, op, e, F, mapping, composition, id> &f, int x) {
        if (f.contains(x)) return false;
        auto rf = f.split_by_key(x);
        auto g = f.kth_entry(f.size() - 1).second;
        f.insert(x, g);
        f.merge(move(rf));
        return true;
    };

    vector<long long> ans(q);
    auto dfs = [&](auto dfs, int u, int p) -> void {
        auto &f = fs[head[u]];
        for (int v : g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
            if (head[u] == head[v]) continue;
            assert(head[v] == v);
            const int m = fs[v].size();
            rep(i, m) {
                auto [xl, g] = fs[v].kth_entry(i);
                auto xr = i + 1 == m ? inf : fs[v].kth_entry(i + 1).first;
                interpolate(f, xl);
                if (i + 1 != m) interpolate(f, xr);
                f.apply_by_key(xl, xr, g);
            }
        }

        for (const auto &[x, k] : qs[u]) {
            bool b = interpolate(f, x);
            auto [s, t] = S(f[x]);
            ans[k] = s * x + t;
            if (b) f.erase_key(x);
        }

        f.apply_all(F { -1, 0 });
        int m = f.size() - 1;
        while (m >= 0) {
            auto [xl, fl] = f.kth_entry(m);
            auto yl = fl.first * xl + fl.second;
            if (yl < 1) {
                --m;
                continue;
            }
            f.split_by_index(m + 1);
            long long t = fl.first;
            long long xm = xl + cld(1 - yl, t);
            f.insert(xm, { 0, 1 });
            break;
        }
    };
    dfs(dfs, 0, -1);
    print_all(ans, "\n");
    return 0;
}