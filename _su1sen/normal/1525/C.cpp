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
bool chmin(T &x, T &y) {
    if (y < x) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmin(T &x, T &&y) {
    if (y < x) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmax(T &x, T &y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmax(T &x, T &&y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}

#pragma endregion

// ! code from here

void solve(vec<ll> &x, vec<int> &robot, vec<int> &d, vec<ll> &ans, ll m) {
    auto collide_time = [&](pair<int, int> &p) -> ll {
        auto [i, j] = p;
        if (d[i] > 0) {
            if (d[j] > 0) {
                return (m - x[j]) + (x[j] - x[i]) / 2;
            } else {
                return (x[j] - x[i]) / 2;
            }
        } else {
            if (d[j] > 0) {
                return m + (x[i] - x[j]) / 2;
            } else {
                return x[i] + (x[j] - x[i]) / 2;
            }
        }
    };
    auto cmp = [&](pair<int, int> &p1, pair<int, int> &p2) {
        return collide_time(p2) < collide_time(p1);
    };
    priority_queue<
        pair<int, int>,
        vec<pair<int, int>>,
        decltype(cmp)
    > pq {cmp};
    int sz = robot.size();
    rep(i, sz - 1) {
        pq.emplace(robot[i], robot[i + 1]);
    }
    set<int> survive;
    for (int i : robot) survive.insert(i);
    while (pq.size() > 0) {
        auto p = pq.top();
        pq.pop();
        auto [i, j] = p;
        if (survive.count(i) and survive.count(j)) {
            ll time = collide_time(p);
            ans[i] = ans[j] = time;
            auto it_l = survive.lower_bound(i);
            auto it_r = survive.upper_bound(j);
            if (it_l != survive.begin() and it_r != survive.end()) {
                pq.emplace(*--it_l, *it_r);
            }
            survive.erase(i);
            survive.erase(j);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    read(t);
    while (t --> 0) {
        int n, m;
        read(n, m);
        vec<ll> x(n);
        read(x);
        vec<int> d(n);
        vec<int> odd, evn;
        rep(i, n) {
            string s;
            read(s);
            d[i] = s == "R" ? +1 : -1;
            if (x[i] & 1) {
                odd.push_back(i);
            } else {
                evn.push_back(i);
            }
        }
        vec<int> p(n);
        iota(all(p), 0);
        sort(all(p), [&](int i, int j) { return x[i] < x[j]; });
        vec<int> q(n);
        rep(i, n) {
            q[p[i]] = i;
        }
        sort(all(x));
        for (int &i : odd) i = q[i];
        for (int &i : evn) i = q[i];
        sort(all(odd));
        sort(all(evn));
        vec<int> d2(n);
        rep(i, n) {
            d2[i] = d[p[i]];
        }
        vec<ll> ans(n, -1);
        solve(x, odd, d2, ans, m);
        solve(x, evn, d2, ans, m);
        vec<int> ans2(n);
        rep(i, n) {
            ans2[i] = ans[q[i]];
        }
        print(ans2);
    }
    return 0;
}