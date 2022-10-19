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
    
    vector<int> perm = {0, 1, 2};
    vector<vector<int>> cases;
    do {
        cases.push_back(perm);
    } while (next_permutation(perm.begin(), perm.end()));

    int n;
    cin >> n;
    vector<pair<int, int>> p[3];
    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        p[c - 1].emplace_back(x, y);
    }

    vector<pair<int, int>> pp[3];
    pp[0] = p[0], pp[1] = p[1], pp[2] = p[2];

    // debug(pp[0], pp[1], pp[2]);

    auto _check = [&](int x, int y, int z, int mid) {
        vector<int> a; a.reserve(n / 3);
        for (auto &e : p[x]) a.push_back(e.first);
        sort(a.begin(), a.end());
        int foo = a[mid - 1];
        vector<int> b, c;
        b.reserve(n / 3), c.reserve(n / 3);
        for (auto &e : p[y]) if (e.first > foo) b.push_back(e.second);
        for (auto &e : p[z]) if (e.first > foo) c.push_back(e.second);
        if (b.size() < mid || c.size() < mid) return false;
        sort(b.rbegin(), b.rend());
        sort(c.begin(), c.end());
        
        return b[mid - 1] > c[mid - 1];
    };

    auto _check_order = [&](int x, int y, int z, int mid) {
        // order
        vector<int> a;
        for (auto e : p[x]) a.push_back(e.first);
        sort(a.begin(), a.end());
        int foo = a[mid - 1];
        vector<int> b;
        for (auto &e : p[y]) {
            if (e.first > foo) b.push_back(e.first); 
        }
        if (b.size() < mid) return false;
        sort(b.begin(), b.end());
        foo = b[mid - 1];
        vector<int> c;
        for (auto &e : p[z]) {
            if (e.first > foo) c.push_back(e.first); 
        }
        return c.size() >= mid;
    };

    auto check = [&](int mid, const vector<int> &_case) {
        // debug(mid, _case);
        int x = _case[0], y = _case[1], z = _case[2];

        if (_check_order(x, y, z, mid)) return true;

        // normal
        if (_check(x, y, z, mid)) return true;

        // swap x
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n / 3; j++) p[i][j].first = -p[i][j].first;
        }
        if (_check(x, y, z, mid)) return true;

        // swap first, second
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n / 3; j++) swap(p[i][j].first, p[i][j].second);
        }

        if (_check_order(x, y, z, mid)) return true;
        if (_check(x, y, z, mid)) return true;

        // swap x
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n / 3; j++) p[i][j].first = -p[i][j].first;
        }
        if (_check(x, y, z, mid)) return true;

        return false;
    };

    int res = 1;
    int l = 2, r = n / 3;
    while (r >= l) {
        int mid = (l + r) / 2;
        bool ok = false;
        for (auto _case : cases) {
            p[0] = pp[0], p[1] = pp[1], p[2] = pp[2];
            if (check(mid, _case)) {
                ok = true;
                break;
            }
        }
        if (ok) {
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    cout << res * 3 << '\n';

    return 0;
}