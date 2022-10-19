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
    while (tt--) {
        []() {
            int n;
            cin >> n;
            vector<int> a(n);
            for (int i = 0; i < n; i++) {
                cin >> a[i];
            }
            if (*max_element(a.begin(), a.end()) == *min_element(a.begin(), a.end()) && a[0] == 0) {
                cout << "Yes\n";
                return;
            }
            long long sum = 0;
            vector<pair<int, int>> pos, neg;
            for (int i = 0; i < n; i++) {
                sum += a[i];
                if (a[i] > 0) pos.emplace_back(a[i], i);
                if (a[i] < 0) neg.emplace_back(-a[i], i);
            }
            if (sum != 0) {
                cout << "No\n";
                return;
            }
            if (a[0] == 0) {
                cout << "No\n";
                return;
            }
            reverse(pos.begin(), pos.end());
            reverse(neg.begin(), neg.end());
            int cur = 1e9 + 1;
            while (true) {
                auto u = pos.back();
                pos.pop_back();
                auto v = neg.back();
                neg.pop_back();
                // debug(u, v);
                if (cur < u.second) {
                    cout << "No\n";
                    return;
                }
                if (u.second > v.second) {
                    cout << "No\n";
                    return;
                }
                int foo = min(u.first, v.first);
                u.first -= foo;
                v.first -= foo;
                if (u.first) pos.push_back(u);
                if (v.first) neg.push_back(v);
                cur = v.second;
                if (pos.size() == 0) break;
            }
            cout << "Yes\n";
        }();
    }
    return 0;
}