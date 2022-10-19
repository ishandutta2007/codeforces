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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    } 

    vector<int> bit(n + 1);

    auto update = [&](int k) {
        for (int i = k; i <= n; i += (i & (-i))) {
            bit[i]++;
        }
    };

    auto get = [&](int k) {
        int res = 0;
        for (int i = k; i > 0; i -= (i & (-i))) {
            res += bit[i];
        }
        return res;
    };

    vector<int> to_check;
    int cur = 0;
    bool found = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (pos[i].size() + 1) / 2; j++) {
            int u = pos[i][j];
            int v = pos[i][pos[i].size() - j - 1];
            int foo1 = get(u);
            int foo2 = cur - get(v);
            if (foo1 != foo2) {
                found = true;
                to_check.push_back(i);
                break;
            }
        }
        if (found) break;
        cur += pos[i].size();
        for (int e : pos[i]) {
            update(e);
        }
    }

    fill(bit.begin(), bit.end(), 0);
    found = false;
    cur = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < (pos[i].size() + 1) / 2; j++) {
            int u = pos[i][j];
            int v = pos[i][pos[i].size() - j - 1];
            int foo1 = get(u);
            int foo2 = cur - get(v);
            if (foo1 != foo2) {
                found = true;
                to_check.push_back(i);
                break;
            }
        }
        if (found) break;
        cur += pos[i].size();
        for (int e : pos[i]) {
            update(e);
        }
    }

    // debug("here");
    // debug(to_check);

    bool ok = (to_check.size() == 0);

    for (int e : to_check) {
        vector<int> b;
        for (int i = 1; i <= n; i++) {
            if (a[i] != e) b.push_back(a[i]);
        }
        bool ok_here = true;
        for (int i = 0; i < b.size(); i++) {
            if (b[i] != b[b.size() - i - 1]) {
                ok_here = false;
            }
        }
        ok |= ok_here;
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}