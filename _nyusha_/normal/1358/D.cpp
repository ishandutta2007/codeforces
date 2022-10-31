#include<bits/stdc++.h>

using namespace std;

#define int long long
int a[400005], val[400005], pref[400005], sum[400005];

int sums(int i) {
    return i * (i + 1) / 2;
}

int get(int i, int x) {
    x = min(x, a[i]);
    return x * (x + 1) / 2;
}

int get1(int i, int x) {
    x = min(x, a[i]);
    return sums(a[i]) - sums(a[i] - x);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, ans = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = n + 1; i <= 2 * n; ++i) a[i] = a[i - n];
    n *= 2;
    for (int i = 1; i <= n; ++i) {
        val[i] = a[i] * (a[i] + 1) / 2;
        pref[i] = pref[i - 1] + val[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        int lef = i, righ = n + 1;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            if (sum[mid] - sum[i] <= x - 1) lef = mid;
            else righ = mid;
        }
        ans = max(ans, a[i] + pref[lef] - pref[i] + get(lef + 1, x - 1 - (sum[lef] - sum[i])));
    }
    for (int i = 1; i <= n; ++i) {
        int lef = 1, righ = i + 1;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            if (sum[i] - sum[mid - 1] <= x) righ = mid;
            else lef = mid;
        }
        ans = max(ans, pref[i] - pref[righ - 1] + get1(righ - 1, x - (sum[i] - sum[righ - 1])));
    }
    cout << ans << '\n';
    return 0;
}