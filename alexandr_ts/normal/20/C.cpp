#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 1;
const ll INF = 2e12 + 1;
const ld EPS = 1e-9;

vector <pair <int, int> > g[N];

ll dist[N];
int v[N], u[N], c[N], prv[N];
bool used[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fill(dist, dist + n, INF);
    dist[0] = 0;
    fr(i, m) {
        cin >> v[i] >> u[i] >> c[i];
        g[--v[i]].pb(mp(--u[i], c[i]));
        g[u[i]].pb(mp(v[i], c[i]));
    }

    set <pair <ll, int> > edges;

    edges.insert(mp(0, 0));
    frab(i, 1, n)
        edges.insert(mp(INF, i));

    while (!edges.empty()) {
        //cout << edges.size() << endl;
        auto t = *edges.begin();
        int v = t.second;
        edges.erase(edges.begin());
        for (auto it: g[v]) {
            if (dist[it.first] > dist[v] + it.second) {
                edges.erase(edges.find(mp(dist[it.first], it.first)));
                edges.insert(mp(dist[v] + it.second, it.first));
                dist[it.first] = dist[v] + it.second;
                prv[it.first] = v;
            }
        }
    }
    if (dist[n - 1] == INF) {
        cout << -1;
        return 0;
    }
    int cur = n - 1;
    vector <int> ans;
    while (cur) {
        ans.pb(cur);
        cur = prv[cur];
    }
    ans.pb(0);
    reverse(ans.begin(), ans.end());
    fr(i, ans.size())
        cout << ans[i] + 1 << " ";
}