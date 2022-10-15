#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 300005, MM = 4005, MOD = 1e9 + 7;

int n, h, w, r, c, s, ans[MM][22], fact[MN], inv[MN], val[22];
vector<pii> pts;

int fpow(int b, int p) {
    if (!p) return 1;
    int ret = fpow(b, p / 2);
    if (p & 1) return ret * ret % MOD * b % MOD;
    return ret * ret % MOD;
}

int calc(int x, int y) {
    return fact[x + y] * inv[x] % MOD * inv[y] % MOD;
}

int32_t main() {
    boost();

    cin >> h >> w >> n >> s;
    val[0] = s;
    for (int i = 1; i <= 20; i++) {
        val[i] = val[i - 1] / 2;
        if (val[i - 1] & 1) val[i]++;
    }
    fact[0] = inv[0] = 1;
    for (int i = 1; i < MN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = fpow(fact[i], MOD - 2);
    }
    for (int i = 1; i <= n; i++) {
        cin >> r >> c;
        pts.push_back({r, c});
    }
    pts.push_back({h, w});
    sort(pts.begin(), pts.end());
    for (int k = 0; k <= 20; k++) {
        for (int i = 0; i < pts.size(); i++) {
            //printf("%d %d\n", pts[i].f, pts[i].s);
            ans[i][k] += calc(pts[i].f - 1, pts[i].s - 1);
            for (int pre = 0; pre < k; pre++) ans[i][k] -= ans[i][pre];
            ans[i][k] %= MOD; ans[i][k] += MOD; ans[i][k] %= MOD;
            for (int j = i + 1; j < pts.size(); j++) {
                if (pts[j].f < pts[i].f || pts[j].s < pts[i].s) continue;
                ans[j][k] -= ans[i][k] * calc(pts[j].f - pts[i].f, pts[j].s - pts[i].s);
                //printf("%d %d %d\n",j, ans[i], calc(pts[j].f - pts[i].f, pts[j].s - pts[i].s));
                ans[j][k] %= MOD;
            }
        }
    }
    int tot = calc(h - 1, w - 1);
    int den = calc(h - 1, w - 1);
    int ret = 0;
    for (int i = 0; i <= 20; i++) ret += ans[pts.size() - 1][i] * val[i] % MOD, tot -= ans[pts.size() - 1][i];
    tot %= MOD; tot += MOD; tot %= MOD;
    ret += tot;
    printf("%lld\n", (ret * fpow(den, MOD - 2) % MOD + MOD) % MOD);

    return 0;
}