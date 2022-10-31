#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld lond double
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

const int maxn = 300005;
ll dist[maxn];
ll cost[maxn];
const ll inf = 1e17;
vector<pair<int, int>> g[maxn];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        g[u].pb(mp(v, i));
        g[v].pb(mp(u, i));
        cost[i] = c;
    }

    int s;
    cin >> s;

    for (int i = 1; i <= n; i++)
        dist[i] = inf;

    priority_queue<pair<ll, int>> q;
    q.push(mp(0, s));
    dist[s] = 0;

    while (!q.empty()) {
        int v = q.top().snd;
        ll cd = -q.top().fst;
        q.pop();

        if (cd != dist[v]) {
            continue;
        }

        for (auto to : g[v]) {
            ll nd = cd + cost[to.snd];
            if (dist[to.fst] > nd) {
                dist[to.fst] = nd;
                q.push(mp(-nd, to.fst));
            }
        }
    }

    vector<int> ans;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == inf || i == s) {
            continue;
        }

        pair<ll, int> best(inf, -1);
        for (auto to : g[i]) {
            if (dist[to.fst] + cost[to.snd] == dist[i]) {
                best = min(best, mp(cost[to.snd], to.snd));
            }
        }

        sum += best.fst;
        ans.pb(best.snd);
    }

    cout << sum << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}