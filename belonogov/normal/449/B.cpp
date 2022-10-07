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
const int N = 5e5 + 100;
const int INF = 1e9;


vector < int > e[N];
vector < int > c[N];
set < pair < int, int > > y;
long long dist[N];
int cntWay[N];
int b[N];
int t[N];
set < pair < long long, int > > q;

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    int n, m, k, v, u, w;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &v, &u, &w);
        v--; u--;
        e[v].pb(u);
        e[u].pb(v);
        c[v].pb(w);
        c[u].pb(w);
    }
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &b[cur], &t[cur]);
        if (y.find(mp(b[cur], t[cur])) == y.end()) {
            y.insert(mp(b[cur], t[cur]));
            cur++;
        }
        else {
            ans++;
        }
    }
    k = cur;
    for (int i = 0; i < k; i++) {
        b[i]--;
        e[0].pb(b[i]);
        e[b[i]].pb(0);

        c[0].pb(t[i]);
        c[b[i]].pb(t[i]);
    }
    memset(dist, 63, sizeof(dist));
    dist[0] = 0;
    cntWay[0] = 1;
    q.insert(mp(0, 0));
    while (!q.empty()) {
        v = q.begin()->sc;
        q.erase(q.begin());
        for (int i = 0; i < (int)e[v].size(); i++) {
            int u = e[v][i];
            if (dist[v] + c[v][i] < dist[u]) {
                cntWay[u] = 0;
                q.erase(mp(dist[u], u));
                dist[u] = dist[v] + c[v][i]; 
                q.insert(mp(dist[u], u));
            }
            if (dist[v] + c[v][i] == dist[u])
                cntWay[u] = min(2, cntWay[u] + cntWay[v]);
        }
    }
    //for (int i = 0; i < n; i++)
        //cerr << cntWay[i] << " ";
    //cerr << endl;
    //for (int i = 0; i < n; i++)
        //cerr << dist[i] << " ";
    //cerr << endl;
    for (int i = 0; i < k; i++)
        if (cntWay[b[i]] > 1 || dist[b[i]] < t[i])
            ans++;
    printf("%d\n", ans);
    return 0;

}