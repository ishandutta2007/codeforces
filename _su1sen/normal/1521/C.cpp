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

#ifdef ONLINE_JUDGE
auto query = [](int t, int i, int j, int x) {
    print('?', t, i + 1, j + 1, x);
    cout.flush();
    int response;
    read(response);
    return response;
};
#else
vec<int> test_case {3, 1, 4, 2};
auto query = [](int t, int i, int j, int x) {
    if (t == 1) {
        return max(min(x, test_case[i]), min(x + 1, test_case[j]));
    } else {
        return min(max(x, test_case[i]), max(x + 1, test_case[j]));
    }
};
#endif

// ! code from here

int main() {
    int t;
    read(t);
    while (t --> 0) {
        int n;
        read(n);
        vec<int> ans(n);
        int one = -1;
        reps(i, n, 2) {
            vec<int> idx;
            if (i + 1 < n) idx = {i, i + 1};
            else idx = {n - 2, n - 1};
            int mn = query(2, idx[0], idx[1], 1);
            if (mn == 1) {
                one = idx[0];
            } else if (mn == 2 and query(1, idx[0], idx[1], 1) == 1) {
                one = idx[1];
            }
        }
        rep(i, n) {
            if (i != one) {
                ans[i] = query(1, one, i, n - 1);
            } else {
                ans[i] = 1;
            }
        }
        cout << '!';
        for (int v : ans) cout << ' ' << v;
        cout << '\n';
        cout.flush();
    }
    return 0;
}