#include <bits/stdc++.h>

#pragma region

using namespace std;

// ! type aliases
using int128 = __int128_t;
using ll = long long;
using uint = unsigned int;
using ull = unsigned long long;

template <typename T>
using vec = std::vector<T>;
template <typename T>
using vec2 = vec<vec<T>>;
template <typename T>
using vec3 = vec<vec2<T>>;

template <typename T>
using pq_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T, typename U>
using umap = unordered_map<T, U>;

// ! macros
#define rep(i, n)           for (int i = 0; i < n; ++i)
#define reps(i, n, s)       for (int i = 0; i < n; i += s)
#define replr(i, l, r)      for (int i = l; i < r; ++i)
#define replrs(i, l, r, s)  for (int i = l; i < r; i += s)
#define rrep(i, n)          for (int i = (n) - 1; i >= 0; --i)
#define rreps(i, n, s)      for (int i = (n) - 1; i >= 0; i -= s)
#define rreplr(i, l, r)     for (int i = (r) - 1; i >= l; --i)
#define rreplrs(i, l, r, s) for (int i = (r) - 1; i >= l; i -= s)

#define all(iterable) (iterable).begin(), (iterable).end()

// ! constants
constexpr int dx4[4] = {1, 0, -1, 0};
constexpr int dy4[4] = {0, 1, 0, -1};

constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

constexpr int IINF = (1 << 30) - 1;
constexpr ll LINF = (1LL << 62) - 1; 

// ! I/O utilities
inline void print() { cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head& head, const Tail&... tails) {
    cout << head;
    if (sizeof...(tails)) cout << ' ';
    print(tails...);
}
template <typename T>
void print(const vec<T>& v, const string sep = " ", const string end = "\n") {
    int n = v.size();
    rep(i, n) cout << v[i] << (i < n - 1 ? sep : end);
}
template <typename T>
void print(const vec<T>& v, const size_t begin_index, const size_t length, const string sep = " ", const string end = "\n") {
    int n = begin_index + length;
    replr(i, begin_index, n) cout << v[i] << (i < n - 1 ? sep : end);
}
constexpr void read() {}
template <typename Head, typename... Tail>
inline void read(Head& head, Tail& ...tails) {
    cin >> head;
    read(tails...);
}
template <typename T>
void read(vec<T>& a, size_t begin_index, size_t length) {
    a.resize(begin_index + length);
    while (length --> 0) cin >> a[begin_index++];
}
template <typename T>
void read(vec<T>& a) {
    read(a, 0, a.size());
}

// ! utility functions
template <typename T>
void chmin(T &x, T &y) { if (y < x) x = y; }
template <typename T>
void chmax(T &x, T &y) { if (y > x) x = y; }

#pragma endregion


namespace prioritizing_mode {
    template <typename T>
    using left_most_min = std::greater<T>;
    template <typename T>
    using right_most_min = std::greater_equal<T>;
    template <typename T>
    using left_most_max = std::less<T>;
    template <typename T>
    using right_most_max = std::less_equal<T>;
}

template <typename T, typename _Comparator = prioritizing_mode::left_most_min<T>>
class sliding_window_minimum {
    public:
        sliding_window_minimum(size_t n, std::function<T(int)> gen) : _n(n) {
            _a.resize(_n);
            for (int i = 0; i < _n; ++i) _a[i] = gen(i);
        }
        void proc_right() {
            assert(_r < _n);
            T v = _a[_r];
            while (not _dq.empty() and _cmp(_a[_dq.back()], v)) _dq.pop_back();
            _dq.push_back(_r++);
        }
        void proc_right(size_t to_index) { while (_r < to_index) proc_right(); }
        void proc_left() {
            assert(_l < _r);
            if (_dq.front() == _l) _dq.pop_front();
            ++_l;
        }
        void proc_left(size_t to_index) { while (_l < to_index) proc_left(); }
        void proc(size_t new_l, size_t new_r) { proc_right(new_r); proc_left(new_l); }
        size_t argmin() const {
            assert(_l < _r);
            return _dq.front();
        }
        T min() const { return _a[argmin()]; }

        size_t get_left()  const { return _l; }
        size_t get_right() const { return _r; }
        size_t get_window_size() const { return _r - _l; }

    private:
        const size_t _n;
        size_t _l = 0, _r = 0;
        std::vector<T> _a;
        std::deque<size_t> _dq;
        _Comparator _cmp;
};

// ! code from here

int main() {
    int n, k, x;
    read(n, k, x);
    vec<ll> a(n);
    read(a);
    vec<ll> dp(n, -LINF);
    rep(i, k) {
        dp[i] = a[i];
    }
    rep(i, x - 1) {
        sliding_window_minimum<ll, prioritizing_mode::left_most_max<ll>> swm(
            n, [&dp](int p) { return dp[p]; }
        );
        rep(j, n) {
            if (swm.get_window_size()) {
                dp[j] = swm.min() + a[j];
            } else {
                dp[j] = -LINF;
            }
            swm.proc_right();
            if (swm.get_left() == j - k) {
                swm.proc_left();
            }
        }
    }
    ll ans = 0;
    replr(i, n - k, n) {
        ans = max(ans, dp[i]);
    }
    if (ans == 0) {
        print(-1);
    } else {
        print(ans);
    }
    return 0;
}