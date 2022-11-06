#include <bits/stdc++.h>
using namespace std;

typedef long long lint;

template<typename T>
void sci(T& t) {
    cin >> t;
}

void sci(int& t) {
    scanf("%d", &t);
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

vector<int> merge(vector<int>& a, vector<int>& b) {
    vector<int> t;
    int i1 = 0, i2 = 0;
    while (i1 + i2 < 10 && (i1 < a.size() || i2 < b.size())) {
        if (i2 == b.size() || (i1 < a.size() && a[i1] < b[i2])) {
            t.push_back(a[i1++]);
        } else {
            t.push_back(b[i2++]);
        }
    }
    return t;
}

vector<int> empty;

vector<int> g[111111];
vector<int> pp[111111];

int up[111111][22];
vector<int> mins[111111][22];
int tin[111111];
int tout[111111];
int timer = 0;

void dfs(int v, int p) {
    tin[v] = ++timer;
    int op = p;
    if (p != -1) {
        up[v][0] = p;
        mins[v][0] = merge(pp[v], empty);
        for (int i = 1; up[p][i - 1] != -1; i++) {
            up[v][i] = up[p][i - 1];
            mins[v][i] = merge(mins[v][i - 1], mins[p][i - 1]);
            p = up[p][i - 1];
        }
    }

    p = op;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        dfs(i, v);
    }

    tout[v] = ++timer;
}

bool isAncestor(int anc, int v) {
    return tin[anc] <= tin[v] && tout[anc] >= tout[v];
}

int lca(int u, int v) {
    if (isAncestor(u, v)) {
        return u;
    }
    if (isAncestor(v, u)) {
        return v;
    }

    for (int i = 20; i >= 0; i--) {
        int x = up[u][i];
        if (x != -1 && !isAncestor(x, v)) {
            u = x;
        }
    }
    return up[u][0];
}

vector<int> minsOnPath(int u, int anc) {
    if (u == anc) {
        return empty;
    }
    vector<int> res;

    for (int i = 20; i >= 0; i--) {
        int x = up[u][i];
        if (x == -1 || isAncestor(x, anc)) {
            continue;
        }
        res = merge(res, mins[u][i]);
        u = x;
    }

    res = merge(res, mins[u][0]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m, q);
    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 0; i < m; i++) {
        scid(x);
        --x;
        pp[x].push_back(i);
    }


    memset(up, -1, sizeof(int) * 111111 * 22);
    dfs(0, -1);

    while (q-- > 0) {
        scid(v, u, a);
        --v; --u;
        int lc = lca(v, u);
        vector<int> a1 = minsOnPath(v, lc);
        vector<int> a2 = minsOnPath(u, lc);
        vector<int> ans = merge(a1, a2);
        ans = merge(ans, pp[lc]);

        if (ans.size() > a) {
            ans.resize(a);
        }
        cout << ans.size();
        for (int i : ans) {
            cout << " " << i + 1;
        }
        cout << "\n";
    }

    return 0;
}