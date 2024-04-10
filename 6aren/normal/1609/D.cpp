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

    int n, d;
    cin >> n >> d;
    
    vector<int> x(d), y(d);
    for (int i = 0; i < d; i++) {
        cin >> x[i] >> y[i];
    }

    vector<int> par(n + 1, -1), sz(n + 1, 1);

    auto find = [&](int x) {
        if (par[x] == -1) par[x] = x;
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    };

    auto merge = [&](int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            par[y] = x;
            sz[x] += sz[y];
            return true;
        }
        return false;
    };
    
    int count_dup = 0;
    for (int i = 0; i < d; i++) {
        if (!merge(x[i], y[i])) count_dup++;
        vector<int> foo;
        for (int j = 1; j <= n; j++) {
            if (par[j] == j || par[j] == -1) foo.push_back(sz[j]);
        } 
        sort(foo.rbegin(), foo.rend());
        int res = 0;
        for (int j = 0; j < min(count_dup + 1, (int) foo.size()); j++) {
            res += foo[j];
        }
        cout << res - 1 << '\n';
    }  
    
    return 0;
}