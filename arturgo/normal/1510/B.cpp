#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

pair<int, vector<int>> hungarian(const vector<vector<int>> &a) {
    if (a.empty())
        return {0, {}};
    int n = a.size() + 1, m = a[0].size() + 1;
    vector<int> u(n), v(m), p(m), ans(n-1);

    for (int i = 1; i < n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> dist(m, INT_MAX), pre(m, -1);
        vector<bool> done(m+1);
        do {
            done[j0] = true;
            int i0 = p[j0], j1, delta = INT_MAX;
            for (int j = 1; j < m; ++j)
                if (!done[j]) {
                    auto cur = a[i0-1][j-1] - u[i0] - v[j];
                    if (cur < dist[j])
                        dist[j] = cur, pre[j] = j0;
                    if (dist[j] < delta) delta = dist[j], j1 = j;
                }
            for (int j = 0; j < m; ++j) {
                if (done[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    dist[j] -= delta;
            }
            j0 = j1;
        } while(p[j0]);
        while (j0) {
            int j1 = pre[j0];
            p[j0] = p[j1], j0 = j1;
        }
    }
    for (int j = 1; j < m; ++j)
        if (p[j])
            ans[p[j] - 1] = j-1;
    return {-v[0], ans};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int d, n;
    cin >> d >> n;
    vector<int> codes(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        for (int j = 0; j< d; ++j)
            codes[i] = 2 * codes[i] + s[j] - '0';
    }

    vector<vector<int>> cost(n, vector<int>(2*n, INF));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if ((codes[i] & codes[j]) == codes[j] and i != j)
                cost[i][j] = __builtin_popcount(codes[i] - codes[j]);
    for (int i = 0; i < n; ++i)
        for (int j = n; j < 2 * n; ++j)
            cost[i][j] = 1 + __builtin_popcount(codes[i]);
    auto [c, couplage] = hungarian(cost);
    vector<int> nxt(2*n, -1);
    for (int i = 0; i < n; ++i)
        nxt[couplage[i]] = i;
    vector<int> sol;
    for (int i = n; i < 2 * n; ++i)
        if (nxt[i] != -1) {
            int cur = 0;
            int j = i;
            vector<int> path;
            if (!sol.empty())
                sol.push_back(-1);
            while(nxt[j] != -1) {
                j = nxt[j];
                for (int p = 0; p < d; ++p)
                    if ((1 << p) & (codes[j] - cur)) {
                        cur |= 1 << p;
                        sol.push_back(p);
                    }
            }
        }
    cout << sol.size() << '\n';
    for (int x : sol)
        cout << (x==-1?'R':(char)('0' + x)) << ' ';
    cout << endl;
}