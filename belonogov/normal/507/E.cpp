#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
const int N = 1e6 + 10;
const int INF = 1e9;


int n, m;
vector < pair < int, int > > e[N];
pair < int, int > dist[N];
set < pair < pair < int, int >, int > > q;
map < pair < int, int >, int > w;
int p[N];

pair < int, int > sum(pair < int, int > a, pair < int, int > b) {
    return mp(a.fr + b.fr, a.sc + b.sc);
}

pair < int, int > myMp(int a, int b) {
    if (a > b) swap(a, b);
    return mp(a, b);
}

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u, z;
        scanf("%d%d%d", &v, &u, &z);
        z ^= 1;
        v--; u--;
        e[v].pb(mp(u, z));
        e[u].pb(mp(v, z));
        if (z == 0) {
            w[(myMp(v, u))] = 1;
        }
    }
    for (int i = 0; i < n; i++)
        dist[i] = mp(INF, INF);
    dist[0] = mp(0, 0);
    q.insert(mp(mp(0, 0), 0));
    while (!q.empty()) {
        int v = q.begin()->sc;
        q.erase(q.begin());
        for (auto x: e[v]) {
            auto c = mp(1, x.sc);
            if (dist[x.fr] > sum(c, dist[v])) {
                q.erase(mp(dist[x.fr], x.fr));
                dist[x.fr] = sum(c, dist[v]);
                p[x.fr] = v;
                q.insert(mp(dist[x.fr], x.fr));
            }
        }
    }
    int v = n - 1;
    for (; v != 0; ) {
        int u = p[v]; 
        if (w.find(myMp(v, u)) == w.end())
            w[(myMp(v, u))] = 0;
        else
            w.erase(myMp(v, u));
        v = u;
    }
    printf("%d\n", (int)w.size());
    for (auto x: w) {
        printf("%d %d %d\n", x.fr.fr + 1, x.fr.sc + 1, x.sc ^ 1); 
    } 
}

void solve() {

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