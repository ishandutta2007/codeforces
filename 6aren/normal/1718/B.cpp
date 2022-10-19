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
    vector<long long> f(60), prefF(60);
    f[0] = 1, f[1] = 1;
    for (int i = 2; i < 60; i++) {
        f[i] = f[i - 1] + f[i - 2];
    } 
    prefF = f;
    for (int i = 1; i < 60; i++) {
        prefF[i] += prefF[i - 1];
    }
    // debug(f, prefF);
    int tt;
    cin >> tt;
    while (tt--) {
        int k;
        cin >> k;
        vector<int> c(k);
        for (int &e : c) {
            cin >> e;
        }
        if (k == 1) {
            cout << (c[0] == 1 ? "YES\n" : "NO\n");
            continue;
        }
        sort(c.begin(), c.end());
        long long sum = 0;
        for (int &e : c) sum += e;
        int n = lower_bound(prefF.begin(), prefF.end(), sum) - prefF.begin();
        if (prefF[n] != sum) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;

        priority_queue<pair<int, int>> s;
        for (int i = 0; i < k; i++) {
            s.push({c[i], i});
        }
        int last = -1;
        vector<vector<int>> res(k);
        for (int i = n; i >= 0; i--) {
            pair<int, int> first = s.top();
            s.pop();
            pair<int, int> second = s.top();
            s.pop();
            if (first.second == last) {
                if (second.first < f[i]) {
                    ok = false;
                    break;
                }
                second.first -= f[i];
                last = second.second;
                res[last].push_back(i);
            } else {
                if (first.first < f[i]) {
                    ok = false;
                    break;
                }
                first.first -= f[i];
                last = first.second;
                res[last].push_back(i);
            }
            s.push(first);
            s.push(second);
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j + 1 < res[i].size(); j++) {
                if (res[i][j] - 1 == res[i][j + 1]) {
                    ok = false;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}