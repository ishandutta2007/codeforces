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

const int BL = 350;

int small[BL][BL];

void run_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n);
    vector<pair<int, int>> d(m);
    vector<vector<int>> ev(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> d[i].first >> d[i].second;
        d[i].second--;
        ev[d[i].second].push_back(i);
    }
    vector<int> pref(m + 1);
    for (int i = 0; i < n; i++) {
        if (x[i] + y[i] < BL) continue;
        for (int id = 0; id < ev[i].size(); id += 2) {
            int nx = (id + 1 < ev[i].size() ? ev[i][id + 1] : m);
            for (int u = ev[i][id]; u < nx; u += x[i] + y[i]) {
                pref[u]++;
                int r = min(nx, u + x[i]);
                if (r <= m) pref[r]--;
            }
        }
    }

    for (int i = 1; i < m; i++) {
        pref[i] += pref[i - 1];
    }

    vector<int> last(n, -1);

    int cnt = 0;

    for (int i = 0; i < m; i++) {
        int ty = d[i].second;
        int res = pref[i];
        cnt += (d[i].first == 1 ? 1 : -1);
        if (x[ty] + y[ty] < BL) {
            int sum = x[ty] + y[ty];
            if (d[i].first == 1) {
                int it = i % sum;
                for (int j = 0; j < x[ty]; j++) {
                    small[sum][it]++;
                    it += 1;
                    if (it >= sum) it -= sum;
                }
            } else {
                int it = last[ty] % sum;
                for (int j = 0; j < x[ty]; j++) {
                    small[sum][it]--;
                    it += 1;
                    if (it >= sum) it -= sum;
                }
            }
        }
        for (int j = 2; j < BL; j++) {
            res += (small[j][i % j]);
        }
        last[ty] = i;
        cout << cnt - res << '\n';
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    for (int test = 1; test <= tests; test++) run_case(test);
    return 0;
}