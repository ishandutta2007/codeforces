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

int n, m, i, x, y, z, R, p;
vector< pair<int, ll> > list[maxN];
ll dist[maxN], dif;
pair<ll, int> best;

vector< pair<ll, int> > ord;
int l[maxN], r[maxN], cnt;
int aib[maxN];

int zrs(int x) {
    return (x & (x - 1)) ^ x;
}

void add(int x, int v) {
    while (x <= n) {
        aib[x] += v;
        x += zrs(x);
    }
}

int sum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += aib[x];
        x -= zrs(x);
    }
    return ans;
}

void dfs(int node, int root, ll act) {
    dist[node] = max(dist[node], act);
    best = max(best, mp(act, node));

    for (auto to : list[node])
        if (to.first != root)
            dfs(to.first, node, act + to.second);
}

void dfs2(int node, int root) {
    ord.pb(mp(dist[node], node));
    l[node] = ++cnt;

    for (auto to : list[node])
        if (to.first != root)
            dfs2(to.first, node);

    r[node] = cnt;
}

int solve() {
    int i, p;
    int ans = 1;

    memset(aib, 0, sizeof(aib));
    p = 0;

    for (i = 0; i < ord.size(); i++) {
        while (p < ord.size()) {
            if (ord[i].first + dif < ord[p].first) break;
            add(l[ord[p].second], +1);
            p++;
        }

        ans = max(ans, sum(r[ord[i].second]) - sum(l[ord[i].second] - 1));
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        list[x].pb(mp(y, z));
        list[y].pb(mp(x, z));
    }

    best = mp(-1, 0);
    dfs(1, 0, 0);
    R = best.second;

    best = mp(-1, 0);
    dfs(R, 0, 0);
    R = best.second;
    dfs(R, 0, 0);

    for (i = 1; i <= n; i++)
        if (dist[i] < dist[R])
            R = i;

    dfs2(R, 0);
    sort(ord.begin(), ord.end());

    scanf("%d", &m);
    for (i = 1; i <= m; i++) {
        scanf("%lld", &dif);
        printf("%d\n", solve());
    }

    return 0;
}