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

int n, m;
int ans[200500];
vector<int> vars[200500];
vector<int> f[200500];

int xbs(int x) { return x ^ (x >> 31); }

void stupidVar(int i) {
    assert(sz(vars[i]) <= 2);
    assert(sz(vars[i]) != 2 || (vars[i][0] ^ ~vars[i][1]) != 0);
    if (sz(vars[i]) == 2 && (vars[i][0] ^ vars[i][1]) < 0)
        return;
    if (sz(vars[i]) == 0) {
        if (ans[i] < 0)
            ans[i] = 1;
        return;
    }
    assert(ans[i] < 0 || ans[i] == (vars[i][0] >= 0));
    ans[i] = (vars[i][0] >= 0);
    int ei = xbs(vars[i][0]);
    vector<pii> kicklist;
    for (int j : f[ei]) {
        if (j < 0) {
            kicklist.emplace_back(~j, ~ei);
        } else {
            kicklist.emplace_back(j, ei);
        }
    }
    f[ei].clear();
    for (auto p : kicklist) {
        auto it = find(all(vars[p.X]), p.Y);
        if (it != vars[p.X].end()) {
            swap(*it, vars[p.X].back());
            vars[p.X].pop_back();
            stupidVar(p.X);
        }
    }
}

vector<int> adj[200500];
int rev[200500];
bool u[200500];

bool dfs(int x) {
    u[x] = true;
    for (int y : adj[x]) {
        if (rev[y] < 0 || !u[rev[y]] && dfs(rev[y])) {
            rev[y] = x;
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    REP (i, n) {
        int k;
        scanf("%d", &k);
        f[i].resize(k);
        for (int &v : f[i]) {
            scanf("%d", &v);
            v -= (v > 0);
            if (v < 0)
                vars[~v].pb(~i);
            else
                vars[v].pb(i);
        }
    }
    REP (i, m) ans[i] = -1;
    REP (i, m) {
        if (ans[i] < 0)
            stupidVar(i);
    }
    vector<int> s;
    REP (i, m) {
        if (ans[i] < 0) {
            assert(sz(vars[i]) == 2);
            if (vars[i][0] < 0)
                reverse(all(vars[i]));
            int a = vars[i][0];
            int b = ~vars[i][1];
            assert(a >= 0);
            assert(b >= 0);
            adj[i].reserve(2);
            adj[i].pb(a);
            adj[i].pb(b);
            s.pb(i);
        }
    }
    CL(rev, -1);
    for (; ; ) {
        CL(u, 0);
        bool stop = true;
        for (int k = sz(s); k --> 0; ) {
            if (!u[s[k]] && dfs(s[k])) {
                s[k] = s.back();
                s.pop_back();
                stop = false;
            }
        }
        if (stop) break;
    }
    REP (j, n) {
        if (sz(f[j]) && rev[j] < 0) {
            puts("NO");
            return 0;
        }
        if (rev[j] >= 0) {
            int i = rev[j];
            assert(ans[i] < 0);
            ans[i] = (vars[i][0] == j);
        }
    }
    puts("YES");
    REP (i, m) cout << max(ans[i], 0); cout << endl;
    return 0;
}