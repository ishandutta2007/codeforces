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

lint d[5555][5555];

vector<pair<int, int> > g[5555];
bool used[5555];
int n;

void go(int v) {
    if (used[v])
        return;
    used[v] = true;
    for (auto e : g[v]) {
        int to = e.first;
        int c = e.second;
        go(to);
        for (int i = 1; i <= n; i++) {
            d[v][i] = min(d[v][i], d[to][i - 1] + c);
        }
    }
}

void print_ans(int v, int c) {
    cout << v + 1 << " ";
    if (v == n - 1) {
        return;
    }
    for (auto i : g[v]) {
        if (d[v][c] == d[i.first][c - 1] + i.second) {
            print_ans(i.first, c - 1);
            return;
        }
    }
    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    sci(n);
    scid(m, T);
    for (int i = 0; i < m; i++) {
        scid(x, y, z);
        --x; --y;
        g[x].push_back({y, z});
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] = 1e18;
        }
    }
    d[n - 1][1] = 0;
    used[n - 1] = true;

    go(0);

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[0][i] <= T) {
            ans = i;
        }
    }

    cout << ans << "\n";
    print_ans(0, ans);




    return 0;
}