#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

struct Query {
    int l, r, s, t, pos;
    bool operator<(const Query& other) const {
        return l > other.l;
    }
};

int dp[1005][1005];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        Query& p = queries[i];
        cin >> p.l >> p.r >> p.s >> p.t;
        p.s--;
        p.t--;
        p.l--;
        p.r--;
        p.pos = i;
    }
    memset(dp, 0x3f, sizeof dp);

    sort(queries.begin(), queries.end());
    vector<bool> answers(q);
    int pos = m - 1;
    for (const Query& curr: queries) {
        while (pos >= curr.l) {
            int x = edges[pos].first, y = edges[pos].second;
            dp[x][y] = dp[y][x] = pos;
            for (int i = 0; i < n; ++i) {
                if (dp[y][i] > dp[x][i]) {
                    dp[y][i] = dp[x][i];
                } else {
                    dp[x][i] = dp[y][i];
                }
            }
            pos--;
        }
        answers[curr.pos] = curr.r >= dp[curr.s][curr.t];
    }
    for (bool ans: answers) {
        cout << (ans ? "Yes\n": "No\n");
    }
}