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
    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i + 3 <= s.size(); i++) {
        if (s.substr(i, 3) == "abc") res++;
    }

    while (q--) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        for (int i = max(pos - 2, 0); i <= min(pos, (int) s.size() - 3); i++) {
            if (s.substr(i, 3) == "abc") res--;
        }
        s[pos] = c;
        for (int i = max(pos - 2, 0); i <= min(pos, (int) s.size() - 3); i++) {
            if (s.substr(i, 3) == "abc") res++;
        }
        cout << res << '\n';
    }

    return 0;
}