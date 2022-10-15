#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005, MOD = 998244353;

int t, n, a[MN], d[MN];
vector<int> ds[MN];

int calc(int l, int r) {
    int mn = 0x3f3f3f3f, ret = 0;
    for (int i = r; i >= l; i--) {
        for (int j = 1; j <= a[i]; j++) {
            int d = a[i] / j, m = (a[i] % j) > 0;
            if (d + m <= mn) {ret += j - 1; mn = d; break;}
        }
    }
    return ret;
}

inline int get_nxt(int num, int div) {
    int lo = div + 1, hi = num, mid;
    for (lo = div + 1; lo <= div + 7; lo++) {
        if (num / lo < num / div || (num % lo == 0 && num % div != 0)) return lo;
    }
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (num / mid < num / div || (num % mid == 0 && num % div != 0)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int32_t main() {
    boost();

    /*a[1] = 99;
    for (int j = 1; j <= a[1]; j++) {
        int d = a[1] / j, m = (a[1] % j) > 0;
        printf("%lld %lld %lld\n", j, d, m);
    }*/
    //int cnt = 0;
    /*for (int i = 1; i < MN; i++) {
        int div = 1;
        ds[i].push_back(div);
        while (div < i) {
            int lo = div + 1, hi = i, mid;
            for (lo = div + 1; lo <= div + 7; lo++) {
                //cnt++;
                if (i / lo < i / div || (i % lo == 0 && i % div != 0)) goto done;
            }
            while (lo < hi) {
                //cnt++;
                mid = (lo + hi) >> 1;
                if (i / mid < i / div || (i % mid == 0 && i % div != 0)) hi = mid;
                else lo = mid + 1;
            }
            done:
            div = lo;
            ds[i].push_back(div);
        }
    }*/
    //printf("%lld\n", cnt);
    //for (int d : ds[99]) printf("%d\n", d);
    cin >> t;
    while (t--) {
        cin >> n;
        int tot = 0, cur = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i], d[i] = 1;
            int lim = a[i];
            for (int j = i - 1; j > 0; j--) {
                if ((a[j] / d[j]) + (a[j] % d[j] > 0) <= lim) break;
                while ((a[j] / d[j]) + (a[j] % d[j] > 0) > lim) {
                    int o = d[j];
                    d[j] = get_nxt(a[j], d[j]), cur = (cur + j * (d[j] - o)) % MOD;
                }
                lim = a[j] / d[j];
            }
            tot = (tot + cur) % MOD;
        }
        /*int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                ans += calc(j, i), ans %= MOD;
            }
            printf("%lld\n", ans);
        }*/
        //printf("%lld ", ans);
        printf("%lld\n", tot);

    }

    return 0;
}