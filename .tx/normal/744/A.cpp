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
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

bool c[1111];
vector<int> g[1111];
int cc[1111];

bool dfs(int v, int cur, int& sz) {
    cc[v] = cur;
    ++sz;
    bool res = c[v];
    for (int i : g[v]) {
        if (cc[i] == 0) {
            res |= dfs(i, cur, sz);
        }
    }
    return res;
}

int sz[1111];
bool a[1111][1111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m, k);
    for (int i = 0; i < k; i++) {
        scid(x);
        c[--x] = true;
    }
    for (int i = 0; i < m; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        a[x][y] = a[y][x] = true;
    }
    
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (cc[i] == 0) {
            int csz = 0;
            bool x = dfs(i, ++cur, csz);
            if (x) {
                sz[cur] = csz; 
            } else {
                sz[cur] = -csz;
            }
        }
    }
    
    int mxi = max_element(sz, sz + cur) - sz;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (a[i][j]) {
                continue;
            }
            if (sz[cc[i]] < 0 && sz[cc[j]] < 0) {
                ans++;
                a[i][j] = a[j][i] = true;
            } else if (sz[cc[i]] < 0 && cc[j] == mxi) {
                ans++;
                a[i][j] = a[j][i] = true;
            } else if (cc[i] == cc[j]) {
                ans++;
                a[i][j] = a[j][i] = true;
            }
        }
    }
    
    cout << ans;

    return 0;
}