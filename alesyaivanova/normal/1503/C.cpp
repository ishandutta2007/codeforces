#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
const int lg = 20;
int mi1[maxn][lg];
int mi2[maxn][lg];
pii a[maxn];
int n;
int pref_c[maxn];
int dp[maxn];
int inf = 1e18;
int prec[maxn];

int get1(int l, int r) {
    int e = prec[r - l + 1];
    return min(mi1[l][e], mi1[r - (1 << e) + 1][e]);
}

int get2(int l, int r) {
    int e = prec[r - l + 1];
//    cout << " " << l << " " << r << " " << e << "\n";
    return min(mi2[l][e], mi2[r - (1 << e) + 1][e]);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 1; i < maxn; i++) {
        prec[i] = prec[i - 1];
        if ((1 << (prec[i] + 1)) <= i)
            prec[i]++;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].ff >> a[i].ss;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        pref_c[i] = (i ? pref_c[i - 1] : 0) + a[i].ss;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            dp[i] = a[i].ss;
        } else {
            dp[i] = inf;
            int r = lower_bound(a, a + n, mp(a[i].ff + a[i].ss + 1, 0ll)) - a - 1;
            r = max(r, i);
//            cout << i << " " << r << "\n";
            if (r >= i + 1) {
                dp[i] = get1(i + 1, r) - (i ? pref_c[i - 1] : 0);
            }
            if (r < n - 1) {
                dp[i] = min(dp[i], get2(r + 1, n - 1) - pref_c[i] - a[i].ff);
            }
//            cout << "   " << get2(r + 1, n - 1) << "\n";
        }
        if (!i)
            break;
        mi1[i][0] = dp[i] + pref_c[i - 1];
        mi2[i][0] = dp[i] + pref_c[i - 1] + a[i].ff;
        for (int e = 1; e < lg; e++) {
            mi1[i][e] = mi1[i][e - 1];
            mi2[i][e] = mi2[i][e - 1];
            if (i + (1 << (e - 1)) < n) {
                mi1[i][e] = min(mi1[i][e], mi1[i + (1 << (e - 1))][e - 1]);
                mi2[i][e] = min(mi2[i][e], mi2[i + (1 << (e - 1))][e - 1]);
            }
        }
    }
//    for (int i = 0; i < n; i++)
//        cout << dp[i] << " ";
//    cout << "\n";
    cout << dp[0];
}