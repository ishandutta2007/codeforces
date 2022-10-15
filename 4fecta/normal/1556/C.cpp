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

int n, c[MN], ans, suf[MN][MN];

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 2; i <= n; i += 2) {
        suf[i][i] = c[i];
        int cnt = c[i];
        for (int j = i - 1; j > 0; j--) {
            if (j & 1) cnt -= c[i];
            else cnt += c[i];
            suf[j][i] = min(suf[j + 1][i], cnt);
        }
    }
    for (int i = 1; i <= n; i += 2) {
        int cnt = 0;
        int f = c[i];
        for (int j = i; j <= n; j++) {
            if (j & 1) cnt += c[j];
            else {
                cnt -= c[j];
                if (cnt < 0) {
                    int s = max(0ll, c[j] + cnt);
                    ans += min(f, s);
                    break;
                }
                int lft = cnt, rit = f;
                int ff = max(0ll, rit - lft);
                ans += min(ff, c[j]);
                //printf("%d %d %d\n", cnt, f, ans);
                f = min(f, cnt + 1);
            }
        }
        //printf("%lld\n", ans);
    }
    printf("%lld\n", ans);

    return 0;
}