#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn];
vector < pair < int, int > > open[maxn];
int R[maxn];
int dp[maxn];
int inf = 1e9;

inline int ok(int x, int n, int t) {
    for (int i = 1; i <= n; ++i) R[i] = inf;
    for (int i = 1; i <= n; ++i) {
        for (auto key : open[i]) {
            if (x >= key.second || key.first < i) continue;
            R[key.first] = min(R[key.first], i);
        }
    }
    t -= (n + 1);
    int lst = 0;
    vector < pair < int, int > > st;
    multiset < int > Q;
    for (int i = 1; i <= n; ++i) {
        if (R[i] == inf) continue;
        //cout << R[i] << " " << i << '\n';
        dp[i] = (i - R[i] + 1) * 2 + lst;
        int s = inf;
        while ((int)st.size() > 0 && st.back().first > R[i]) {
            s = min(s, st.back().second);
            Q.erase(Q.find(st.back().second - 2 * st.back().first));
            st.pop_back();
        }
        dp[i] = min(dp[i], s + 2 * i + 2 - 2 * R[i]);
        if ((int)Q.size() > 0) {
            dp[i] = min(dp[i], 2 * i + 2 + (*Q.begin()));
        }
        s = min(s, lst);
        lst = dp[i];
        st.push_back({R[i], s});
        Q.insert(s - 2 * R[i]);
    }
    t -= lst;
    //cout << t << '\n';
    return t >= 0;
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n, k, t, l, r, d;
    cin >> m >> n >> k >> t;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    for (int i = 1; i <= k; ++i) {
        cin >> l >> r >> d;
        open[l].push_back({r, d});
    }
    sort(a + 1, a + m + 1);
    l = 0, r = m + 1;
    //cout << ok(3, n, t) << '\n';
    //return 0;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (ok(a[mid], n, t)) r = mid;
        else l = mid;
    }
    cout << m + 1 - r << '\n';
    return 0;
}