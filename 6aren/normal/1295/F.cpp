#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 105;
const int MOD = 998244353;

int n;
int r[N], l[N];
int len[N];
ii seg[N];
int cnt[N][N][N];
int pref[N][N];

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2) res = 1LL * res * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return res;
}

int inv(int x) {
    return power(x, MOD - 2);
}

int fac[N], ifac[N];

void init_combi() {
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[i] = inv(fac[i]); 
    }
}

// int C(int n, int k) {
//     return 1LL * ifac[k] * ifac[n - k] % MOD * fac[n] % MOD;
// }

int c(int k, int n) {
    long long res = ifac[k];
    for (int i = n - k + 1; i <= n; i++) {
        res = res * i % MOD;
    }
    return res;
}

int solve(int k, int n) {
    return c(k, n + k - 1);
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    init_combi();
    vector<int> v;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        cin >> l[i] >> r[i];
        len[i] = r[i] - l[i] + 1;
    }
    for (int i = 2; i <= n; i++) l[i] = max(l[i - 1], l[i]);
    for (int i = n - 1; i >= 1; i--) r[i] = min(r[i + 1], r[i]);
    for (int i = 1; i <= n; i++) v.pb(l[i]), v.pb(r[i] + 1);
    sort(all(v));
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int nSeg = v.size() - 1;
    for (int i = 1; i < v.size(); i++) {
        seg[i] = make_pair(v[i - 1], v[i] - 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 1; k <= nSeg; k++) {
                if (l[i] > seg[k].y || r[i] < seg[k].x) continue;
                if (l[j] > seg[k].x || r[j] < seg[k].x) continue;
                cnt[i][j][k] = solve(j - i + 1, seg[k].y - seg[k].x + 1);
                // cout << i << ' ' << j << ' ' << k << ' ' << cnt[i][j][k] << endl;
            }
        }
    }
    for (int i = 0; i < N; i++) pref[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= nSeg; j++) {
            if (l[i] <= seg[j].x && r[i] >= seg[j].y) {
                for (int k = i; k >= 1; k--) {
                    pref[i][j] += pref[k - 1][j - 1] * cnt[k][i][j];
                    pref[i][j] %= MOD;
                }
            }
            pref[i][j] += pref[i][j - 1];
            if (pref[i][j] > MOD) pref[i][j] -= MOD;
            // cout << i << ' ' << j << ' ' << pref[i][j] << endl;
        }
    }
    int ans = pref[n][nSeg];
    for (int i = 1; i <= n; i++) ans = ans * inv(len[i]) % MOD;
    cout << ans;
    return 0;
}