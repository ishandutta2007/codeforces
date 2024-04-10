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

#define equal equalll
#define less lesss
const int N = 1e6;
const int INF = 1e9;
const int V = 1e3 + 10;

int n, m;
vector < int > e[N];
int color[N];
bool fail;
int dist[V];
int compColor[N];
queue < int > q;
int answer = 0;
unsigned G[V][V];
vector < int > D;
unsigned use[V];
int sz;


void addE(int v, int u) {
    //cerr << "v u: " << v << " " << u << endl;
    e[v].pb(u);
    //cerr << "v u: " << v << " " << u << " " << (1 << (u & 32)) << endl;
    //cerr << "v u: " << v << " " << u << " " << (1 << (u & 32)) << endl;
    G[v][u / 32] |= (1 << (u & 31));
}

void read() {
    scanf("%d%d", &n, &m);
    sz = (n + 31) / 32;
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        addE(v, u);
        addE(u, v);
    }
    //db(G[0][0]);
    //db(G[1][0]);
    //exit(0);
}

void dfs(int v, int c, int c2) {
    color[v] = c;
    compColor[v] = c2;
    for (auto u: e[v]) {
        if (color[u] == 0)
            dfs(u, 3 - c, c2);
        else {
            if (color[u] != 3 - c)
                fail = 1;
        }
    }
}

void bfs(int S) {
    //db(S);
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    for (int i = 0; i < sz; i++) {
        use[i] = 0; 
    }
    use[S / 32] |= (1 << (S & 31));
    dist[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        //db(v);
        //db(q.size());
        vector < unsigned > tmp(sz);
        //db(use[0]);
        //db(G[v][0]);
        for (int i = 0; i < sz; i++)
            tmp[i] = (~use[i]) & G[v][i];
        //db(sz);
        for (int i = 0; i < sz; i++) {
            if (tmp[i] != 0) {
                //db(tmp[i]);
                for (int j = 0; j < 32; j++)
                   if ((tmp[i] >> j) & 1) {
                       use[i] ^= (1u << j);
                       int u = i * 32 + j;
                       //db(u);
                       dist[u] = dist[v] + 1;
                       q.push(u);
                   }
            }
        }
        //db(q.size());
    }
    //db(dist[0]);
    //db(dist[1]);
    for (int i = 0; i < n; i++)
        if (compColor[S] == compColor[i])
            D[compColor[S]] = max(D[compColor[S]], dist[i]);

}


void solve() {
    fail = 0;
    int cur = 0;
    for (int i = 0; i < n; i++)
        if (color[i] == 0) {
            dfs(i, 1, cur);
            cur++;
        }
    if (fail) {
        printf("-1\n");
        return;
    }
    D.resize(cur);
    for (int i = 0; i < n; i++)
        bfs(i); 
    
    answer = 0;
    for (int i = 0; i < cur; i++)
        answer += D[i];
    printf("%d\n", answer); 

    

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