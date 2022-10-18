#include <bits/stdc++.h>

using namespace std;

int const maxn = 1e6 + 5;
int g[maxn];
vector < int > f[maxn];
int used[maxn];
int a[maxn];
int ans[maxn];
int gett[maxn];
int d[maxn];
vector < int > t;

void dfs(int v) {
    t.push_back(v);
    used[v] = 1;
    if (used[g[v]] == 0) dfs(g[v]);
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) g[i] = a[i];
    int bal = 0;
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            t = {};
            dfs(i);
            int x = (int)t.size(), numb = 0;
            if ((int)t.size() % 2 == 1) {
                for (int j = 0; j < x; ++j) {
                    gett[numb] = t[j];
                    numb = (numb + 2);
                    if (numb >= x) numb -= x;
                }
                numb = 0;
                for (int j = 0; j < x; ++j) {
                    ans[t[j]] = gett[(numb + 1) % x];
                    numb = (numb + 2);
                    if (numb >= x) numb -= x;
                }
            }
            else {
                if ((int)f[x].size() == 0) {
                    bal++;
                    f[x] = t;
                }
                else {
                    bal--;
                    int ptr = 0;
                    for (int j = 0; j < x; ++j) {
                        d[ptr++] = t[j];
                        d[ptr++] = f[x][j];
                    }
                    for (int j = 0; j < 2 * x; ++j) {
                        int nxt = j + 1;
                        if (nxt == 2 * x) nxt = 0;
                        ans[d[j]] = d[nxt];
                    }
                    f[x] = {};
                }
            }
        }
    }
    if (bal != 0) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    return 0;
}