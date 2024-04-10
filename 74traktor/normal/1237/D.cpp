#include <bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5, logg = 18;
int a[maxn];
int imin[4 * maxn][logg];
int imax[4 * maxn][logg];
int ans[maxn];
int ans1[maxn];
int sz[maxn];
int inf = 1e9;

inline get_min(int l, int r) {
    int t = sz[r - l + 1];
    return min(imin[l][t], imin[r - (1 << t) + 1][t]);
}

inline get_max(int l, int r) {
    int t = sz[r - l + 1];
    return max(imax[l][t], imax[r - (1 << t) + 1][t]);
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int mini = inf, maxi = -1 * inf;
    for (int i = 1; i <= n; ++i) {
        mini = min(mini, a[i]), maxi = max(maxi, a[i]);
    }
    for (int i = 1; i <= 4 * n; ++i) for (int j = 0; j < logg; ++j) imin[i][j] = inf, imax[i][j] = -inf;
    for (int i = 1; i <= n; ++i) imin[i][0] = a[i], imax[i][0] = a[i];
    for (int j = 1; j < logg; ++j) {
        for (int i = 1; i <= n; ++i) {
            imin[i][j] = min(imin[i][j - 1], imin[i + (1 << (j - 1))][j - 1]);
            imax[i][j] = max(imax[i][j - 1], imax[i + (1 << (j - 1))][j - 1]);
        }
    }
    int nxt = 2;
    for (int i = 2; i <= n; ++i) {
        sz[i] = sz[i - 1];
        if (i == nxt) sz[i]++, nxt *= 2;
    }
    if (mini * 2 >= maxi) {
        for (int i = 1; i <= n; ++i) cout << -1 << " ";
        cout << '\n';
        return 0;
    }
    for (int j = 0; j < 20; ++j) {
        for (int i = n; i >= 1; --i) {
            int lef = i, righ = n + 1;
            while (righ - lef > 1) {
                int mid = (righ + lef) / 2;
                int min_x = get_min(i, mid), max_x = get_max(i, mid);
                if (min_x * 2 < a[i] || max_x > a[i]) righ = mid;
                else lef = mid;
            }
            ans[i] = righ - i;
            if (righ == n + 1) {
                int lef = 0, righ = n + 1;
                while (righ - lef > 1) {
                    int mid = (righ + lef) / 2;
                    int min_x = get_min(1, mid), max_x = get_max(1, mid);
                    if (min_x * 2 < a[i] || max_x > a[i]) righ = mid;
                    else lef = mid;
                }
                //if (i == 4) cout << righ << '\n';
                ans[i] += (righ - 1);
                if (a[righ] > a[i]) ans[i] += ans[righ];
            }
            else if (a[righ] > a[i]) {
                ans[i] += ans[righ];
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << '\n';
    /*for (int i = 1; i <= n; ++i) {
        int x = a[i], y = a[i];
        int j = i;
        while (1) {
            if (2 * a[j] < y) break;
            y = max(y, a[j]);
            ans[i]--;
            ++j;
            if (j == n + 1) j = 1;
        }
        //cout << j << endl;
    }
    //for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    for (int i = 1; i <= n; ++i) {
        if (ans[i] != 0) {
            cout << "WA" << endl;
            return 0;
        }
    }*/
    return 0;
}