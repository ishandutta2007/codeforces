#include<bits/stdc++.h>

using namespace std;

#define int long long
vector < int > g[4], pref[4];
int const maxn = 1e5 + 5;
pair < int, int > goal[maxn];
int sum[maxn], cnt[maxn], nxt[3][maxn], lst[maxn];
int inf = 1e18;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, w, c, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> w >> c;
        g[w].push_back(c);
    }
    for (int i = 1; i <= 3; ++i) sort(g[i].rbegin(), g[i].rend());
    for (int i = 1; i <= 3; ++i) {
        int sum = 0, f = 0;
        for (auto key : g[i]) {
            f += key;
            pref[i].push_back(f);
        }
    }
    int ptr = 1;
    for (int i = 1; i <= 2; ++i) {
        for (auto key : g[i]) goal[ptr++] = {key, i};
    }
    sort(goal + 1, goal + ptr, [](pair < int, int > s1, pair < int, int > s2) {
        return s1.first * s2.second > s2.first * s1.second;
    });
    for (int i = 1; i < ptr; ++i) sum[i] = sum[i - 1] + goal[i].first, cnt[i] = cnt[i - 1] + goal[i].second;
    for (int i = ptr - 1; i >= 1; --i) {
        if (goal[i + 1].second == 1) nxt[1][i] = goal[i + 1].first;
        else nxt[1][i] = nxt[1][i + 1];
        if (goal[i + 1].second == 2) nxt[2][i] = goal[i + 1].first;
        else nxt[2][i] = nxt[2][i + 1];
    }
    lst[0] = inf;
    for (int i = 1; i < ptr; ++i) {
        if (goal[i].second == 1) lst[i] = goal[i].first;
        else lst[i] = lst[i - 1];
    }
    lst[ptr] = lst[ptr - 1];
    for (int j = 1; j <= 2; ++j) nxt[j][0] = nxt[j][1];
    for (int i = 0; i <= (int)g[3].size(); ++i) {
        int f = m - 3 * i;
        if (f >= 0) {
            int cur = 0;
            if (i > 0) cur = pref[3][i - 1];
            int lef = 0, righ = ptr;
            while (righ - lef > 1) {
                int mid = (righ + lef) / 2;
                if (cnt[mid] <= f) lef = mid;
                else righ = mid;
            }
            if (lef == ptr - 1) ans = max(ans, cur + sum[lef]);
            else {
                if (cnt[lef] == f) ans = max(ans, cur + sum[lef]);
                else {
                    //cout << lef << " " << sum[lef] << " " << cnt[lef] << " " << f << " " << nxt[1][lef] << endl;
                    ans = max(ans, cur + sum[lef] + nxt[1][lef]);
                    ans = max(ans, cur - lst[lef] + nxt[2][lef] + sum[lef]);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}