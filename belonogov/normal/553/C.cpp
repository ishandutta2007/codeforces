#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 

#define equal equalll
#define less lesss
const int N = 1e5 + 100;
const int INF = 1e9 + 19;
const int P = 1e9 + 7;

int n, m;
vector < int > e[N];
vector < int > g[N];
vector < int > h[N];
int comp[N];
int use[N];
int answer = 1;

void dfs(int v, int color) {
    comp[v] = color;
    for (auto u: e[v])
        if (comp[u] != color) {
            assert(comp[u] == -1);
            dfs(u, color);
        }
}

void dfs2(int v, int color) {
    use[v] = color;
    for (auto u: h[v]) {
        if (use[u] == 0) 
            dfs2(u, 3 - color);
        else if (use[u] == use[v]) {
            //db2(use[v], use[u]);
            //db2(v, u);
            answer = 0;
        }
    }

}

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u, c;
        scanf("%d%d%d", &v, &u, &c); v--; u--;
        if (c == 1) {
            e[v].pb(u);
            e[u].pb(v);
        }
        else {
            g[v].pb(u);
            g[u].pb(v);
        }
    }
}

void solve() {
    int cur = 0;
    memset(comp, -1, sizeof(comp));
    for (int i = 0; i < n; i++) 
        if (comp[i] == -1) {
            dfs(i, cur); 
            cur++;
        }
    //db(cur);

    //for (int i = 0; i < n; i++)
        //cerr << comp[i] << " ";
    //cerr << endl;

    for (int v = 0; v < n; v++)
        for (auto u: g[v]) {
            if (comp[v] == comp[u]) {
                //db("here");
                answer = 0; 
            }
            h[comp[v]].pb(comp[u]);
            h[comp[u]].pb(comp[v]);
        }
   
    int g = 0;
    for (int i = 0; i < cur; i++)
        if (use[i] == 0) {
            dfs2(i, 1);
            g++;
        }


    //db(g);
    for (int i = 0; i < g - 1; i++)
        answer = (answer * 2) % P;
    cout << answer << endl;


}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
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