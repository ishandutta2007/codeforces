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

struct q {
    int type, i, j;
    q() {};
    q(int a, int b, int c) {
        type = a;
        i = b;
        j = c;
    }
};

const int MAXN = (int) 1e5 + 7;
const int MAXK = (int) 1e3 + 7;
vector <pair <int, q> > g[MAXN];
bitset <MAXK> p[MAXK];
int ans[MAXN];
int cnt = 0;
int m;

void dfs(int v) {
    ans[v] = cnt;
    for (auto to : g[v]) {
        if (to.sc.type == 1) {
            bool was = p[to.sc.i][to.sc.j];
            cnt -= was;
            p[to.sc.i][to.sc.j] = 1;
            cnt++;
            dfs(to.fc);
            cnt -= 1;
            cnt += was;
            p[to.sc.i][to.sc.j] = was;
        } else if (to.sc.type == 2) {
            bool was = p[to.sc.i][to.sc.j];
            cnt -= was;
            p[to.sc.i][to.sc.j] = 0;
            cnt += 0;
            dfs(to.fc);
            p[to.sc.i][to.sc.j] = was;
            cnt += was;
        } else if (to.sc.type == 3) {
            int was = p[to.sc.i].count() - p[to.sc.i][m] * (MAXK - m);
            cnt -= was;
            p[to.sc.i] = ~p[to.sc.i];   
            int now = p[to.sc.i].count() - p[to.sc.i][m] * (MAXK - m);
            cnt += now;
            dfs(to.fc);
            cnt -= now;
            cnt += was;
            p[to.sc.i] = ~p[to.sc.i];
        } else {
            dfs(to.fc);
        }
    }
}

int main() {
    int n, q;
    scanf("%d%d%d", &n, &m, &q);
    int cur = 0;
    for (int i = 1; i <= q; i++) {
        int c;
        scanf("%d", &c);
        if (c == 1) {
            int a, b;
            scanf("%d%d", &a, &b);
            b--;
            g[cur].pb({i, {1, a, b}});
            cur = i;
        } else if (c == 2) {
            int a, b;
            scanf("%d%d", &a, &b);
            b--;
            g[cur].pb({i, {2, a, b}});
            cur = i;
        } else if (c == 4) {
            scanf("%d", &cur);
            g[cur].pb({i, {4, -1, -1}});
            cur = i;
        } else {
            int a;
            scanf("%d", &a);
            g[cur].pb({i, {3, a, -1}});
            cur = i;
        }
    }
    dfs(0);
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]); 
    }
}