#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011


int n, m, q, i, x, y, cnt;
vector<int> list[maxN];

int gr[maxN];
vector<ll> vals[maxN], sums[maxN];
ll best_dist[maxN];
map< pair<int, int>, ll > M;

void dfs(int node) {
    gr[node] = cnt;
    vals[cnt].pb(node);

    for (auto to : list[node])
        if (gr[to] == 0)
            dfs(to);
}

pair<int, int> dfs2(int node, int root, int lvl) {
    pair<int, int> ans = mp(lvl, node);
    best_dist[node] = max(best_dist[node], 1LL * lvl);

    for (auto to : list[node]) {
        if (to == root) continue;
        ans = max(ans, dfs2(to, node, lvl + 1));
    }

    return ans;
}

void pre() {
    int i, d1, d2;

    for (i = 1; i <= n; i++) {
        if (gr[i]) continue;
        cnt++;
        dfs(i);

        d1 = dfs2(i, 0, 0).second;
        d2 = dfs2(d1, 0, 0).second;
        dfs2(d2, 0, 0);

        for (auto& e: vals[cnt])
            e = best_dist[e];

        sort(vals[cnt].begin(), vals[cnt].end());
        sums[cnt] = vals[cnt];
        for (int j = 1; j < sums[cnt].size(); j++) sums[cnt][j] += sums[cnt][j - 1];
    }
}

ll solve(int x, int y) {
    int p;

    if (M[mp(x, y)] != 0) return M[mp(x, y)];
    ll ans = 0;
    ll maxi;

    if (vals[x].size() > vals[y].size()) swap(x, y);
    ans += 1LL * vals[x].size() * sums[y].back() + 1LL * vals[y].size() * sums[x].back() + 1LL * vals[x].size() * vals[y].size();
    maxi = max(vals[x].back(), vals[y].back());

    //if (x == 8 && y == 3)
    //    cerr << "d";


    for (auto e : vals[x]) {
        p = lower_bound(vals[y].begin(), vals[y].end(), maxi - e - 1) - vals[y].begin();
        if (p == 0) continue;

        ans -= sums[y][p - 1];
        ans -= 1LL * e * p;
        ans -= p;
        ans += maxi * p;
    }


    if (x > y) swap(x, y);
    M[mp(x, y)] = ans;
    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &q);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    pre();
    for (i = 1; i <= q; i++) {
        scanf("%d%d", &x, &y);
        x = gr[x];
        y = gr[y];
        if (x > y) swap(x, y);

        if (x == y) {
            printf("-1\n");
            continue;
        }

        double ans = 1.00 * solve(x, y) / (1.00 * vals[x].size() * vals[y].size());
        printf("%.10lf\n", ans);

        //if (i == 17) cerr << "!! " << setprecision(10) << ans << '\n';
    }


    return 0;
}