#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

stack <int> l;
bitset <N> vis;
int n, p[N], size[N], comp[N], cur = 0;
vector <int> q[N];

long long bigMod (long long a, int e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

void dfsUp (int u) {
    vis[u] = 1;
    if (!vis[p[u]]) dfsUp(p[u]);
    l.push(u);
}

void dfsDown (int u) {
    comp[u] = cur, ++size[cur];
    for (int v : q[u]) if (comp[v] == -1) dfsDown(v);
}

int main (int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", p + i), q[p[i]].push_back(i);

    memset(comp, -1, sizeof comp);
    for (int i = 1; i <= n; ++i) if (!vis[i]) dfsUp(i);
    while (!l.empty()) {
        int u = l.top(); l.pop();
        if (comp[u] == -1) ++cur, dfsDown(u);
    }

    int unused = 0;
    long long ans = 1LL;
    for (int i = 1; i <= cur; ++i) {
        if (size[i] > 1) ans *= (bigMod(2LL, size[i]) - 2LL);
        else ++unused;
        ans %= MOD;
    }
    ans *= bigMod(2LL, unused), ans %= MOD, ans += MOD, ans %= MOD;

    printf("%lld\n", ans);
    return 0;
}