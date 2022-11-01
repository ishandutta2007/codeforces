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

int n;
vector<int> adj[200500];

struct answer_t { int max, min, leafs; };

answer_t dfs_max(int x) {
    int leafs = 0;
    int nmin = 0, nmax = -1u/2;
    for (int y : adj[x]) {
        auto t = dfs_max(y);
        nmax = min(nmax, t.min);
        nmin += t.max;
        leafs += t.leafs;
    }
    if (leafs == 0)
        return {0, 0, 1};
    return {leafs - 1 - nmax, leafs - 1 - nmin, leafs};
}

int main() {
    scanf("%d", &n);
    FOR (i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x - 1].pb(y - 1);
    }
    auto res = dfs_max(0);
    printf("%d %d\n", res.max + 1, res.min + 1);
    return 0;
}