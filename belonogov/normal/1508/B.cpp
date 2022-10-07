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
const ll INF = 1.01e18;

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int T;
    scanf("%d", &T);
    for (int tt = 0; tt < T; tt++) {
        int n;
        ll k;
        scanf("%d%lld", &n, &k);
        k--;
        vector<ll> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(INF, dp[i - 1] * 2);
        }
        if (k >= dp[n]) {
            puts("-1");
            continue;
        }
        vector<int> answer;
        for (int i = 0; i < n;) {
            int cnt = 0;
            for (; dp[n - i - 1 - cnt] <= k; cnt++) {
                k -= dp[n - i - 1 - cnt];
            }
            for (int j = 0; j <= cnt; j++) {
                answer.pb(i + cnt - j);
            }
            i += cnt + 1;
        }
        for (auto x: answer) {
            cout << x + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}