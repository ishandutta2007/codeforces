#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
const int INF = 1e9;

int n;
int a[N];
int dp[N];
int nxt[N];
set<pair<int, int>> s[N];
int valBest[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 0; i <= n; i++) {
            dp[i] = INF;
            s[i].clear();
            valBest[i] = INF;
        }
        vector<int> st;
        for (int i = n; i; i--) {
            while (!st.empty() && a[i] > a[st.back()]) st.pop_back();
            if (st.empty()) nxt[i] = n + 1;
            else nxt[i] = st.back();
            st.push_back(i);
        }
        nxt[0] = 1;

        s[0].insert({1, 0});
        dp[0] = 0;

        auto update = [&](int u, int v) {
            s[u].insert({nxt[v], a[v]});
            dp[u] = a[v];
        };

        auto check = [&](int u, int v) {
            while (!s[u].empty() && s[u].begin()->first < v) {
                valBest[u] = min(valBest[u], s[u].begin()->second);
                s[u].erase(s[u].begin());
            }
            return valBest[u] <= a[v];
        };

        for (int i = 1; i <= n; i++) {
            int id = upper_bound(dp, dp + n + 1, a[i]) - dp;
            update(id, i);
            if (check(id - 1, i)) update(id + 1, i);
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (dp[i] < INF) res = i;
        }
        cout << res << '\n';
    }
    return 0;
}