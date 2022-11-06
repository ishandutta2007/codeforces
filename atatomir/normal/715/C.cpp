#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

int n, M, i, x, y, z;
vector< pair<int, int> > list[maxN];

int target;
ll inv_ten, pow_ten[maxN];
bool us[maxN];
int cnt[maxN];

int maps_set, last_asso[maxN];
ll down[maxN], up[maxN];
map<int, int> full, sons[maxN];

ll ans;


ll poww(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % M;
        b >>= 1;
        a = (a * a) % M;
    }

    return ans;
}

void compute_inverse() {
    ll i, j;
    ll ans = M;
    ll aux = M;

    for (i = 2; i * i <= aux; i++) {
        if (aux % i) continue;

        ans /= i;
        ans *= (i - 1);

        while (aux % i == 0)
            aux /= i;
    }

    if (aux != 1) {
        ans /= aux;
        ans *= aux - 1;
    }

    ans--;
    inv_ten = poww(10, ans);

    pow_ten[0] = 1;
    for (i = 1; i <= n; i++)
        pow_ten[i] = (pow_ten[i - 1] * 10) % M;
}


void dfs_cnt(int node, int dad) {
    cnt[node] = 1;

    for (auto to : list[node])
        if (!us[to.first] && to.first != dad)
            dfs_cnt(to.first, node), cnt[node] += cnt[to.first];
}

int find_centroid(int node, int dad) {
    bool all_good = (target - cnt[node] <= target / 2);

    for (auto to : list[node]) {
        if (us[to.first] || to.first == dad) continue;
        all_good &= (cnt[to.first] <= target / 2);

        int ans = find_centroid(to.first, node);
        if (ans) return ans;
    }

    if (all_good)
        return node;
    return 0;
}

void compute(int node, int dad, int lvl, int asso) {
    last_asso[node] = asso;

    if (dad != 0) {
        full[up[node]]++;
        sons[asso][up[node]]++;

        if (up[node] == 0)
            ans++;
        if (down[node] == 0)
            ans++;
    }

    for (auto to : list[node]) {
        if (us[to.first] || to.first == dad) continue;

        if (dad == 0)
            sons[++maps_set].clear();

        down[to.first] = (down[node] * 10 + to.second) % M;
        up[to.first] = (up[node] + pow_ten[lvl] * to.second) % M;

        compute(to.first, node, lvl + 1, (dad == 0 ? maps_set : asso));
    }
}

void add_composed(int node, int dad, int lvl) {

    if (dad != 0) {
        ll need = (M - down[node]) * poww(inv_ten, lvl);
        need %= M;

        ans += 1LL * full[need];
        ans -= 1LL * sons[last_asso[node]][need];
    }

    for (auto to : list[node]) {
        if (us[to.first] || to.first == dad) continue;

        add_composed(to.first, node, lvl + 1);
    }
}

void solve(int node) {
    dfs_cnt(node, 0);
    target = cnt[node];

    node = find_centroid(node, 0);

    down[node] = up[node] = maps_set = 0;
    full.clear();

    compute(node, 0, 0, 0);
    add_composed(node, 0, 0);

    us[node] = true;
    for (auto to : list[node])
        if (!us[to.first])
            solve(to.first);
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &M);
    for (i = 1; i < n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        x++; y++;

        list[x].pb(mp(y, z));
        list[y].pb(mp(x, z));
    }

    compute_inverse();
    solve(1);


    printf("%lld", ans);

    return 0;
}