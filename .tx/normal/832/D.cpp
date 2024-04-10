#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

const int N = 111111;

int h[N];
int tin[N];
int tout[N];
int up[N][22];
vector<int> g[N];

bool is_anc(int anc, int child) {
    return tin[anc] <= tin[child] && tout[anc] >= tout[child];
}

int tmr = 1;

void init(int v, int p, int ch) {
    tin[v] = tmr++;
    h[v] = ch;
    int op = p;
    for (int i = 0; p != -1; i++) {
        up[v][i] = p;
        p = up[p][i];
    }
    p = op;

    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        init(i, v, ch + 1);
    }

    tout[v] = tmr++;
}

int lca(int a, int b) {
    if (is_anc(a, b)) {
        return a;
    }
    if (is_anc(b, a)) {
        return b;
    }

    for (int i = 21; i >= 0; i--) {
        int x = up[a][i];
        if (x != -1 && !is_anc(x, b)) {
            a = x;
        }
    }

    return up[a][0];
}

int get(int s, int f, int t) {
    if (is_anc(f, s) && is_anc(f, t)) {
        return h[lca(s, t)] - h[f] + 1;
    }

    if (is_anc(f, s) || is_anc(f, t)) {
        return 0;
    }

    if (is_anc(s, f) && is_anc(t, f)) {
        if (is_anc(s, t)) {
            return h[f] - h[t] + 1;
        }
        return h[f] - h[s] + 1;
    }

    if (is_anc(s, f)) {
        return h[f] - max(h[s], h[lca(f, t)]) + 1;
    }
    if (is_anc(t, f)) {
        return h[f] - max(h[t], h[lca(f, s)]) + 1;
    }

    int a = lca(s, f);
    int b = lca(t, f);
    int c = lca(s, t);
    if (h[c] > h[a]) {
        return h[c] - h[a] + 1 + h[f] - h[a];
    }
    return h[f] - max(h[a], h[b]) + 1;
}

void solve(istream& cin, ostream& cout) {
    memset(up, -1, sizeof(int) * 22 * N);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        --x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    init(0, -1, 0);
    rep(i, 0, q) {
        int a[3];
        rep(x, 0, 3) {
            cin >> a[x];
            --a[x];
        }
        sort(a, a + 3);
        int ans = 0;
        do {
            ans = max(ans, get(a[0], a[1], a[2]));
        } while (next_permutation(a, a + 3));
        cout << ans << "\n";
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//pspnnq