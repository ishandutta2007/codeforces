#include <bits/stdc++.h>

#pragma region

using namespace std;

// ! type aliases
using int128 = __int128_t;
using ll = long long;
using uint = unsigned int;
using ull  = unsigned long long;

template <typename T> using vec  = std::vector<T>;
template <typename T> using vec2 = vec<vec<T>>;
template <typename T> using vec3 = vec<vec2<T>>;
template <typename T> using vec4 = vec<vec3<T>>;

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
bool chmin(T &x, const T &y) {
    if (y < x) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmin(T &x, const T &&y) {
    if (y < x) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}
template <typename T>
bool chmax(T &x, const T &&y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}

// ! operator overload (pair)
template <typename T, typename U>
std::pair<T, U>& operator+=(std::pair<T, U> &p1, const std::pair<T, U> &p2) {
    p1.first += p2.first, p1.second += p2.second;
    return p1;
}
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U> &p1, const std::pair<T, U> &p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}
template <typename T, typename U>
std::pair<T, U>& operator-=(std::pair<T, U> &p1, const std::pair<T, U> &p2) {
    p1.first -= p2.first, p1.second -= p2.second;
    return p1;
}
template <typename T, typename U>
std::pair<T, U> operator-(const std::pair<T, U> &p1, const std::pair<T, U> &p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}
template <typename T, typename U, typename V>
std::pair<T, U>& operator*=(std::pair<T, U> &p, const V m) {
    p.first *= m, p.second *= m;
    return p;
}
template <typename T, typename U, typename V>
std::pair<T, U> operator*(std::pair<T, U> &p, const V m) {
    return {p.first * m, p.second * m};
}
// ! operator overload (vector)
template <typename T>
std::vector<T>& operator+=(std::vector<T> &a, const std::vector<T> &b) {
    int n = a.size();
    a.resize(n + b.size());
    std::copy(b.begin(), b.end(), a.begin() + n);
    return a;
}
template <typename T>
std::vector<T> operator+(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<T> c = a; return c += b;
}
template <typename T>
std::vector<T>& operator+=(std::vector<T> &a, const T &b) {
    a.push_back(b); return a;
}
template <typename T>
std::vector<T> operator+(const std::vector<T> &a, const T &b) {
    std::vector<T> c = a; return c += b;
}
template <typename T>
std::vector<T>& operator*=(std::vector<T> &a, const int repeat) {
    int n = a.size();
    a.resize(n * repeat);
    for (int i = 1; i < repeat; ++i) std::copy(a.begin(), a.end(), a.begin() + i * n);
    return a;
}
template <typename T>
std::vector<T> operator*(std::vector<T> &a, const int repeat) {
    std::vector<T> c = a; return c *= repeat;
}

#pragma endregion

// ! code from here

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l;
    read(n, m, l);
    vec<pair<ll, int>> idx_a, idx_b, idx_c, idx_d;
    vec<ll> a {0}, b {0}, c {0}, d {0};
    rep(i, n) {
        int t, pa, pb;
        read(t, pa, pb);
        if (pa == 1 and pb == 1) {
            idx_c.emplace_back(t, i + 1);
            c.push_back(t);
        } else if (pa == 1) {
            idx_a.emplace_back(t, i + 1);
            a.push_back(t);
        } else if (pb == 1) {
            idx_b.emplace_back(t, i + 1);
            b.push_back(t);
        } else {
            idx_d.emplace_back(t, i + 1);
            d.push_back(t);
        }
    }
    auto f = [n](vec<ll> &a) -> void {
        sort(all(a));
        int x = a.size();
        rep(i, x - 1) a[i + 1] += a[i];
    };
    f(a), f(b), f(c), f(d);
    vec<ll> conv(m + 1, LINF);
    vec<tuple<int, int, int>> sel(m + 1);
    int sl = m;
    int i = 0, j = 0, k = 0;
    replr(s, l, m + 1) {
        int imax = min(int(a.size()) - 1, s - l), jmax = min(int(b.size()) - 1, s - l), kmax = int(c.size()) - 1;
        if (imax + jmax + kmax >= s) {
            int ci = 0, cj = 0, ck = s;
            if (ck <= kmax and chmin(conv[s], a[ci] + b[cj] + c[ck])) {
                conv[s] = a[ci] + b[cj] + c[ck];
                i = ci, j = cj, k = ck;
            }
            replr(t, 1, s + 1) {
                ll vi = ci < imax ? a[ci + 1] + b[cj] : LINF;
                ll vj = cj < jmax ? a[ci] + b[cj + 1] : LINF;
                if (vi < vj) {
                    ++ci;
                } else if (cj < jmax) {
                    ++cj;
                } else {
                    break;
                }
                --ck;
                if (ck <= kmax and chmin(conv[s], a[ci] + b[cj] + c[ck])) {
                    i = ci, j = cj, k = ck;
                }
            }
            sl = s;
            sel[s] = {i, j, k};
            break;
        }
    }
    replr(s, sl + 1, m + 1) {
        int ai = -10, aj = -10, ak = -10;
        for (int di : {-1, 0, 1}) for (int dj : {-1, 0, 1}) for (int dk : {-1, 0, 1}) {
            int ni = i + di, nj = j + dj, nk = k + dk;
            if (ni + nj + nk != s) continue;
            if (ni < 0 or ni > s - l or ni >= a.size()) continue;
            if (nj < 0 or nj > s - l or nj >= b.size()) continue;
            if (nk < 0               or nk >= c.size()) continue;
            if (chmin(conv[s], a[ni] + b[nj] + c[nk])) {
                ai = ni, aj = nj, ak = nk;
            }
        }
        i = ai, j = aj, k = ak;
        sel[s] = {i, j, k};
    }
    int ai, aj, ak, al;
    ll ans = LINF;
    replr(s, l, m + 1) {
        if (m - s >= d.size()) continue;
        if (chmin(ans, conv[s] + d[m - s])) {
            ai = get<0>(sel[s]), aj = get<1>(sel[s]), ak = get<2>(sel[s]);
            al = m - (ai + aj + ak);
        }
    }
    if (ans == LINF) {
        print(-1);
    } else {
        sort(all(idx_a)), sort(all(idx_b)), sort(all(idx_c)), sort(all(idx_d));
        vec<int> restore;
        rep(i, ai) restore.push_back(idx_a[i].second);
        rep(i, aj) restore.push_back(idx_b[i].second);
        rep(i, ak) restore.push_back(idx_c[i].second);
        rep(i, al) restore.push_back(idx_d[i].second);
        print(ans);
        print(restore);
    }
    return 0;
}