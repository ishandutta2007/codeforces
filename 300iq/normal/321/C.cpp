#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for(int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int MAXN = (int) 1e5 + 7;

vector <int> g[MAXN];
int pr[MAXN];
int h[MAXN];

int dfs(int v, int sz, int &c, int p = -1) {
    int sum = 1;
    for (auto to : g[v]) {
        if (h[to] == -1 && to != p) {
            sum += dfs(to, sz, c, v);
        }
    }
    if (c == -1 && (2 * sum >= sz || p == -1)) {
        c = v;
    }
    return sum;
}

void build(int v, int sz, int last, int len) {
    int c = -1;
    dfs(v, sz, c);
    pr[c] = last;
    h[c] = len;
    for (auto to : g[c]) {
        if (h[to] == -1) {
            build(to, sz >> 1, c, len + 1);
        }
    }
}


int main() {
    memset(h, -1, sizeof h);
    int n, a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a, &b);
        g[a].pb(b), g[b].pb(a);
    }
    build(1, n, -1, 0);
    for (int i = 1; i <= n; i++) {
        printf("%c ", 'A' + h[i]);
    }
}