#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 105;

int n, k, c[MN * MN], sum[MN * MN], pre[MN], done[MN];
vector<int> pos[MN], adj[MN][MN];
pii ans[MN];

bool inter(pii p, pii q) {
    return !(p.s < q.f || q.s < p.f);
}

int32_t main() {
    boost();

    cin >> n >> k;
    int len = (n + k - 2) / (k - 1);
    for (int i = 1; i <= n * k; i++) {
        cin >> c[i];
        pos[c[i]].push_back(i);
    }
    /*for (int i = 1; i < n; i++) {
        for (int p1 = 1; p1 < k; p1++) {
            for (int p2 = 1; p2 < k; p2++) {
                if (inter({pos[i][p1 - 1], pos[i][p1]}, {pos[i + 1][p2 - 1], pos[i + 1][p2]})) adj[i][p1].push_back(p2);
            }
        }
    }*/
    for (int i = 1; i <= n * k; i++) {
        if (done[c[i]] || !pre[c[i]]) {pre[c[i]] = i; continue;}
        int mx = 0;
        for (int j = pre[c[i]]; j <= i; j++) mx = max(mx, sum[j]);
        if (mx >= len) {pre[c[i]] = i; continue;}
        for (int j = pre[c[i]]; j <= i; j++) sum[j]++;
        ans[c[i]] = {pre[c[i]], i};
        done[c[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        assert(done[i]);
        printf("%lld %lld\n", ans[i].f, ans[i].s);
    }

    return 0;
}