#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int N = (int) 2e5 + 7;
int m;
vector <int> g[N];
int sz[N];
int a[N];
int d = 0;
int root;

int dfs(int v, int pr) {
    sz[v] = 1;
    int m1 = 0, m2 = 0, res = 1;
    for (auto to : g[v]) {
        if (to == pr) continue;
        int f = dfs(to, v);
        sz[v] += sz[to];
        if (f == sz[to]) {
            res += f;
        } else if (f > m1) {
            m2 = m1;
            m1 = f;
        } else if (f > m2) {
            m2 = f;
        }
    }
    if (a[v] < m) return 0;
    d = max(d, res + m1 + m2);
    return res + m1;
}

int check() {
    d = 0;
    dfs(root, -1);
    return d;
}


int main() {
    int n, k, u, v;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i + 1 < n; i++) {
        scanf("%d%d", &u, &v);
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    root = min_element(a, a + n) - a;
    int l = 0, r = (int) 1e6 + 7;
    while (l < r - 1) {
        m = (l + r) / 2;
        if (check() >= k) {
            l = m;
        } else {
            r = m;
        }
    }
    printf("%d\n", l);
}