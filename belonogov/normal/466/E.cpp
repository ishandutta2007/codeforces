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
const int N = 2e5 + 10;
const int INF = 1e9;

int n, m;
vector < int > e[N];
int b[N];
vector < pair < int, int > > c[N];
int cur = 0;
bool use[N];
int tin[N];
int tout[N];
int tmr;
int answer[N];
int cur2;
int p[N];
//int who[N];
int up[N];


bool isPar(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int getId(int v) {
    return p[v] == v? v: p[v] = getId(p[v]);
}

void merge(int v, int u) {
    v = getId(v);
    u = getId(u);
    p[v] = u; 
}


void read() {
    scanf("%d%d", &n, &m);
}

void dfs(int v) {
    use[v] = 1;
    tin[v] = tmr++;
    for (int u : e[v])
        if (!use[u])
            dfs(u);
    tout[v] = tmr++;
}

void solve() {
    for (int i = 0; i < n; i++)
        p[i] = i;
    cur = 0;
    cur2 = 0;
    int x, y, type;
    for (int i = 0; i < m; i++) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d", &x, &y);
            x--; y--;
            merge(x, y);
            e[y].pb(x);
        }
        if (type == 2) {
            scanf("%d", &x); x--;
            b[cur] = x;
            int v = getId(x);
            up[cur] = v;
            cur++;
        }
        if (type == 3) {
            scanf("%d%d", &x, &y); x--; y--;
            c[y].pb(mp(x, cur2++));
        }
    }
    //cerr << "edge\n";
    //for (int i = 0; i < n; i++) {
        //cerr << i << ": ";
        //for (int u : e[i])
           //cerr << u << " ";
       //cerr << endl; 
    //}
    //for (int i = 0; i < n; i++)
        //cerr << getId(i) << " ";
    //cerr << endl;
    for (int i = 0; i < n; i++)
        if (!use[getId(i)])
            dfs(getId(i));
    for (int i = 0; i < cur; i++) {
        for (auto x : c[i]) {
            //cerr << up[i] << endl;
            answer[x.sc] = isPar(up[i], x.fr) && isPar(x.fr, b[i]);
        }
    }
    //for (int i = 0; i < n; i++)
        //cerr << tin[i] << " " << tout[i] << endl;
}

void printAns() {
    for (int i = 0; i < cur2; i++) {
        if (answer[i])
            printf("YES\n");
        else
            printf("NO\n");
    }
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