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


const int N = 1000005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> isP(N, 1);
    isP[0] = isP[1] = 0;
    for (int i = 2; i < N; i++) {
        if (isP[i]) {
            for (int j = i + i; j < N; j += i) {
                isP[j] = 0;
            }
        }
    }

    int tt;
    cin >> tt;

    while (tt--) {
        int n, e;
        cin >> n >> e;
        vector<int> a(n);
        for (int &e : a) cin >> e;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (isP[a[i]]) {
                int cntl = 0;
                for (int j = i - e; j >= 0; j -= e) {
                    if (a[j] == 1) cntl++;
                    else break;
                }
                int cntr = 0;
                for (int j = i + e; j < n; j += e) {
                    if (a[j] == 1) cntr++;
                    else break;
                } 
                // debug(i, cntl, cntr);
                res += 1LL * (cntl + 1) * (cntr + 1) - 1;
            }
        }
        cout << res << "\n";
    }

    return 0;
}