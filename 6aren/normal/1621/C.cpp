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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int _ = 0; _ < tt; _++) {
        int n;
        cin >> n;
        vector<int> res(n + 1);
        vector<bool> done(n + 1);
        for (int i = 1; i <= n; i++) {
            if (done[i]) continue;
            vector<int> cyc;
            while (true) {
                int foo;
                cout << "? " << i << endl;
                cin >> foo;
                cyc.push_back(foo);
                if (cyc.size() >= 2 && cyc[0] == cyc.back()) break;
            }
            for (int j = 1; j < cyc.size(); j++) {
                res[cyc[j - 1]] = cyc[j]; 
            }
            for (int e : cyc) done[e] = true;
        }
        cout << "! ";
        for (int i = 1; i <= n; i++) cout << res[i] << ' ';
        cout << endl;
    }
    return 0;
}