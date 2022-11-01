#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld PI = acos(-1);
const ll MAX = 1e6 + 10;
const ll INF = 1e9 + 10;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 5e3 + 10;

int dist[N][N];
vector <int> g[N];

struct shop {
    ll city, cnt, cost;
} a[N];

bool cmpCost(shop a, shop b) {
    return a.cost < b.cost;
}

void distPrecalc(int n) {
    fr(i, n) {
        fill(dist[i], dist[i] + n, INF);
        dist[i][i] = 0;
        queue <int> q;
        q.push(i);
        while (q.size()) {
            int v = q.front();
            q.pop();
            for (auto t: g[v])
                if (dist[i][t] == INF) {
                    dist[i][t] = dist[i][v] + 1;
                    q.push(t);
                }
        }
    }
}

vector <int> shops[N];

bool check(int city, ll cnt, ll cost, int d) {
    vector <int> sh;
    for (auto t: shops[city])
        if (dist[city][a[t].city] <= d)
            sh.pb(t);
    ll curcost = 0;
    fr(i, sh.size()) {
        if (a[sh[i]].cnt >= cnt) {
            curcost += cnt * a[sh[i]].cost;
            cnt = 0;
            break;
        }
        else {
            curcost += a[sh[i]].cnt * a[sh[i]].cost;
            cnt -= a[sh[i]].cnt;
        }
    }
    if (cnt || curcost > cost)
        return false;
    return true;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fr(i, m) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }

    int w;
    cin >> w;
    fr(i, w) {
        cin >> a[i].city >> a[i].cnt >> a[i].cost;
        a[i].city--;
    }
    sort(a, a + w, cmpCost);

    distPrecalc(n);

    fr(i, n)
        fr(j, w)
            if (dist[i][a[j].city] != INF)
                shops[i].pb(j);

    int q;
    cin >> q;
    fr(i, q) {
        ll city, cnt, cost;
        cin >> city >> cnt >> cost;
        city--;
        int tl = -1, tr = n; /// check
        while (tr - tl > 1) {
            int tm = (tl + tr) / 2;
            bool ok = check(city, cnt, cost, tm);
            if (ok)
                tr = tm;
            else
                tl = tm;
        }
        bool ok = check(city, cnt, cost, tr);
        if (!ok)
            cout << -1 << endl;
        else
            cout << tr << endl;
    }
}