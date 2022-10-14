#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;

int main() {
    /*
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    */
    int n, k;
    cin >> n >> k;
    vector<int> dist(n + 1, INF);
    vector<int> p(n + 1, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (int x = 0; x <= v && x <= k; x++) {
            int y = k - x;
            if (y > n - v) continue;
            int to = v - x + y;
            if (dist[to] == INF) {
                dist[to] = dist[v] + 1;
                p[to] = v;
                q.push(to);
            }
        }
    }
    if (dist[n] == INF) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    vector<vector<int>> a(dist[n]);
    vector<int> path;
    int v = n;
    while (v != -1) {
        path.pb(v);
        v = p[v];
    }
    reverse(all(path));
    vector<int> now0, now1;
    for (int i = 0; i < n; i++) now0.pb(i);
    for (int i = 0; i + 1 < (int)path.size(); i++) {
        int x = path[i], y = path[i + 1];
        int p = 0;
        while (x - p + k - p != y) p++;
        vector<int> now00, now11;
        for (int j = 0; j < p; j++) a[i].pb(now1[j]);
        for (int j = 0; j < k - p; j++) a[i].pb(now0[j]);
        for (int j = 0; j < p; j++) now00.pb(now1[j]);
        for (int j = p; j < (int)now1.size(); j++) now11.pb(now1[j]);
        for (int j = 0; j < k - p; j++) now11.pb(now0[j]);
        for (int j = k - p; j < (int)now0.size(); j++) now00.pb(now0[j]);
        now0 = now00;
        now1 = now11;
    }
    for (auto &c : a) {
        cout << '?' << " ";
        for (auto &l : c) cout << l + 1 << " ";
        cout << endl;
        int x;
        cin >> x;
        ans ^= x;
    }
    cout << '!' << " " << ans << endl;
    return 0;
}