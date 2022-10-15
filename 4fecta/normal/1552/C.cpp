#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 205;

int t, n, k, u, v, used[MN];
vector<pii> edges;

bool in(int l, int r, int x) {
    if (l <= r) return l < x && x < r;
    else return l < x || x < r;
}

bool inter(pii p, pii q) {
    if (in(p.f, p.s, q.f) && in(p.s, p.f, q.s)) return true;
    if (in(p.f, p.s, q.s) && in(p.s, p.f, q.f)) return true;
    return false;
}

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        edges.clear();
        memset(used, 0, sizeof(used));
        cin >> n >> k;
        for (int i = 1; i <= k; i++) {
            cin >> u >> v;
            u--, v--;
            edges.push_back({u, v});
            used[u] = 1;
            used[v] = 1;
        }
        vector<int> vec;
        for (int i = 0; i < 2 * n; i++) if (!used[i]) vec.push_back(i);
        for (int i = 0; i < vec.size() / 2; i++) edges.push_back({vec[i], vec[i + vec.size() / 2]});
        int ans = 0;
        for (int i = 0; i < edges.size(); i++) {
            for (int j = i + 1; j < edges.size(); j++) {
                ans += inter(edges[i], edges[j]);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}