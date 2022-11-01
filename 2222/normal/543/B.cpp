#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define long int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<int> adj[3333];
int f[3333][3333];

void bfs(int x, int dist[]) {
    fill(dist, dist + n, 1000000);
    dist[x] = 0;
    queue<int> q;
    q.push(x);
    for (; sz(q); ) {
        x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (dist[x] + 1 < dist[y]) {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP (i, m) {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x - 1].pb(y - 1);
        adj[y - 1].pb(x - 1);
    }
    REP (x, n) bfs(x, f[x]);
    int s1, t1, l1, s2, t2, l2;
    scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
    --s1, --t1, --s2, --t2;
    int res = -1;
    if (f[s1][t1] <= l1 && f[s2][t2] <= l2) {
        res = max(res, m - f[s1][t1] - f[s2][t2]);
    }
    REP (x, n) REP (y, n) {
        assert(f[x][y] == f[y][x]);
        int d1 = min(f[s1][x] + f[y][t1], f[s1][y] + f[x][t1]) + f[x][y];
        int d2 = min(f[s2][x] + f[y][t2], f[s2][y] + f[x][t2]) + f[x][y];
        if (d1 <= l1 && d2 <= l2) {
            res = max(res, m - (d1 + d2 - f[x][y]));
        }
    }
    cout << res << endl;
    return 0;
}