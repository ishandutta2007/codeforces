#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(char c) { return string(1, c); }
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
#ifdef GAREN
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void run_case(int test) {
    string s;
    cin >> s;
    int cur = 0;
    int cnt = 0;
    for (char ch : s) {
        if (ch == '0') cur++;
        else {
            if (cur) cnt++;
            cur = 0;
        }
    }
    if (cur) cnt++;
    cout << min(cnt, 2) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    cin >> tests;
    for (int test = 1; test <= tests; test++) run_case(test);
    return 0;
}