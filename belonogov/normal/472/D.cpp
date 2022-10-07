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
#include <unordered_set>
#include <unordered_map>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 2000 + 10;
const int INF = 1e9;

int n;
int a[N][N];
vector < int > e[N];
vector < int > w[N];
set < pair < int, int > > q;
int dist[N];
bool use[N];
int p[N];
bool flag;
int o;

void dfs(int v, int h) {
    use[v] = 1; 
    flag &= a[v][o] == h;
    flag &= a[o][v] == h;
    for (int i = 0; i < (int)e[v].size(); i++)  {
        int u = e[v][i];
        if (!use[u]) {
            dfs(u, h + w[v][i]);
        }
    }
}

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && a[i][j] == 0) {
                printf("NO\n");
                exit(0);
            }

    memset(dist, 63, sizeof(dist));
    memset(p, -1, sizeof(p));
    dist[0] = 1;
    q.insert(mp(0, 0));
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (dist[j] > 0 && (v == -1 || dist[j] < dist[v]))
                v = j;
        assert(v != -1);
        int u = p[v];
        if (u != -1) {

            e[u].pb(v);
            e[v].pb(u);
            w[u].pb(dist[v]);
            w[v].pb(dist[v]);
        }
        for (int j = 0; j < n; j++) 
            if (a[v][j] < dist[j]) {
                dist[j] = a[v][j];
                p[j] = v;
            }
    }
    flag = 1;
    for (int i = 0; i < n; i++) {
        memset(use, 0, sizeof(use));
        o = i;
        dfs(i, 0);
    }
}


void printAns() {
    if (flag)
        printf("YES\n");
    else
        printf("NO\n");
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}