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

#define maxN 30024
#define inf (1LL << 60)

int n, m, i, x, y, S, D;
vector< pair<int, int> > list[maxN];
int w[maxN];

int deny_edge;
bool us[maxN];
vector<int> way;
vector<int> St;

bool is_bridge[maxN];
bool us_edge[maxN];
int lvl[maxN];
int low[maxN];

vector<int> candidate;
ll ans;
vector<int> ans_edge;


void dfs_way(int node) {
    if (way.size() > 0) return;
    us[node] = true;

    if (node == D) {
        way = St;
        return;
    }

    for (auto to : list[node]) {
        if (deny_edge == to.second || us[to.first]) continue;

        St.pb(to.second);
        dfs_way(to.first);
        St.pop_back();
    }
}

void get_way(int _deny) {
    deny_edge = _deny;

    way.clear();
    St.clear();
    memset(us, 0, sizeof(us));

    dfs_way(S);
}

void dfs(int node) {
    us[node] = true;

    low[node] = lvl[node];
    for (auto to : list[node]) {
        if (us_edge[to.second]) continue;
        us_edge[to.second] = true;

        if (us[to.first]) {
            low[node] = min(low[node], lvl[to.first]);
        } else {
            lvl[to.first] = lvl[node] + 1;
            dfs(to.first);
            low[node] = min(low[node], low[to.first]);

            if (low[to.first] == lvl[to.first])
                is_bridge[to.second] = true;
        }
    }
}

pair<ll, int> get_bridge(int _deny) {
    int i;
    pair<ll, int> ans = mp(inf, 0);

    memset(us, 0, sizeof(us));
    memset(us_edge, 0, sizeof(us_edge));
    memset(lvl, 0, sizeof(lvl));
    memset(low, 0, sizeof(low));
    memset(is_bridge, 0, sizeof(is_bridge));

    us_edge[_deny] = true;
    dfs(S);

    get_way(_deny);
    for (auto e : way)
        if (is_bridge[e])
            ans = min(ans, mp(1LL * w[e], e));

    return ans;
}



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d%d", &n, &m, &S, &D);
    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &w[i]);
        list[x].pb(mp(y, i));
        list[y].pb(mp(x, i));
    }

    get_way(-1);
    candidate = way;

    if (candidate.empty()) {
        printf("0\n0");
        return 0;
    }

    ans = inf;
    ans_edge.empty();

    // only one bridge
    auto aux = get_bridge(-1);
    if (aux.first < ans) {
        ans = aux.first;
        ans_edge = {aux.second};
    }

    // two bridges
    for (auto act : candidate) {
        aux = get_bridge(act);
        if (aux.first + w[act] < ans) {
            ans = aux.first + w[act];
            ans_edge = {aux.second, act};
        }
    }

    if (ans >= inf) {
        printf("-1");
        return 0;
    }

    printf("%lld\n", ans);
    printf("%d\n", ans_edge.size());
    for (auto e : ans_edge)
        printf("%d ", e);

    return 0;
}