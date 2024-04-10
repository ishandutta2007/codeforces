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
const int N = 1e6 + 10;
const int INF = 1e9 + 19;

struct Edge {
    int v, l, id;
};

int n, m, s, t;
long long distS[N];
long long distT[N];
vector < Edge > e[N];
vector < Edge > er[N];
vector < pair < int, int > > g[N];
set < pair < long long, int > > q;
char flag[N];
char use[N];
vector < int > st;
long long answer[N];


void read() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    s--;
    t--;
    for (int i = 0; i < m; i++) {
        int v, u, l;
        scanf("%d%d%d", &v, &u, &l); v--; u--;
        e[v].pb({u, l, i});
        er[u].pb({v, l, i});
    }
}

void dfs0(int v) {
    use[v] = 1;
    for (auto x: g[v])
        if (!use[x.fr])
            dfs0(x.fr);
    st.pb(v);
}

void dijkstra(int v, long long * dist, vector < Edge > * e) {
    memset(dist, 63, sizeof(long long) * n); 
    dist[v] = 0;
    q.insert(mp(0, v));
    while (!q.empty()) {
        int v = q.begin()->sc;
        q.erase(q.begin());
        for (auto x: e[v]) {
            if (dist[x.v] > dist[v] + x.l) {
                q.erase(mp(dist[x.v], x.v));
                dist[x.v] = dist[v] + x.l;
                q.insert(mp(dist[x.v], x.v));
            }
        }
    }
}

void solve() {
    dijkstra(s, distS, e);
    dijkstra(t, distT, er);
    vector < pair < long long, int > > perm;   
    for (int i = 0; i < n; i++)
        perm.pb(mp(distS[i], i));
    sort(perm.begin(), perm.end());
    flag[t] = 1;
    for (int i = n - 1; i >= 0; i--) {
        int v = perm[i].sc;
        for (auto x: e[v])
            if (flag[x.v] && distS[v] + x.l == distS[x.v]) {
                flag[v] = 1;
                g[v].pb(mp(x.v, x.id));
            }
    }

    memset(answer, -1, sizeof(answer));

    memset(use, 0, sizeof(use));
    dfs0(s);
    //assert((int)st.size() == n);
    reverse(st.begin(), st.end()); 
    vector < int > rev(n, -1);
    for (int i = 0; i < (int)st.size(); i++)
        rev[st[i]] = i;
    int mxR = 0;
    for (int i = 0; i < (int)st.size(); i++) {
        int v = st[i];
        if ((int)g[v].size() == 1) {
            assert(mxR >= i);
            if (mxR == i) {
                answer[g[v][0].sc] = 0;             
            }
        }
        for (auto x: g[v])
            mxR = max(mxR, rev[x.fr]);
    }
    //for (int v = 0; v < n; v++) {
        //epr("%d:   ", v + 1);
        //for (auto x: g[v])
            //cerr << x.fr  + 1<< " ";
        //cerr << endl;
    //}


    long long dist = distS[t];
    for (int v = 0; v < n; v++) {
        for (auto x: e[v]) {
            if (answer[x.id] == -1) {
                int u = x.v;
                long long l = distS[v] + distT[u] + x.l;
                long long diff = l - dist + 1;
                //db(diff);
                assert(diff > 0);
                if (x.l > diff) {
                    //db(diff);
                    answer[x.id] = diff;
                }
            }
        } 
    }
    for (int i = 0; i < m; i++) {
        if (answer[i] == -1)
            puts("NO");
        else if (answer[i] == 0)
            puts("YES");
        else
            printf("CAN %lld\n", answer[i]);

    }

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