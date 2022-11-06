#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
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

typedef long long lint;

vector<int> g[222222];
bool del[222222];

bool a[222222];

int ce = 0;

bool dfs(int v, int p) {
    bool res = a[v];
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        if (!dfs(i, v)) {
            del[i] = true;
        } else {
            ce++;
            res = true;
        }
    }
    return res;
}

int dist[222222];

void filld(int v, int p, int cd) {
    dist[v] = cd;
    for (int i : g[v]) {
        if (i != p && !del[i]) {
            filld(i, v, cd + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int some = -1;
    for (int i = 0; i < m; i++) {
        sci(some);
        --some;
        a[some] = true;
    }

    dfs(some, -1);

    filld(some, -1, 0);

    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (!del[i] && dist[i] >= dist[mx]) {
            mx = i;
        }
    }

    memset(dist, -1, sizeof(dist));
    filld(mx, -1, 0);

    int diam = *max_element(dist, dist + n);
    int last = max_element(dist, dist + n) - dist;
    vector<int> xs;
    for (int i = 0; i <= diam; i++) {
        if (diam % 2 == 0) {
            if (i == diam / 2) {
                xs.push_back(last);
            }
        } else {
            if (i == diam / 2 || i == (diam + 1) / 2) {
                xs.push_back(last);
            }
        }
        for (int to : g[last]) {
            if (!del[to] && dist[to] + 1 == dist[last]) {
                last = to;
                break;
            }
        }
    }

    int ans = 1e9;
    for (int i : xs) {
        memset(dist, -1, sizeof(dist));
        filld(i, -1, 0);
        for (int j = 0; j < n; j++) {
            if (dist[j] == (diam + 1) / 2) {
                ans = min(ans, j);
            }
        }
    }

    cout << ans + 1 << "\n" << 2 * ce - diam;



    return 0;
}