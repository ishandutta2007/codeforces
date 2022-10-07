#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 1e5 + 10;
const int inf = 1e9;

vector < pair < int, int > > b;
vector < int > e[maxn];
int a[maxn];
int p[maxn];
int cnt[maxn];

int getId(int v) {
    return (p[v] == v)? v: p[v] = getId(p[v]);
}

void merge(int v, int u) {
    cnt[v] += cnt[u];
    p[u] = v;
}

bool cmp(pair < int, int > c, pair < int, int > d) {
    return c.fr > d.fr;
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, m, v, u, vv, uu;
    long long ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
       scanf("%d", &a[i]); 
       b.pb(mp(a[i], i));
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    sort(b.begin(), b.end(), cmp);
    for (int i = 0; i < n; i++) {
        p[i] = i;
        cnt[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        v = b[i].sc;
        for (int j = 0; j < (int)e[v].size(); j++) {
            u = e[v][j];
            if (a[u] < a[v]) continue;
            uu = getId(u);
            vv = getId(v); 
            if (vv == uu) continue;
            ans += cnt[vv] * 1ll * cnt[uu] * a[v] * 2;
            merge(vv, uu);
        }
    }
    printf("%.15lf\n", ans * 1.0 / (n * 1ll * (n - 1)));

    return 0;
}