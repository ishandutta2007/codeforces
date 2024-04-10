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

string solve(string a, string b) {
    int n = a.size();
    for (int ch = 0; ch < 2; ch++) {
        int cntA = 0;
        int cntB = 0;
        for (int i = 0; i < n; i++) {
            cntA += a[i] == ('0' + ch);
        }
        for (int i = 0; i < n; i++) {
            cntB += b[i] == ('0' + ch);
        }
        if (cntA >= n / 2 && cntB >= n / 2) {
            int curA = 0;
            int curB = 0;
            string ret;
            for (;curA < n || curB < n;) {
                if (curA == n) {
                    ret += b[curB++];
                    continue;
                }
                if (curB == n) {
                    ret += a[curA++];
                    continue;
                }
                if (a[curA] == b[curB]) {
                    ret += a[curA];
                    curA++;
                    curB++;
                    continue;
                }
                if (a[curA] != ch + '0') {
                    ret += a[curA++];
                    continue;
                }
                ret += b[curB++];
            }
            assert(ret.size() <= (n / 2) * 3);
            return ret;
        }
    }
    return "";
}

int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int T;
    cin >> T;
    for (int tt = 0; tt < T; tt++) {
        int n;
        cin >> n;
        vector<string> s(3);
        for (int i = 0; i < 3; i++) {
            cin >> s[i];
        }
        string ret;
        ret = solve(s[0], s[1]);
        if (ret.empty()) {
            ret = solve(s[0], s[2]);
            if (ret.empty()) {
                ret = solve(s[1], s[2]);
                assert(!ret.empty());
            }
        }
        cout << ret << endl;
    }

    return 0;
}