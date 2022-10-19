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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> w(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> w[i][j];
    vector<vector<int>> cost(n, vector<int>(n));
    for (int r = 0; r < n; r++) {
        int cur = 0;
        for (int l = r; l >= 0; l--) {
            cur += w[r][l];
            cost[l][r] = (r > 0 ? cost[l][r - 1] : 0) + cur;
        }
    }
    vector<vector<int>> dp(k + 1, vector<int>(n));
    for (int i = 0; i < n; i++) {
        dp[1][i] = cost[0][i];
    }

    function<void(int, int, int, int, int)> solve = [&](int id, int l, int r, int u, int v) {
        if (l > r) return;
        int mid = (l + r) / 2;
        int best = 1e9;
        int opt = -1;
        for (int i = u; i <= min(mid, v); i++) {
            int val = (i > 0 ? dp[id - 1][i - 1] : 0) + cost[i][mid];
            if (val <= best) {
                best = val;
                opt = i;
            } 
        }
        dp[id][mid] = best;
        solve(id, l, mid - 1, u, opt);
        solve(id, mid + 1, r, opt, v);
    };
    // dbg(dp[2]);
    for (int i = 2; i <= k; i++) {
        solve(i, 0, n - 1, 0, n - 1);
    }
    
    cout << dp[k][n - 1] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    while (tests--) run_case();
    return 0;
}