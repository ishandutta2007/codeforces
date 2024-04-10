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
const int N = 11;
const int K = 1e3 + 10; 
const int INF = 1e9;

struct edge {
    int v, u, c;
    edge() { }
    edge(int v, int u, int c): v(v), u(u), c(c) { }
};
char a[K][N][N];
edge b[K * K / 2];
int p[K];
vector < int > e[K];
bool use[K];

int getId(int v) {
    return (p[v] == v)? v: p[v] = getId(p[v]);
}

void merge(int v, int u) {
    v = getId(v);
    u = getId(u);
    p[v] = u;
}

bool cmp(edge a, edge b) {
    return a.c < b.c;
}

void dfs(int v) {
    use[v] = 1;
    for (int i = 0; i < (int)e[v].size(); i++) {
        if (!use[e[v][i]]) {
            printf("%d %d\n", e[v][i] + 1, v + 1);
            dfs(e[v][i]);
        } 
    }
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, m, k, w;
    scanf("%d%d%d%d\n", &n, &m, &k, &w);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            scanf("%s", a[i][j]);
    int cur = 0;
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k; j++) {
            int cnt = 0;
            for (int ii = 0; ii < n; ii++)
                for (int jj = 0; jj < m; jj++)
                    cnt += a[i][ii][jj] != a[j][ii][jj];
            //cerr << "i j cnt: " << i << " " << j << " " << cnt << endl;
            if (cnt * w < n * m)
                b[cur++] = edge(i, j, cnt * w);
        }
    sort(b, b + cur, cmp);
    for (int i = 0; i < k; i++)
        p[i] = i;
    int ans = n * m * k;
    for (int i = 0; i < cur; i++) {
        int v = b[i].v;
        int u = b[i].u;
        if (getId(v) != getId(u)) {
            //cerr << "sdfsdf\n";
            e[v].pb(u);
            e[u].pb(v);
            //cerr << b[i].c << endl;
            ans += b[i].c;
            ans -= n * m;
            merge(v, u);
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < k; i++) 
        if (!use[i]) {
            printf("%d 0\n", i + 1);
            dfs(i);
        }
    return 0;
}