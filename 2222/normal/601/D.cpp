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

int n;
char s[300300];
vector<int> adj[300300];
ll dif[300300];
unordered_map<ll, int> F;

int code(unsigned h, char c) {
    ll p = h * 65536ull + c;
    auto i = F.find(p);
    if (i != F.end())
        return i->second;
    int k = sz(F);
    F[p] = k;
    return k;
}

unordered_set<int> dfs(int x, int prev, int h) {
    h = code(h, s[x]);
    unordered_set<int> res{h};
    for (int y : adj[x]) {
        if (y == prev) continue;
        unordered_set<int> t = dfs(y, x, h);
        if (sz(t) > sz(res))
            res.swap(t);
        for (int u : t)
            res.insert(u);
    }
    dif[x] += sz(res);
    return res;
}

int main() {
    scanf("%d", &n);
    REP (i, n) {
        int c;
        scanf("%d", &c);
        dif[i] = c;
    }
    scanf("%s", s);
    FOR (k, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x, --y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    F[0] = 0;
    dfs(0, -1, 0);
    auto v = *max_element(dif, dif + n);
    cout << v << endl;
    cout << count(dif, dif + n, v) << endl;
    return 0;
}