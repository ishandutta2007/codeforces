#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011
#define maxLog 19
#define inf (1LL << 60)

int n, m, R, i, x, y, w;
vector< pair<int, int> > list[maxN];
priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > H;
ll dist[maxN];
vector<int> ord;

vector<int> adj[maxN];
int lvl[maxN];
int dad[maxLog][maxN];

vector<int> tree[maxN];
int cnt[maxN];
int ans;


void dijk() {
    int i;

    for (i = 1; i <= n; i++) dist[i] = inf;

    dist[R] = 0;
    H.push(mp(0, R));

    while (!H.empty()) {
        ll act_dist = H.top().first;
        int node = H.top().second;
        H.pop();

        if (dist[node] != act_dist) continue;
        ord.pb(node);

        for (auto to : list[node]) {
            if (dist[to.first] <= dist[node] + to.second) continue;
            dist[to.first] = dist[node] + to.second;
            H.push(mp(dist[to.first], to.first));
        }
    }

    for (auto node : ord) {
        for (auto to : list[node]) {
            if (dist[node] + to.second == dist[to.first]) {
                adj[to.first].pb(node);
            }
        }
    }
}

int lca(int x, int y) {
    if (lvl[x] > lvl[y]) swap(x, y);

    int dif = lvl[y] - lvl[x];
    for (int step = maxLog - 1; step >= 0; step--)
        if (dif & (1 << step))
            y = dad[step][y];

    if (x == y) return x;

    for (int step = maxLog - 1; step >= 0; step--) {
        if (dad[step][x] == dad[step][y]) continue;
        x = dad[step][x];
        y = dad[step][y];
    }

    return dad[0][x];
}

void build_tree() {
    int daddy, i;

    for (auto node : ord) {
        if (node == R) continue;

        daddy = adj[node][0];
        for (i = 1; i < adj[node].size(); i++)
            daddy = lca(daddy, adj[node][i]);

        tree[daddy].pb(node);
        lvl[node] = lvl[daddy] + 1;
        dad[0][node] = daddy;

        for (int step = 1; step < maxLog; step++)
            dad[step][node] = dad[step - 1][ dad[step - 1][node] ];
    }
}

void dfs(int node) {
    cnt[node] = 1;

    for (int to : tree[node])
        dfs(to), cnt[node] += cnt[to];

    if (node != R)
        ans = max(ans, cnt[node]);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &R);
    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &w);
        list[x].pb(mp(y, w));
        list[y].pb(mp(x, w));
    }

    dijk();
    build_tree();
    dfs(R);

    printf("%d", ans);


    return 0;
}