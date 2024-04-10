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

int t, n, m, a[MN * MN], pos[MN * MN], occ[MN][MN], bit[MN][MN];
map<int, int> mp[MN];

bool cmp(pii x, pii y) {
    if (x.f != y.f) return x.f < y.f;
    return x.s > y.s;
}

void upd(int x, int y, int val) {
    for (int i = y; i < MN; i += i & -i) bit[x][i] += val;
}

int qry(int x, int y) {
    int ret = 0;
    for (int i = y; i > 0; i -= i & -i) ret += bit[x][i];
    return ret;
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        memset(pos, 0, sizeof(pos));
        memset(occ, 0, sizeof(occ));
        memset(bit, 0, sizeof(bit));
        for (int i = 0; i < MN; i++) mp[i].clear();
        cin >> n >> m;
        vector<pii> v;
        for (int i = 1; i <= n * m; i++) cin >> a[i], v.push_back({a[i], i});
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) pos[v[i].s] = i + 1;
        int ans = 0;
        for (int i = 1; i <= n * m; i++) {
            int r = (pos[i] - 1) / m + 1;
            int c = (pos[i] - 1) % m + 1;
            //printf("%d %d\n", r, c);
            ans += qry(r, c) - mp[r][a[i]];
            upd(r, c, 1);
            mp[r][a[i]]++;
            /*for (int j = 1; j < pos[i]; j++) ans += occ[j];
            occ[pos[i]] = 1;*/
        }
        printf("%lld\n", ans);
    }

    return 0;
}