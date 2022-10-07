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
pair < vector < int >, int > e[N];
vector < pair < int, int > > g[N];
vector < pair < int, int > > query[N];
vector < int > color[N];
vector < int > p[N];
int answer[N];
int q, sz;
pair < int, int > cnt[N];

int use[N];
int tmr;
int tmrCnt;
int useBig[N];


void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u, c;
        scanf("%d%d%d", &v, &u, &c); v--; u--; c--;
        //e[v].pb(mp(u, c));
        //e[u].pb(mp(v, c));
        g[c].pb(mp(v, u));
        color[v].pb(c);
        color[u].pb(c);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)  {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        query[v].pb(mp(u, i));
    }


}

int getId(int id, int v) {
    return p[id][v] == v? v: p[id][v] = getId(id, p[id][v]);
}

void add(int v, int u) {
    if (e[v].sc != tmr) {
        e[v].sc = tmr;
        e[v].fr.clear();
    }
    e[v].fr.pb(u);
}

void dfs(int v) {
    use[v] = tmr;
    if (cnt[v].sc != tmrCnt)  {
        cnt[v] = mp(0, tmrCnt);
    }
    cnt[v].fr++;
    for (auto u: e[v].fr)
        if (use[u] != tmr)
            dfs(u);
}

void solve() {

    for (int i = 0; i < n; i++) {
        sort(all(color[i]));
        color[i].resize(unique(all(color[i])) - color[i].begin());
    }

    sz = sqrt(n);
    //sz = n;
    //db(sz);
    vector < int > big;
    for (int i = 0; i < m; i++) 
        if ((int)g[i].size() > sz) {
            big.pb(i);
            useBig[i] = 1;
            p[i].resize(n);
            for (int j = 0; j < n; j++)
                p[i][j] = j;
            //db(i);
            for (auto x: g[i]) {
                //db2(x.fr, x.sc);
                int v = getId(i, x.fr);
                int u = getId(i, x.sc);
                p[i][v] = u;
            }
        }
    //db("here");

    //db(big.size());
    for (int v = 0; v < n; v++) {
        if (query[v].empty()) continue;
        //db(v);

        tmrCnt++;
        for (auto c: color[v]) {
            //db(c);
            if (useBig[c]) continue;
            tmr++;
            for (auto x: g[c]) {
                add(x.fr, x.sc);
                add(x.sc, x.fr);
            }
            dfs(v);
        }
        //db(v);

        //db(answer[0]);
        for (auto y: query[v]) {
            int u = y.fr;
            for (auto x: big) {
                //db(x);
                int r1 = getId(x, v);
                int r2 = getId(x, u);
                //db2(r1, r2);
                if (r1 == r2)
                    answer[y.sc]++;
            }
            if (cnt[u].sc == tmrCnt)
                answer[y.sc] += cnt[u].fr;
        }
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", answer[i]);
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