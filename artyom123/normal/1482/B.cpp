#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double
#define mp make_pair
#define pii pair<long long, long long>

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

vector<ll> find_dists(int n, vector<pair<pii, int>> e, int s) {
    vector<vector<pii>> g(n);
    for (auto &c : e) {
        int w = c.se;
        g[c.fi.fi].pb(c.fi.se, w);
        g[c.fi.se].pb(c.fi.fi, w);
    }
    vector<ll> dist(n, INFLL);
    dist[s] = 0;
    set<pair<ll, int>> q;
    q.insert({0LL, s});
    while (q.size()) {
        int v = q.begin()->se;
        q.erase(q.begin());
        for (auto &to : g[v]) {
            if (dist[to.fi] > dist[v] + to.se) {
                q.erase({dist[to.fi], to.fi});
                dist[to.fi] = dist[v] + to.se;
                q.insert({dist[to.fi], to.fi});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, L, s, t;
    cin >> n >> m >> L >> s >> t;
    vector<pair<pii, int>> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].fi.fi >> e[i].fi.se >> e[i].se;
    }
    vector<pair<pii, int>> e1 = e;
    for (auto &c : e1) {
        if (c.se == 0) c.se = 1;
    }
    ll left = 1, right = 1e9 + 1;
    if (find_dists(n, e1, s)[t] > L) {
        cout << "NO";
        return 0;
    }
    e1 = e;
    for (auto &c : e1) {
        if (c.se == 0) c.se = right;
    }
    if (find_dists(n, e1, s)[t] < L) {
        cout << "NO";
        return 0;
    }
    if (find_dists(n, e1, s)[t] == L) {
        cout << "YES\n";
        for (auto &c : e1) {
            cout << c.fi.fi << " " << c.fi.se << " " << c.se << "\n";
        }
        return 0;
    }
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        vector<pair<pii, int>> e1 = e;
        for (auto &c : e1) {
            if (c.se == 0) c.se = mid;
        }
        if (find_dists(n, e1, s)[t] <= L) left = mid;
        else right = mid;
    }
    int x = left;
    left = -1;
    right = m;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        vector<pair<pii, int>> e1 = e;
        for (int i = 0; i < mid; i++) {
            if (e1[i].se == 0) e1[i].se = x + 1;
        }
        for (int i = mid; i < m; i++) {
            if (e1[i].se == 0) e1[i].se = x;
        }
        ll now = find_dists(n, e1, s)[t];
        if (now == L) {
            cout << "YES\n";
                for (auto &c : e1) {
                cout << c.fi.fi << " " << c.fi.se << " " << c.se << "\n";
            }
            return 0;
        }
        if (now < L) left = mid;
        else right = mid;
    }
    return 0;
}