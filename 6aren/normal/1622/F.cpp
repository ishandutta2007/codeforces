#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    vector<int> minP(n + 1);
    for (int i = 2; i <= n; i++) {
        if (minP[i] == 0) {
            minP[i] = i;
            for (int j = i + i; j <= n; j += i) {
                if (minP[j] == 0) minP[j] = i;
            }
        }
    }

    vector<int64_t> H(n + 1), H_fac(n + 1);
    unordered_map<int64_t, int, custom_hash> mp;
    for (int i = 2; i <= n; i++) {
        if (minP[i] == i) H[i] = rng();
        else {
            int cur = i;
            while (minP[cur] != 0) {
                H[i] ^= H[minP[cur]];
                cur /= minP[cur];
            }
        }
        H_fac[i] = H_fac[i - 1] ^ H[i];
        mp[H_fac[i]] = i;
    }

    int64_t sum = 0;
    for (int i = 1; i <= n; i++) sum ^= H_fac[i];
    set<int> res;
    for (int i = 1; i <= n; i++) res.insert(i);
    auto printRes = [&]() -> void {
        cout << res.size() << '\n';
        for (int e : res) cout << e << ' ';
        cout << '\n';
        exit(0);
    };

    if (sum == 0) printRes();
    else if (mp[sum] != 0) {
        res.erase(mp[sum]);
        printRes();
    } else {
        for (int i = 2; i <= n; i++) {
            if (mp[sum ^ H_fac[i]] != 0) {
                res.erase(i);
                res.erase(mp[sum ^ H_fac[i]]);
                printRes();
            }
        }
    }
    res.erase(2);
    res.erase(n / 2);
    res.erase(n);
    printRes();

    return 0;
}