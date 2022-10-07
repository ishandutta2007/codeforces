#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 2e5 + 10;
const int inf = 1e9;

struct edge {
    int x, y, z;
    edge(){}
    edge(int x, int y, int z): x(x), y(y), z(z){}
};

vector < pair < int, int > > e[maxn];
vector < edge > a;
bool use[maxn];
bool useE[maxn];
vector < int > d[maxn];
int n;

bool dfs(int v, int p) {
    use[v] = 1;
    for (int i = 0; i < (int)e[v].size(); i++) {
        if (use[e[v][i].fr] == 0) {
            useE[e[v][i].sc] = 1;
            if (dfs(e[v][i].fr, v)) {
                d[v].pb(e[v][i].fr);
            }
            continue;
        }
        if (useE[e[v][i].sc] == 1)
            continue;
        useE[e[v][i].sc] = 1;
        d[v].pb(e[v][i].fr);
    }
    //cerr << "v sz: " << v << " " << d[v].size() << endl;
    for (int i = 0; i + 2 <= (int)d[v].size(); i += 2)
        a.pb(edge(d[v][i], v, d[v][i + 1]));
    if (d[v].size() % 2 == 0)
        return 1;
    else {
        assert(p != -1);
        a.pb(edge(d[v].back(), v, p));
        return 0;
    }
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int m, x, y;
    scanf("%d%d", &n, &m);
    if (m % 2 == 1) {
        printf("No solution\n");
        return 0;
    }   
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y); x--; y--;
        e[x].pb(mp(y, i));
        e[y].pb(mp(x, i));
    }
    dfs(0, -1);
    //cout << a.size() << endl;
    for (int i = 0; i < (int)a.size(); i++)
        printf("%d %d %d\n", a[i].x + 1, a[i].y + 1, a[i].z + 1);

    return 0;
}