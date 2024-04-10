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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> res;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] ^ a[i];
    
    auto do_op = [&](int id) {
        if (id > n - 2) return;
        res.push_back(id);
        int sum_xor = a[id] ^ a[id + 1] ^ a[id + 2];
        a[id] = a[id + 1] = a[id + 2] = sum_xor;
    };

    auto assign = [&](int x, int y) {
        if (x > y) do_op(y + 1);
        else do_op(x);
    };

    for (int i = 1; i >= 0; i--) {
        int id = -1;
        for (int j = i; j <= n; j += 2) {
            if (pref[j] == 0) {
                id = j;
                break;
            }
        }
        if (id != -1) {
            for (int j = id + 2; j <= n; j += 2) assign(j, j - 2);
            for (int j = id - 2; j >= 1; j -= 2) assign(j, j + 2);
        }
    }
    for (int i = 0; i <= n; i++) if (a[i] == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << res.size() << '\n';
    for (int e : res) cout << e << ' ';
    cout << '\n';
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