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

#define int long long

const int INF = 1e9 + 1;

struct SegmentTree {

    vector<int> it;

    SegmentTree(int n) {
        it.resize(4 * n + 4, -INF);
    }

    void update(int k, int l, int r, int id, int val) {
        if (l > id || r < id) return;
        if (l == id && r == id) {
            it[k] = max(it[k], val);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * k, l, mid, id, val);
        update(2 * k + 1, mid + 1, r, id, val);
        it[k] = max(it[2 * k], it[2 * k + 1]);
    }

    int get(int k, int l, int r, int u, int v) {
        if (u > v) return -INF;
        if (l > v || r < u) return -INF;
        if (l >= u && r <= v) return it[k];
        int mid = (l + r) / 2;
        return max(get(2 * k, l, mid, u, v), get(2 * k + 1, mid + 1, r, u, v)); 
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<long long> pref(n + 1);
    vector<long long> to_comp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        to_comp.push_back(pref[i]);
    }
    // debug(a);
    to_comp.push_back(0);
    sort(to_comp.begin(), to_comp.end());
    vector<int> mp(n + 1);
    for (int i = 0; i <= n; i++) {
        mp[i] = lower_bound(to_comp.begin(), to_comp.end(), pref[i]) - to_comp.begin() + 1;
    }

    SegmentTree pos(n + 1), neg(n + 1);
    vector<int> eq(n + 2, -INF);
    pos.update(1, 1, n + 1, mp[0], 0);
    neg.update(1, 1, n + 1, mp[0], 0);
    eq[mp[0]] = 0;

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        // eq
        dp[i] = eq[mp[i]];
        // pos
        dp[i] = max(dp[i], pos.get(1, 1, n + 1, 1, mp[i] - 1) + i);
        // neg
        dp[i] = max(dp[i], neg.get(1, 1, n + 1, mp[i] + 1, n + 1) - i);

        eq[mp[i]] = dp[i];
        pos.update(1, 1, n + 1, mp[i], dp[i] - i);
        neg.update(1, 1, n + 1, mp[i], dp[i] + i);
    }
    // debug(dp);
    cout << dp[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}