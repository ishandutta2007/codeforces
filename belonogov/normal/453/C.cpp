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
const int N = 2e5 + 100;
const int INF = 1e9;

int n, m;
vector < int > e[N];
vector < int > path;
int x[N];
bool flagFail;
bool use[N];


void read() {
    int v, u;
    if (scanf("%d%d", &n, &m) != 2) exit(0);
    for (int i = 0; i < n; i++)
        e[i].clear();
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v, &u);
        v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
}

void dfs(int v) {
    path.pb(v);
    use[v] = 1;
    x[v] ^= 1;
    for (int u: e[v]) {
        if (!use[u]) {
            dfs(u);
            path.pb(v);
            x[v] ^= 1;
            if (x[u] == 1) {
                path.pb(u);
                path.pb(v);
                x[v] ^= 1;
                x[u] ^= 1;
            }
        }        
    }
}

void solve() {
    flagFail = 0;
    memset(use, 0, sizeof(use));
    path.clear();
    int v = -1;
    for (int i = 0; v == -1 && i < n; i++)
        if (x[i]) 
            v = i;
    if (v == -1) return;
    dfs(v);
    if (x[v]) {
        path.pop_back();
        x[v] ^= 1;
    } 
    for (int i = 0; i < n; i++) {
        if (x[i] == 1) {
            flagFail = 1;
            assert(use[i] == 0);
        }
    }
}

void printAns() {
    if (flagFail) {
        printf("-1\n"); 
        return; 
    }
    printf("%d\n", (int)path.size());
    for (int i = 0; i < (int)path.size(); i++)
        printf("%d ", path[i] + 1);
    printf("\n");
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
        }
    }
    else {
        stress();
    }

    return 0;
}