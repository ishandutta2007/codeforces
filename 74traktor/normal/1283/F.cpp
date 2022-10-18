#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn];
vector < int > g[maxn];
int go[maxn], was[maxn];

void dfs(int v) {
    was[v] = 1;
    for (auto u : g[v]) {
        if (was[u] == 0) dfs(u);
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) cin >> a[i];
    vector < pair < int, int > > out;
    set < int > good, used;
    for (int i = 1; i <= n; ++i) good.insert(i);
    int i = 1;
    while (i < n) {
        used.insert(a[i]);
        if (good.find(a[i]) != good.end()) good.erase(a[i]);
        int x = (*good.rbegin());
        good.erase(x);
        i++;
        while (i < n) {
            if (a[i] == x) {
                go[i - 1] = a[i];
                if (good.find(a[i]) != good.end()) good.erase(a[i]);
                break;
            }
            if (used.find(a[i]) != used.end()) {
                go[i - 1] = x;
                used.insert(x);
                break;
            }
            used.insert(a[i]);
            go[i - 1] = a[i];
            if (good.find(a[i]) != good.end()) good.erase(a[i]);
            ++i;
        }
        if (i == n) go[i - 1] = x;
    }
    for (int i = 1; i < n; ++i) g[a[i]].push_back(go[i]);
    dfs(a[1]);
    for (int i = 1; i <= n; ++i) {
        if (was[i] == 0) {
            cout << -1;
            return 0;
        }
    }
    cout << a[1] << '\n';
    for (int i = 1; i < n; ++i) {
        cout << a[i] << " " << go[i] << '\n';
    }
    return 0;
}