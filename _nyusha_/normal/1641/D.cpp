#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5, K = 200;
map < int, vector < int > > cnt;
map < int, int > numb;
bitset < maxn > used[5 * maxn / K];
int inf = 2e9 + 7;
bitset < maxn > one, dp;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x;
    cin >> n >> m;
    vector < vector < int > > Q;
    for (int i = 1; i <= n; ++i) {
        vector < int > b;
        for (int j = 1; j <= m + 1; ++j) {
            cin >> x;
            b.push_back(x);
        }
        reverse(b.begin(), b.end());
        Q.push_back(b);
    }
    sort(Q.begin(), Q.end());
    for (int i = 0; i < (int)Q.size(); ++i) {
        for (int j = 1; j <= m; ++j) {
            cnt[Q[i][j]].push_back(i);
        }
    }
    for (int i = 0; i < maxn; ++i) {
        one[i] = 1;
    }
    int ptr = 1;
    for (auto key : cnt) {
        if (key.second.size() > K) {
            numb[key.first] = ptr;
            used[ptr] = one;
            for (auto elem : key.second) {
                used[ptr][elem] = 0;
            }
            ptr++;
        }
    }
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        dp = one;
        for (int j = 1; j <= m; ++j) {
            if (numb[Q[i][j]] == 0) {
                for (auto key : cnt[Q[i][j]]) dp[key] = 0;
            } else dp &= used[numb[Q[i][j]]];
        }
        int pos = dp._Find_first();
        if (pos < n) ans = min(ans, Q[i][0] + Q[pos][0]);
    }
    if (ans == inf) ans = -1;
    cout << ans;
    return 0;
}