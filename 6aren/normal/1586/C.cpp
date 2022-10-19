#include <bits/stdc++.h>

using namespace std;

#ifdef GAREN
#include <cp-template/debugger.hpp>
#else
#define debug(...) 42
#endif

const int INF = 1e9;

void run_case(int test) {
    int n, m;
    cin >> n >> m;
    vector<string> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    vector<string> s(m);
    for (int i = 0; i < m; i++) {
        string foo;
        for (int j = 0; j < n; j++) foo.push_back(t[j][i]);
        s[i] = foo;
    }
    swap(n, m);
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                if (s[i][j] == 'X') dp[i][j] = i;
                else dp[i][j] = -INF;
            } else {
                if (s[i][j] == 'X') dp[i][j] = i;
                else if (j == 0) dp[i][j] = -INF;
                else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector<pair<int, int>> banned;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int foo = min({dp[i - 1][j], dp[i][j - 1], dp[i][j]});
            banned.push_back(make_pair(foo, i));
        }
    }
    vector<tuple<int, int, int>> queries;
    int q;
    cin >> q;
    vector<int> res(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back(make_tuple(l - 1, r - 1, i));
    }
    sort(queries.begin(), queries.end(), [](tuple<int, int, int> lhs, tuple<int, int, int> rhs) {
        return get<0>(lhs) > get<0>(rhs);
    });
    sort(banned.rbegin(), banned.rend());
    // debug(banned);
    set<int> rights;
    int id = 0;
    for (auto que : queries) {
        int l = get<0>(que);
        int r = get<1>(que);
        int q_id = get<2>(que);
        while (id < banned.size() && banned[id].first >= l) {
            rights.insert(banned[id].second);
            id++;
        } 
        if (rights.empty() || r < *rights.begin()) res[q_id] = 1;
    }
    for (int i = 0; i < q; i++) cout << (res[i] ? "YES\n" : "NO\n");
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