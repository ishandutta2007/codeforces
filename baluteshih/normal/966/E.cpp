#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int K = 800;

vector<int> G[100005];
vector<pii> bkt[100005];
int pa[100005], tag[100005], blw[100005], lazy[100005], val[100005], boss[100005];
int pt[100005], op[100005], ans[100005];
int srt[300005], nxt[100005];

int dfs(int u) {
    int sum = tag[u];
    for (int i : G[u])
        sum += dfs(i);
    if (sum > 1)
        tag[u] = 1;
    return blw[u] = (sum >= 1);
}

void dfs2(int u, int b) {
    boss[u] = b; 
    for (int i : G[u])
        if (blw[i]) {
            if (tag[u])
                dfs2(i, i);
            else
                dfs2(i, b);
        }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= n; ++i)
        cin >> pa[i], G[pa[i]].pb(i);
    for (int i = 1; i <= n; ++i)
        cin >> val[i];
    for (int i = 1; i <= m; ++i)
        cin >> op[i];
    for (int i = 1; i <= m; i += K) {
        int sum = 0;
        for (int j = 0; j <= n * 3; ++j)
            srt[j] = 0;
        for (int j = 1; j <= n; ++j)
            tag[j] = lazy[j] = blw[j] = boss[j] = 0, bkt[j].clear();
        for (int j = 1; j <= n; ++j) {
            nxt[j] = srt[val[j] + n];
            srt[val[j] + n] = j;
        }
        for (int j = i; j < min(i + K, m + 1); ++j)
            tag[abs(op[j])] = tag[pa[abs(op[j])]] = 1;

        dfs(1), dfs2(1, 1);

        auto bkt_pb = [](vector<pii> &vc, int v) {
            if (vc.empty() || vc.back().X != v)
                vc.pb(pii(v, 1));
            else
                ++vc.back().Y;
        };

        for (int j = 0; j < n; ++j)
            for (int k = srt[j]; k; k = nxt[k]) {
                bkt_pb(bkt[boss[k]], val[k]);
                ++sum;
            }
        for (int j = 1; j <= n; ++j)
            pt[j] = SZ(bkt[j]);
        for (int j = n; j <= n * 3; ++j)
            for (int k = srt[j]; k; k = nxt[k])
                bkt_pb(bkt[boss[k]], val[k]);

        auto mdfy = [&](int idx, int v) {
            if (idx == 0) return;
            lazy[idx] += v;
            while (pt[idx] < SZ(bkt[idx]) && bkt[idx][pt[idx]].X + lazy[idx] < 0)
                sum += bkt[idx][pt[idx]].Y, ++pt[idx];
            while (pt[idx] > 0 && bkt[idx][pt[idx] - 1].X + lazy[idx] >= 0)
                --pt[idx], sum -= bkt[idx][pt[idx]].Y;
        };

        for (int j = i; j < min(i + K, m + 1); ++j) {
            if (op[j] > 0) {
                mdfy(op[j], n);
                for (int u = pa[op[j]]; u; u = pa[u])
                    mdfy(u = boss[u], -1);
            }
            else {
                mdfy(-op[j], -n);
                for (int u = pa[-op[j]]; u; u = pa[u])
                    mdfy(u = boss[u], 1);
            }
            ans[j] = sum;
        }
        for (int j = 1; j <= n; ++j)
            val[j] += lazy[boss[j]];
    }
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << " \n"[i == m];
}