#include <bitset>
#include <cstring>
#include <chrono>
#include <random>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <complex>
#include <cmath>
#include <queue>
#include <vector>
#include <fstream>
#include <functional>
#include <memory>

namespace std {
template <typename A, typename B>
inline string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
inline string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
inline string to_string(tuple<A, B, C, D> p);

inline string to_string(const string& s) {
    return '"' + s + '"';
}

inline string to_string(const char* s) {
    return to_string((string) s);
}

inline string to_string(bool b) {
    return (b ? "true" : "false");
}

inline string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
inline string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
inline string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
inline string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
inline string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
inline string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

}
inline void debug_out() { std::cerr << std::endl; }

template <typename Head, typename... Tail>
inline void debug_out(Head H, Tail... T) {
    std::cerr << " " << std::to_string(H);
    debug_out(T...);
}

#define db(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define pw(x) (1LL<<(x))
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef double dbl;
const int N = 2e5;
char s[111];

random_device rd;
mt19937 rnd(rd());

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    vector<bitset<N>> a(m);
    vector<ll> masks(n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; j < m; j++) {
            a[j][i] = s[j] == '1';
            masks[i] |= pw(j) * (s[j] == '1');
        }
    }
    uniform_int_distribution<int> dist(0, n);

    ll best_mask = 0;
    int best_n_bit = 0;
    function<void(ll, ll, int, const bitset<N>&)> rec = [&](ll cur_mask, ll full_mask, int pos, const bitset<N>& state) {
        if (__builtin_popcountll(cur_mask) + __builtin_popcountll(full_mask >> pos) <= best_n_bit) {
            return;
        }
        if (pos == m) {
            int n_bit =  __builtin_popcountll(cur_mask);
            if (best_n_bit < n_bit) {
                best_n_bit = n_bit;
                best_mask = cur_mask;
            }
            return;
        }
        if (full_mask & pw(pos)) {
            auto new_state = state & a[pos];
            ll next_mask = cur_mask | pw(pos);
            if ((int)new_state.count() * 2 >= n) {
                rec(next_mask, full_mask, pos + 1, new_state);
            }
        }
        rec(cur_mask, full_mask, pos + 1, state);

    };

    set<ll> q;
    for (int kk = 0; kk < 20 && clock() * 1.0 / CLOCKS_PER_SEC < 2; kk++) {
        int pos = dist(rnd);
        ll full_mask = masks[pos];
        if (q.count(full_mask) == 0) {
            bitset<N> state;
            state.flip();
            rec(0, full_mask, 0, state);
            q.insert(full_mask);
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%lld", (best_mask >> i) & 1);
    }
    puts("");


    return 0;
}