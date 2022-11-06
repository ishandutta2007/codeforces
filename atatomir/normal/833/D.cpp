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

const int maxN = 100011;
const ll mod = 1000000007;

struct edge {
    int to, tp;
    ll cost;
};

int n, i, x, y, z;
vector<edge> list[maxN];
ll aux, ans = 1;

bool dead[maxN];
int down[maxN];

vector< pair<int, ll> > here[2], global[2];


ll poww(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

ll inv(ll x) {
    return poww(x, mod - 2);
}

void clr(vector<edge>& data) {
    int i, p = 0;

    for (i = 0; i < data.size(); i++) {
        if (dead[data[i].to]) continue;
        data[p++] = data[i];
    }
    data.resize(p);
}

void dfs(int node, int root) {
    clr(list[node]);
    down[node] = 1;

    for (auto e : list[node])
        if (e.to != root)
            dfs(e.to, node), down[node] += down[e.to];
}

int dfs2(int node, int root, int target) {
    bool ok = (target - down[node]) <= target / 2;

    for (auto e : list[node]) {
        if (e.to == root) continue;
        int ans = dfs2(e.to, node, target);
        if (ans != 0) return ans;
        ok &= (down[e.to] <= target / 2);
    }

    if (ok) return node;
    return 0;
}

void dfs_add(int node, int root, ll cost, int t1, int t2) {
    here[0].pb(mp(t1, cost));
    here[1].pb(mp(t2, cost));

    for (auto e : list[node]) {
        if (e.to == root) continue;
        dfs_add(e.to, node, (cost * e.cost) % mod, t1 + (e.tp == 0 ? 2 : -1), t2 + (e.tp == 0 ? -1 : 2));
    }
}

ll get_combs(vector< pair<int, ll> >& data) {
    int i, j;
    ll ans = 1;

    sort(data.begin(), data.end());
    i = 0;
    for (j = data.size() - 1; j >= 0; j--) {
        while (i < data.size()) {
            if (data[j].first + data[i].first >= 0) break;
            i++;
        }

        if (i >= data.size()) break;
        ans = (ans * poww(data[j].second, data.size() - i)) % mod;
    }

    return ans;
}

void solve(int R) {
    ll aux;

    dfs(R, 0);
    R = dfs2(R, 0, down[R]);

    global[0] = global[1] = {mp(0, 1)};
    for (auto e : list[R]) {
        here[0].clear();
        here[1].clear();

        dfs_add(e.to, R, e.cost, (e.tp == 0 ? 2 : -1), (e.tp == 0 ? -1 : 2));
        aux = get_combs(here[0]) * get_combs(here[1]);
        aux = inv(aux % mod);
        ans = (ans * aux) % mod;

        for (auto e : here[0]) global[0].pb(e);
        for (auto e : here[1]) global[1].pb(e);
    }

    aux = get_combs(global[0]) * get_combs(global[1]);
    aux %= mod;
    ans = (ans * aux) % mod;

    dead[R] = true;
    for (auto e : list[R]) solve(e.to);
}

void dfs_rm(int node, int root) {
    down[node] = 1;

    for (auto e : list[node]) {
        if (e.to == root) continue;
        dfs_rm(e.to, node);
        down[node] += down[e.to];

        ll aux = poww(e.cost, 1LL * down[e.to] * (n - down[e.to]));
        ans = (ans * inv(aux)) %  mod;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d%d%lld%d", &x, &y, &aux, &z);
        list[x].pb({y, z, aux});
        list[y].pb({x, z, aux});
    }

    dfs_rm(1, 0);
    solve(1);


    printf("%lld", ans);

    return 0;
}