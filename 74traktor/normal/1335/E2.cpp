#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn], pref[205][maxn];
vector < int > go[205];

inline int get(int L, int R) {
    int ans = 0;
    for (int j = 1; j <= 200; ++j) ans = max(ans, pref[j][R] - pref[j][L - 1]);
    return ans;
}

int solve(int n) {
    int ans = 0;
    for (int i = 1; i <= 200; ++i) go[i] = {};
    for (int i = 1; i <= n; ++i) {
        go[a[i]].push_back(i);
        for (int j = 1; j <= 200; ++j) pref[j][i] = pref[j][i - 1];
        pref[a[i]][i]++;
    }
    for (int i = 1; i <= 200; ++i) {
        for (int j = 0; j < (int)go[i].size() / 2; ++j) {
            int L = go[i][j] + 1, R = go[i][(int)go[i].size() - j - 1] - 1;
            ans = max(ans, get(L, R) + 2 * (j + 1));
        }
    }
    return ans;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        ans = solve(n);
        for (int i = 1; i <= 200; ++i) ans = max(ans, pref[i][n]);
        cout << ans << '\n';
    }
    return 0;
}