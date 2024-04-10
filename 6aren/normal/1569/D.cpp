#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename A> ostream& operator<<(ostream &os, const vector<A> &vt) {
    os << '[';
    for (size_t i = 0; i + 1 < vt.size(); i++) os << vt[i] << ", ";
    if (!vt.empty()) os << vt.back();
    return os << ']';
}

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef GAREN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void run_case() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(n), y(m);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < m; i++) cin >> y[i];
    vector<map<int, int>> cnt_x(n), cnt_y(m);
    while (k--) {
        int xx, yy;
        cin >> xx >> yy;
        int id_x = lower_bound(x.begin(), x.end(), xx) - x.begin();
        int id_y = lower_bound(y.begin(), y.end(), yy) - y.begin();
        if (x[id_x] == xx && y[id_y] == yy) continue;
        if (x[id_x] == xx) {
            cnt_x[id_x][id_y]++;
        }
        if (y[id_y] == yy) {
            cnt_y[id_y][id_x]++;
        }
    }
    map<int, long long> sum_x, sum_y, sq_x, sq_y;
    for (int i = 0; i < n; i++) {
        for (auto e : cnt_x[i]) {
            sum_x[e.first] += e.second;
            sq_x[e.first] += 1LL * e.second * e.second;
        }
    }
    for (int i = 0; i < m; i++) {
        for (auto e : cnt_y[i]) {
            sum_y[e.first] += e.second;
            sq_y[e.first] += 1LL * e.second * e.second;
        }
    }
    long long res = 0;
    for (auto e : sum_x) {
        long long tmp = e.second * e.second - sq_x[e.first];
        assert(tmp % 2 == 0);
        res += tmp / 2;
    }
    for (auto e : sum_y) {
        long long tmp = e.second * e.second - sq_y[e.first];
        assert(tmp % 2 == 0);
        res += tmp / 2;
    }
    cout << res << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    cin >> tests;
    while (tests--) run_case();
    return 0;
}