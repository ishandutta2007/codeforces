#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 1005;

int n, k, c[MN][MN];

void solve(int l, int r, int col) {
    if (l == r) return;
    int sz = (r - l + 1) / k, rem = (r - l + 1) % k;
    vector<vector<int>> gps;
    int cl = l;
    for (int i = 1; i <= k; i++) {
        int cr = cl + sz - 1;
        if (rem) cr++, rem--;
        vector<int> v;
        for (int j = cl; j <= cr; j++) v.push_back(j);
        gps.push_back(v);
        cl = cr + 1;
    }
    for (int i = 0; i < gps.size(); i++) {
        for (int j = i + 1; j < gps.size(); j++) {
            for (int p : gps[i]) {
                for (int q : gps[j]) c[p][q] = col;
            }
        }
    }
    for (int i = 0; i < gps.size(); i++) {
        if (gps[i].size()) solve(gps[i][0], gps[i].back(), col + 1);
    }
}

int32_t main() {
    boost();

    cin >> n >> k;
    solve(1, n, 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            mx = max(mx, c[i][j]);
        }
    }
    printf("%lld\n", mx);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            printf("%lld ", c[i][j]);
        }
    }

    return 0;
}