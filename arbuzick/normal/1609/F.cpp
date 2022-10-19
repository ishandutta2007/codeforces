#pragma GCC optimize("O3")
//#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include <algorithm>
#include <iostream>

//#define _USE_MATH_DEFINE
using namespace std;
//#define int long long

const int maxn = 1e6 + 6, lg = 60;

long long a[maxn], mn[maxn], mx[maxn];
int cnt[maxn][60];

long long ans = 0;

void count(int l, int r) {
    if (l == r - 1) {
        ans++;
        return;
    }
    int m = (l + r) / 2;
    count(l, m);
    count(m, r);
    long long pr = ans;
    mn[0] = mx[0] = a[m];
    for (int i = 0; i < lg; ++i) {
        cnt[1][i] = 0;
        cnt[0][i] = 0;
    }
    cnt[1][__builtin_popcountll(a[m])] = 1;
    for (int i = 1; i < r - m; ++i) {
        mn[i] = min(mn[i - 1], a[m + i]);
        mx[i] = max(mx[i - 1], a[m + i]);
        for (int j = 0; j < lg; ++j) {
            cnt[i + 1][j] = cnt[i][j];
        }
        cnt[i + 1][__builtin_popcountll(mx[i])]++;
    }
    long long mn1 = (1LL << lg), mx1 = 0;
    for (int i = m - 1; i >= l; --i) {
        mn1 = min(mn1, a[i]);
        mx1 = max(mx1, a[i]);
        int ll = -1, rr = r - m;
        while (ll < rr - 1) {
            int mm = (ll + rr) / 2;
            if (mn[mm] >= mn1) {
                ll = mm;
            } else {
                rr = mm;
            }
        }
        ll++;
        int ll2 = -1, rr2 = ll;
        while (ll2 < rr2 - 1) {
            int mm = (ll2 + rr2) / 2;
            if (mx[mm] <= mx1) {
                ll2 = mm;
            } else {
                rr2 = mm;
            }
        }
        ll2++;
        int c1 = __builtin_popcountll(mn1);
        if (__builtin_popcountll(mx1) == c1) {
            ans += ll2;
        }
        if (ll2 != ll) {
            ans += cnt[ll][c1] - cnt[ll2][c1];
        }
    }

    mn[0] = mx[0] = a[m - 1];
    for (int i = 0; i < lg; ++i) {
        cnt[1][i] = 0;
        cnt[0][i] = 0;
    }
    cnt[1][__builtin_popcountll(a[m - 1])] = 1;
    for (int i = 1; i < m - l; ++i) {
        mn[i] = min(mn[i - 1], a[m - i - 1]);
        mx[i] = max(mx[i - 1], a[m - i - 1]);
        for (int j = 0; j < lg; ++j) {
            cnt[i + 1][j] = cnt[i][j];
        }
        cnt[i + 1][__builtin_popcountll(mx[i])]++;
    }
    mn1 = (1LL << lg), mx1 = 0;
    for (int i = m; i < r; ++i) {
        mn1 = min(mn1, a[i]);
        mx1 = max(mx1, a[i]);
        int ll = -1, rr = m - l;
        while (ll < rr - 1) {
            int mm = (ll + rr) / 2;
            if (mn[mm] > mn1) {
                ll = mm;
            } else {
                rr = mm;
            }
        }
        ll++;
        int ll2 = -1, rr2 = ll;
        while (ll2 < rr2 - 1) {
            int mm = (ll2 + rr2) / 2;
            if (mx[mm] <= mx1) {
                ll2 = mm;
            } else {
                rr2 = mm;
            }
        }
        ll2++;
        int c1 = __builtin_popcountll(mn1);
        if (__builtin_popcountll(mx1) == c1) {
            ans += ll2;
        }
        if (ll2 != ll) {
            ans += cnt[ll][c1] - cnt[ll2][c1];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    count(0, n);
    cout << ans;
    return 0;
}