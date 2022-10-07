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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const int INF = 1e9 + 19;

int n, m;
vector < pair < int, int > > e[N];
int fin[N];
int dist[N];
int par[N];
int dist0[N];
int how[N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u, cost;
        scanf("%d%d%d", &v, &u, &cost);
        e[v].pb(mp(u, cost));
        e[u].pb(mp(v, cost));
    }  
}

void bfs0() {
    queue < int > q;
    memset(dist0, 63, sizeof(dist0)); 
    q.push(n - 1);
    dist0[n - 1] = 0; 
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        fin[v] = 1;
        for (auto x: e[v]) {
            if (x.sc == 0 && dist0[x.fr] > dist0[v]) {
                dist0[x.fr] = dist0[v] + 1;
                par[x.fr] = v;
                q.push(x.fr);
            }
        }
    }
}


void bfs1() {
    queue < int > q;
    memset(dist, 63, sizeof(dist));
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (fin[v]) continue;
        for (auto x: e[v])  
            if (dist[x.fr] > dist[v] + 1) {
                dist[x.fr] = dist[v] + 1;
                q.push(x.fr);
            }
    }
}

void solve() {
    bfs0();
    bfs1();
    int mnDist = INF;
    for (int i = 0; i < n; i++)
        if (fin[i]) {
            mnDist = min(mnDist, dist[i]);
        }
    assert(mnDist < INF);
    
    vector < int > who;
    for (int i = 0; i < n; i++)
        if (fin[i])
            who.pb(i);
    for (int target = mnDist - 1; target >= 0; target--) {
        int low = 10;  
        assert(!who.empty());
        for (auto v: who) {
            for (auto x: e[v]) {
                if (dist[x.fr] == target) {
                    low = min(low, x.sc);
                }
            }
        }
        assert(low < 10);
        vector < int > tmp;
        for (auto v: who)
            for (auto x: e[v]) 
                if (dist[x.fr] == target && low == x.sc) {
                    if (dist0[x.fr] > INF)
                        tmp.pb(x.fr);
                    if (dist0[x.fr] > dist0[v]) {
                        dist0[x.fr] = dist0[v];
                        par[x.fr] = v;
                        how[x.fr] = x.sc;
                    }
                }
        who = tmp;
    }

    vector < int > number;
    vector < int > path;
    int v = 0;
    for (; v != n - 1; v = par[v]) {
        number.pb(how[v]);         
        path.pb(v);
    }
    path.pb(n - 1);
    reverse(all(number));
    int cur = 0;
    for (; cur < (int)number.size() && number[cur] == 0; cur++);
    if (cur == (int)number.size())
        puts("0");
    else {
        for (int i = cur; i < (int)number.size(); i++)
           printf("%d", number[i]); 
        printf("\n");
    }
    printf("%d\n", (int)path.size());
    for (auto x: path)
        printf("%d ", x);
    printf("\n");
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