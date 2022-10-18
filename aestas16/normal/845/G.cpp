/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

#define ll long long
#define int long long

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e5, M = 1e5, S = 60;

int n, m, val[N + 10];
bool vis[N + 10];

namespace Basis {
    int cnt;
    ll d[S + 10], p[S + 10];
    bool zero;
    bool insert(ll x) {
        for (int i = S; ~i; i--)
            if (x & (1ll << i)) {
                if (p[i] == 0)
                    return p[i] = x, cnt++, 1;
                else
                    x ^= p[i];
            }
        if (x == 0) zero = 1;
        return 0;
    }
    ll maxXor(int ret) {
        for (int i = S; ~i; i--)
            if ((ret ^ p[i]) > ret) ret ^= p[i];
        return ret;
    }
    ll minXor(int ret) {
        for (int i = S; ~i; i--)
            if ((ret ^ p[i]) < ret) ret ^= p[i];
        return ret;
    }
    void rebuild() {
        cnt = 0;
        for (int i = S; ~i; i--)
            for (int j = i - 1; ~j; j--)
                if (p[i] & (1ll << j)) p[i] ^= p[j];
        for (int i = 0; i <= S; i++)
            if (p[i]) d[++cnt] = p[i];
    }
    ll kth(int k) {
        if (zero) k--;
        if (k >= (1ll << cnt)) return -1;
        ll ret = 0;
        for (int i = S; ~i; i--)
            if (k & (1ll << i)) ret ^= p[i];
        return ret;
    }
} // namespace Basis
using namespace Basis;

namespace Edges {
    struct Edge {
        int to, nxt, val;
    } e[(M << 1) + 10];
    int etot, hd[N + 10];
    void adde(int x, int y, int z) { e[++etot] = {y, hd[x], z}, hd[x] = etot; }
} // namespace Edges
using namespace Edges;

void dfs(int u, int p, int Val) {
    vis[u] = 1, val[u] = Val;
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == p) continue;
        if (vis[v])
            insert(val[u] ^ val[v] ^ e[i].val);
        else
            dfs(v, u, val[u] ^ e[i].val);
    }
}

struct OI {
    int RP, score;
} FJOI2021;

signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    fr(n), fr(m);
    for (int i = 1, x, y, z; i <= m; i++) fr(x), fr(y), fr(z), adde(x, y, z), adde(y, x, z);
    return dfs(1, 0, 0), printf("%lld\n", minXor(val[n])), 0;
}