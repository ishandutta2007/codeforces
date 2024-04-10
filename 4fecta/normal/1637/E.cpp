#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 300005, SQRT = 550, MOD = 1e9 + 7;

int t, n, m, a[MN], u, v;
vector<int> vals[SQRT]; //which vals have this freq

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        map<int, int> cnt;
        gp_hash_table<int, int> bad;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
        for (int i = 1; i <= m; i++) {
            cin >> u >> v;
            if (u > v) swap(u, v);
            bad[u * MOD + v] = 1;
        }
        vector<pii> big;
        for (pii p : cnt) {
            if (p.s < SQRT) vals[p.s].push_back(p.f);
            else big.push_back(p);
        }
        int ans = -1;
        for (int i = 0; i < big.size(); i++) {
            for (int j = i + 1; j < big.size(); j++) {
                int hsh = 0;
                if (big[i].f < big[j].f) hsh = big[i].f * MOD + big[j].f;
                else hsh = big[j].f * MOD + big[i].f;
                if (bad.find(hsh) != bad.end()) continue;
                ans = max(ans, (big[i].f + big[j].f) * (big[i].s + big[j].s));
            }
        }
        for (int i = 1; i < SQRT; i++) sort(vals[i].begin(), vals[i].end(), greater<>());
        for (pii p : big) {
            for (int i = SQRT - 1; i > 0; i--) {
                for (int q : vals[i]) {
                    if ((p.f + q) * (p.s + i) <= ans) break;
                    int hsh = 0;
                    if (p.f < q) hsh = p.f * MOD + q;
                    else hsh = q * MOD + p.f;
                    if (bad.find(hsh) != bad.end()) continue;
                    ans = (p.f + q) * (p.s + i);
                }
            }
        }
        for (int j = SQRT - 1; j > 0; j--) {
            for (int k : vals[j]) {
                pii p = {k, j};
                for (int i = j; i > 0; i--) {
                    for (int q : vals[i]) {
                        if ((p.f + q) * (p.s + i) <= ans) break;
                        int hsh = 0;
                        if (p.f < q) hsh = p.f * MOD + q;
                        else hsh = q * MOD + p.f;
                        if (bad.find(hsh) != bad.end() || p.f == q) continue;
                        ans = (p.f + q) * (p.s + i);
                    }
                }
            }
        }
        printf("%lld\n", ans);
        for (int i = 1; i < SQRT; i++) vals[i].clear();
    }

    return 0;
}