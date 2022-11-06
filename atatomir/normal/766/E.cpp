#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

const int bits = 20;

int n, i, x, y;
int v[maxN];
vector<int> list[maxN];
int cnt[2][bits + 3];

bool dead[maxN];
int down[maxN], up[maxN];

ll ans;


void refresh(int node) {
    for (int i = 0; i < list[node].size(); i++) {
        if (dead[list[node][i]]) {
            list[node][i] = list[node].back();
            list[node].pop_back();
            i--; continue;
        }
    }
}

void dfs_down(int node, int root) {
    down[node] = 1;

    refresh(node);
    for (auto to : list[node]) {
        if (to == root) continue;
        dfs_down(to, node);
        down[node] += down[to];
    }
}

int get_centroid(int node, int root, int target) {
    up[node] = target - down[node];
    bool ok = (up[node] <= target / 2);

    for (auto to : list[node]) {
        if (to == root) continue;

        int ans = get_centroid(to, node, target);
        if (ans) return ans;

        if (down[to] > target / 2) ok = false;
    }

    if (ok) return node;
    return 0;
}

void add(int x) {
    int i;

    for (i = 0; i <= bits; i++)
        if (x & (1 << i))
            cnt[1][i]++;
        else
            cnt[0][i]++;
}

void get_way(int x) {
    for (i = 0; i <= bits; i++) {
        int act = (x >> i) & 1;
        ans += (1LL << i) * cnt[act ^ 1][i];
    }
}

void dfs_ways(int node, int root, int on_way) {
    on_way ^= v[node];
    get_way(on_way);

    for (auto to : list[node])
        if (to != root)
            dfs_ways(to, node, on_way);
}

void dfs_add(int node, int root, int on_way) {
    on_way ^= v[node];
    add(on_way);

    for (auto to : list[node])
        if (to != root)
            dfs_add(to, node, on_way);
}

void solve(int node) {
    int i, target;

    dfs_down(node, 0);

    target = down[node];
    node = get_centroid(node, 0, target);

    memset(cnt, 0, sizeof(cnt));
    add(v[node]);
    get_way(0);

    for (auto to : list[node]) {
        dfs_ways(to, node, 0);
        dfs_add(to, node, v[node]);
    }

    dead[node] = true;
    for (auto to : list[node])
        solve(to);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &v[i]);

    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    solve(1);
    printf("%lld", ans);



    return 0;
}