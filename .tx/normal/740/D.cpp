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

lint h[222222];
int a[222222];

vector<pair<int, int> > g[222222];
int ans[222222];
int cur = 0;
int x[222222];

int dfs(int v, int p, lint ch, vector<int>& is) {
    h[v] = ch;
    is.push_back(v);
    int l = -1, r = int(is.size()) - 1;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        lint d = ch - h[is[m]];
        if (d <= a[v]) {
            r = m;
        } else {
            l = m;
        }
    }
    x[is[r]]--;
    int add = 0;
    for (auto& i : g[v]) {
        if (i.first != p) {
            add += dfs(i.first, v, ch + i.second, is);
        }
    }
    is.pop_back();
    ans[v] = add;
    return add + 1 + x[v];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }

    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x;
        g[x].push_back({i, y});
        g[i].push_back({x, y});
    }


    vector<int> t;
    dfs(0, -1, 0, t);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }



    return 0;
}