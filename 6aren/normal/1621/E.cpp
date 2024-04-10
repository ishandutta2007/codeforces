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

void run_case() {
    int n, m;
    cin >> n >> m;
    vector<int> _teachers(n);
    for (int &e : _teachers) cin >> e;
    sort(_teachers.begin(), _teachers.end());
    vector<int> teachers;
    for (int i = n - m; i < n; i++) teachers.push_back(_teachers[i]);
    vector<vector<int>> students(m);
    vector<long long> sum(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        students[i].resize(k);
        for (int &e : students[i]) cin >> e, sum[i] += e;
    }
    vector<int> gr_ids(m);
    for (int i = 0; i < m; i++) gr_ids[i] = i;
    sort(gr_ids.begin(), gr_ids.end(), [&](int lhs, int rhs) {
        return sum[lhs] * students[rhs].size() < sum[rhs] * students[lhs].size();
    });
    vector<vector<int>> pref(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        if (i > 0 && teachers[i] * students[gr_ids[i - 1]].size() >= sum[gr_ids[i - 1]]) pref[i][0] = 1;
        if (teachers[i] * students[gr_ids[i]].size() >= sum[gr_ids[i]]) pref[i][1] = 1;
        if (i + 1 < m && teachers[i] * students[gr_ids[i + 1]].size() >= sum[gr_ids[i + 1]]) pref[i][2] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            pref[i][j] += pref[i - 1][j];
        }
    }

    auto get = [&](int l, int r, int type) {
        if (r < l) return 0LL;
        return pref[r][type] - (l == 0 ? 0 : pref[l - 1][type]);
    };


    vector<vector<int>> res(m);
    for (int i = 0; i < m; i++) {
        int id = gr_ids[i];
        for (int e : students[id]) {
            int cur_sum = sum[id] - e;
            int cur_length = (int) students[id].size() - 1;
            if (cur_length == 0) {
                res[id].push_back(get(1, i, 0) == i && get(i + 1, m - 1, 1) == m - i - 1);
                continue;
            }
            int found = -1;
            int l = 0, r = m - 1;
            while (r >= l) {
                int mid = (l + r) / 2;
                if (sum[gr_ids[mid]] * cur_length < cur_sum * students[gr_ids[mid]].size()) {
                    found = mid;
                    l = mid + 1;
                } else r = mid - 1;
            }
            bool ok = true;
            if (found < i) {
                ok &= get(0, found, 1) == found + 1;
                ok &= teachers[found + 1] * cur_length >= cur_sum;
                ok &= get(found + 2, i, 0) == (i - found - 1);
                ok &= get(i + 1, m - 1, 1) == (m - i - 1);
            } else {
                ok &= get(0, i - 1, 1) == (i);
                ok &= get(i, found - 1, 2) == (found - i);
                ok &= teachers[found] * cur_length >= cur_sum;
                ok &= get(found + 1, m - 1, 1) == (m - found - 1);
            }
            res[id].push_back(ok);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int e : res[i]) cout << e;
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) run_case();
    return 0;
}