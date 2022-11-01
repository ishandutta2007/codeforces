#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define ll int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int n, d[100500];
vector<int> adj[100500];

int dfs(int x, int p = -1) {
    if (sz(adj[x]) < 2)
        return 0;
    int k = 0, q = -1;
    for (int y : adj[x]) {
        if (y == p) continue;
        int z = dfs(y, x);
        if (z == 0) ++k;
        if (z > 1) {
            ++d[x];
            ++d[y];
            q = y;
        }
    }
    if (p < 0 && k == 2 && sz(adj[x]) == 3) {
        --d[q];
        return 1;
    }
    return sz(adj[x]) == k + 1 ? k - 1 : 2;
}

int main() {
    scanf("%d", &n);
    REP (i, n - 1) {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x - 1].pb(y - 1);
        adj[y - 1].pb(x - 1);
    }
    REP (i, n) if (sz(adj[i]) > 2) {
        dfs(i);
        break;
    }
    puts(*max_element(d, d + n) < 3 ? "Yes" : "No");
    return 0;
}