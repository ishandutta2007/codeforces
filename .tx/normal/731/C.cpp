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

int c[222222];
int cc[222222];

vector<int> g[222222];

map<int, int> mm;
int dfs(int v) {
    cc[v] = 1;
    mm[c[v]]++;
    int res = 1;
    for (int i : g[v]) {
        if (cc[i] == 0) {
            res += dfs(i);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m, k);
    for (int i = 0; i < n; i++) {
        sci(c[i]);
    }

    for (int i = 0; i < m; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }


    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (cc[i] == 0) {
            mm.clear();
            int r = dfs(i);
            int mx = 0;
            for (auto& p : mm) {
                mx = max(mx, p.second);
            }
            ans += r - mx;
        }
    }
    cout << ans;

    return 0;
}