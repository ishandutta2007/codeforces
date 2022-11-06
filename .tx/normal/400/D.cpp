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

int c[555];

vector<int> g[111111];
int tp[111111];

lint d[555][555];

bool used[111111];
vector<int> vis_tp;
int cnt_tp[555];

void dfs(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    int tv = tp[v];
    if (cnt_tp[tv] == 0) {
        vis_tp.push_back(tv);
    }
    cnt_tp[tv]++;

    for (int i : g[v]) {
        dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m, k);
    int lst = 0;
    for (int i = 0; i < k; i++) {
        sci(c[i]);
        for (int j = 0; j < c[i]; j++) {
            tp[lst++] = i;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (i != j) {
                d[i][j] = (lint) 1e18;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        scid(x, y, z);
        --x; --y;
        if (z == 0) {
            g[x].push_back(y);
            g[y].push_back(x);
        }
        x = tp[x];
        y = tp[y];
        d[x][y] = min(d[x][y], 1LL * z);
        d[y][x] = min(d[y][x], 1LL * z);
    }


    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        vis_tp.clear();
        dfs(i);
        for (int j : vis_tp) {
            if (cnt_tp[j] != c[j]) {
                cout << "No";
                return 0;
            }
        }
    }

    for (int t = 0; t < k; t++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                d[i][j] = min(d[i][j], d[i][t] + d[t][j]);
            }
        }
    }

    cout << "Yes\n";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (d[i][j] == 1e18) {
                cout << -1;
            } else {
                cout << d[i][j];
            }
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}