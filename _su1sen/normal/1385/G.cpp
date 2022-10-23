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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    read(t);
    while (t --> 0) {
        int n;
        read(n);
        vec<int> a(n), b(n);
        read(a), read(b);
        vec<vec<int>> place(n);
        rep(i, n) {
            place[--a[i]].push_back(i);
            place[--b[i]].push_back(i);
        }
        bool all_twice = true;
        rep(i, n) {
            all_twice &= place[i].size() == 2;
        }
        if (not all_twice) {
            print(-1);
            continue;
        }
        vec<int> flip(n, 0);
        vec<char> vis(n, false);
        rep(i, n) {
            if (vis[i]) continue;
            int cycle_size = 0;
            int flip_cnt = 0;
            int s = a[i], t = b[i];
            int cur_idx = i, cur_val = s;
            vec<int> cycle;
            while (true) {
                cycle.push_back(cur_idx);
                vis[cur_idx] = true;
                ++cycle_size;
                int p = place[cur_val][0], q = place[cur_val][1];
                int nxt_idx = cur_idx ^ p ^ q;
                int nxt_val = cur_val ^ a[nxt_idx] ^ b[nxt_idx];
                if (nxt_idx == i) break;
                if (a[nxt_idx] == cur_val) {
                    ++flip_cnt;
                    flip[nxt_idx] = nxt_idx + 1;
                    swap(a[i], b[i]);
                }
                cur_idx = nxt_idx, cur_val = nxt_val;
            }
            if (cycle_size - flip_cnt < flip_cnt) {
                for (int idx : cycle) {
                    if (flip[idx] > 0) {
                        flip[idx] = 0;
                    } else {
                        flip[idx] = idx + 1;
                    }
                }
            }
        }
        flip.erase(remove_if(all(flip), [](int v){ return v == 0; }), flip.end());
        print(flip.size());
        if (flip.size()) {
            print(flip);
        } else {
            print();
        }
    }
    return 0;
}