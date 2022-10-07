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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const int INF = 1e9 + 19;
const int K = 20;
const int T = 10;

struct TenMin{
    int sz;
    int data[T];
    TenMin(): sz(0) { }

    void add(int x) {
        bool flag = 0;
        if (sz < T) {
            data[sz++] = x; 
            flag = 1;
        }
        else {
            if (data[sz - 1] > x) {
                data[sz - 1] = x;
                flag = 1;
            }
        }
        if (flag) {
            for (int i = sz - 1; i >= 1; i--) {
                if (data[i - 1] > data[i])
                    swap(data[i - 1], data[i]);
            }
        }
    }
};

int n, m, q;
vector < int > e[N];
bool use[N];
int tin[N];
int tout[N];
int tmr;
int jump[N][K];
TenMin mn[N][K];
int h[N];

void read() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x); x--;
        mn[x][0].add(i);
    }
}

void dfs(int v, int p, int hh) {
    use[v] = 1;
    tin[v] = tmr++;
    jump[v][0] = p;
    h[v] = hh;
    for (auto u: e[v]) {
        if (!use[u])
            dfs(u, v, hh + 1);
    }
    tout[v] = tmr++;
}

bool isPar(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int getLCA(int v, int u) {
    if (isPar(v, u)) return v;
    if (isPar(u, v)) return u;
    for (int i = K - 1; i >= 0; i--) {
        if (!isPar(jump[v][i], u))
            v = jump[v][i];
    }
    return jump[v][0];
}

void solve() {
    dfs(0, 0, 0);
    for (int i = 1; i < K; i++) {
        for (int v = 0; v < n; v++) {
            int u = jump[v][i - 1];
            jump[v][i] = jump[u][i - 1];
            for (int j = 0; j < mn[v][i - 1].sz; j++) 
                mn[v][i].add(mn[v][i - 1].data[j]);

            if (h[v] + 1 > (1 << (i - 1))) {
                for (int j = 0; j < mn[u][i - 1].sz; j++)
                    mn[v][i].add(mn[u][i - 1].data[j]);
            }
            else {
                assert(u == 0);
            }
        }
    }

    for (int t = 0; t < q; t++) {
        int v, u, a;
        scanf("%d%d%d", &v, &u, &a); v--; u--;

        TenMin res;
        int o = getLCA(v, u); 
        //db(o);
        //db(mn[o][0].sz);
        for (int j = 0; j < mn[o][0].sz; j++)
            res.add(mn[o][0].data[j]);
        for (int tt = 0; tt < 2; tt++) {
            int dh = h[v] - h[o];
            for (int i = K - 1; i >= 0; i--) {
                if ((dh >> i) & 1) {
                    for (int j = 0; j < mn[v][i].sz; j++)
                        res.add(mn[v][i].data[j]);
                    dh ^= 1 << i;
                    v = jump[v][i];
                }
            }
            swap(v, u);
        }
        int kk = min(res.sz, a);
        printf("%d ", kk);
        for (int i = 0; i < kk; i++)
            printf("%d ", res.data[i] + 1);
        puts("");
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