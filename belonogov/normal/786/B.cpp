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
#include <random>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 4e5 + 10;
const long long INF = 1e9 + 19;
const long long INF18 = 1e18;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


vector<pair<int,int>> e[N];
ll dist[N];
int n;


void addE(int v, int u, int w) {
    //db3(v, u, w);
    e[v].pb({u, w});
}

void addDown(int l, int r, int w, int v) {
    l += n;
    r += n;
    for (; l < r; l /= 2, r /= 2) {
        if (l & 1) addE(v, l++, w);
            //e[v].pb({l++, w});
        if (r & 1) addE(v, --r, w);
           // e[v].pb({--r, w});
    }
}

void addUp(int l, int r, int w, int v) {
    l += n;
    r += n;
    for (; l < r; l /= 2, r /= 2) {
        if (l & 1) e[l++ + n * 2].pb({v, w});
        if (r & 1) e[--r + n * 2].pb({v, w});
    }

}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int m, st;
    scanf("%d%d%d", &n, &m, &st); st--;

    for (int i = 1; i < n; i++) {
        addE(i, i * 2, 0);
        addE(i, i * 2 + 1, 0);

        addE(i * 2 + n * 2, i + n * 2, 0);
        addE(i * 2 + 1 + n * 2, i + n * 2, 0);
    } 

    for (int i = 0; i < m; i++) {
        int type, v, l, r, u, w;
        scanf("%d%d", &type, &v); v--;
            //db(type);
        if (type == 1) {
            scanf("%d%d", &u, &w); u--;
            addE(v + n, u + n, w);
        }
        else {
            assert(type == 2 || type == 3);
            scanf("%d%d%d", &l, &r, &w); l--;
            if (type == 2) {
                addDown(l, r, w, v + n);
            }
            else {
                addUp(l, r, w, v + n);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        //db2(i + n, i + n * 3);
        e[i + n].pb({i + n * 3, 0});
        e[i + n * 3].pb({i + n, 0});
    }
    set<pair<ll,int>> q;

    memset(dist, 63, sizeof dist);
    dist[st + n] = 0;
    q.insert({0, st + n});
    while (!q.empty()) {
        int v = q.begin()->S;
        //db(v);
        q.erase(q.begin());
        for (auto x: e[v]) {
            //db("dsf");
            if (dist[x.F] > dist[v] + x.S) {
                q.erase({dist[x.F], x.F});
                dist[x.F] = dist[v] + x.S;
                q.insert({dist[x.F], x.F});
            }
        }
    }

    for (int i = n; i < n * 2; i++) {
        if (dist[i] >= INF18)
            printf("-1 ");
        else
            printf("%lld ", dist[i]);
    }
    puts("");
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}