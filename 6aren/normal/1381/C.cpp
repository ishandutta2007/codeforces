#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 100005;

vector<int> g[N];
int a[N], b[N];

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[a[i]].pb(i);
    }
    vector<int> ok;
    priority_queue<ii> pq;
    for (int i = 1; i <= n + 1; i++) pq.push({g[i].size(), i});
    for (int i = 0; i < x; i++) {
        auto u = pq.top(); pq.pop();
        int id = u.y;
        ok.pb(g[id].back());
        g[id].pop_back();
        pq.push({g[id].size(), id});
    }

    vector<ii> process;
    for (int i = 1; i <= n + 1; i++) {
        process.pb({g[i].size(), i});
    }
    sort(all(process));
    int cnt = 0;
    for (ii e : process) cnt += e.x;
    int t = 2 * process.back().x - cnt;
    y = y - x;
    if (y > cnt - t) {
        cout << "NO\n";
        for (int i = 1; i <= n + 1; i++) g[i].clear();
        return;
    }
    while (t > 0) {
        t--;
        int id = process.back().y;
        g[id].pop_back();
    }
    cout << "YES\n";

    while (!pq.empty()) pq.pop();

    int dem = 0;

    for (int i = 1; i <= n + 1; i++) if (g[i].size()) pq.push({g[i].size(), i}), dem++;

    while (y) {
        if (y == 3 && dem > 2) {
            auto u1 = pq.top(); pq.pop();
            auto u2 = pq.top(); pq.pop();
            auto u3 = pq.top(); pq.pop();
            int id1 = g[u1.y].back();
            int id2 = g[u2.y].back();
            int id3 = g[u3.y].back();
            g[u1.y].pop_back();
            g[u2.y].pop_back();
            g[u3.y].pop_back();
            b[id1] = a[id2];
            b[id2] = a[id3];
            b[id3] = a[id1];
            break;
        }

        if (y == 1) {
            auto u1 = pq.top(); pq.pop();
            auto u2 = pq.top(); pq.pop();
            int id1 = g[u1.y].back();
            int id2 = g[u2.y].back();
            g[u1.y].pop_back();
            g[u2.y].pop_back();
            b[id1] = a[id2];
            break;
        }


        auto u1 = pq.top(); pq.pop();
        auto u2 = pq.top(); pq.pop();
        int id1 = g[u1.y].back();
        int id2 = g[u2.y].back();
        g[u1.y].pop_back();
        g[u2.y].pop_back();
        b[id1] = a[id2];
        b[id2] = a[id1];
        pq.push({g[u1.y].size(), u1.y});
        pq.push({g[u2.y].size(), u2.y});
        y -= 2;
    }

    for (int e : ok) {
        b[e] = a[e];
    }
    vector<int> check(n + 2, 0);
    for (int i = 1; i <= n; i++) check[a[i]] = 1;
    int lost = 0;
    for (int i = 1; i <= n + 1; i++) if (check[i] == 0) lost = i;

    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) b[i] = lost;
        cout << b[i] << ' ';
        b[i] = 0;
    }
    for (int i = 1; i <= n + 1; i++) g[i].clear();
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) solve();
    return 0;
}