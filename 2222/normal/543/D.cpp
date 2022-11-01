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

const int mod = 1000000007;

int add(int x, int y) { return (x += y) < mod ? x : x - mod; }

int mul(int x, int y) { return (long)x * y % mod; }

int n;
vector<int> adj[200500];
int ans[200500];
int F[200500];

int f(int x) {
    int &res = F[x];
    if (res < 0) {
        res = 1;
        for (int y : adj[x]) {
            res = mul(res, add(f(y), 1));
        }
    }
    return res;
}

void dfs(int x, int g) {
    ans[x] = mul(f(x), add(g, 1));
    vector<int> pre;
    int acc = 1;
    for (int y : adj[x]) {
        pre.push_back(acc);
        acc = mul(acc, add(f(y), 1));
    }
    acc = add(g, 1);
    for (int i = sz(adj[x]); i --> 0; ) {
        int y = adj[x][i];
        dfs(y, mul(acc, pre[i]));
        acc = mul(acc, add(f(y), 1));
    }
}

int main() {
    scanf("%d", &n);
    FOR (y, 1, n) {
        int x;
        scanf("%d", &x);
        adj[x - 1].pb(y);
    }
    CL(F, -1);
    dfs(0, 0);
    REP (i, n) {
        if (i) putchar(' ');
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}