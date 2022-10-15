#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 305;

int t, n, m, a[MN], pos[MN], occ[MN];

bool cmp(pii x, pii y) {
    if (x.f != y.f) return x.f < y.f;
    return x.s > y.s;
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        memset(pos, 0, sizeof(pos));
        memset(occ, 0, sizeof(occ));
        cin >> n >> m;
        vector<pii> v;
        for (int i = 1; i <= m; i++) cin >> a[i], v.push_back({a[i], i});
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++) pos[v[i].s] = i + 1;
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j < pos[i]; j++) ans += occ[j];
            occ[pos[i]] = 1;
        }
        printf("%lld\n", ans);
    }

    return 0;
}