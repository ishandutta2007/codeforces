#include <bits/stdc++.h>

#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (decltype(a) i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first

using namespace std;


int n, m, have, need;

int a[100500];

vector<int> adj[100500];
vector<int> z[100500];

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    cin >> n >> m >> have >> need;
    REP (i, n) { cin >> a[i]; --a[i]; }
    REP (i, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    REP (k, have) {
        vector<bool> u(n);
        vector<int> dist(n, -1);
        queue<int> q;
        REP (i, n) if (a[i] == k) {
            u[i] = true;
            dist[i] = 0;
            q.push(i);
        }
        for (; sz(q); ) {
            int x = q.front(); q.pop();
            for (int y : adj[x]) {
                if (u[y]) continue;
                u[y] = true;
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
        REP (i, n) z[i].pb(dist[i]);
    }
    REP (i, n) {
        if (i) cout << ' ';
        nth_element(z[i].begin(), z[i].begin() + need, z[i].end());
        cout << accumulate(z[i].begin(), z[i].begin() + need, 0ll);
    }
    cout << endl;
    return 0;
}