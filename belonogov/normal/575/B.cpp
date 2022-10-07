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
const int T = 20;
const int MOD = 1e9 + 7;

int n, k;
vector < int > e[N];
int up[N][T];
int sum[2][N][T];
int a[N * 10];
bool use[N];
int tin[N];
int tout[N];
int tmr;
int h[N];
map < pair < int, int >, int > q;



void read() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int v, u, type;
        scanf("%d%d%d", &v, &u, &type);
        v--;
        u--;
        q[mp(v, u)] = type;
        e[v].pb(u);
        e[u].pb(v);
    }
    scanf("%d", &k);
    a[0] = 0;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    k++;
}

void dfs(int v, int p, int hh) {
    use[v] = 1;
    up[v][0] = p;
    tin[v] = tmr++;
    h[v] = hh;
    for (auto u: e[v])
        if (!use[u])
            dfs(u, v, hh + 1);
    tout[v] = tmr++;
}

bool isParrent(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int getLCA(int v, int u) {
    if (isParrent(v, u)) return v;
    if (isParrent(u, v)) return u;
    for (int i = T - 1; i >= 0; i--) 
        if (!isParrent(up[v][i], u))
            v = up[v][i];
    return up[v][0];
}

void add(int v, int h, int type) {
    //cerr << "v h type: " << v << " " << h << " " << type << endl;
    for (int i = 0; i < T; i++) {
        if ((h >> i) & 1) {
            h ^= (1 << i);
            sum[type][v][i]++;
            v = up[v][i];
        }
    }
    assert(h == 0);
}

void solve() {
    dfs(0, 0, 0);
    for (int i = 1; i < T; i++) 
        for (int v = 0; v < n; v++) 
            up[v][i] = up[up[v][i - 1]][i - 1];
    
    for (int i = 0; i < k - 1; i++) {
        int o = getLCA(a[i], a[i + 1]);
        //db(o);
        add(a[i], h[a[i]] - h[o], 0);  // up
        add(a[i + 1], h[a[i + 1]] - h[o], 1); // down
    }
    
    vector < long long > deg(k + 1);
    //deg[0] = 0;
    deg[0] = 1;
    for (int i = 0; i < k; i++) 
        deg[i + 1] = deg[i] * 2 % MOD;

    for (int i = T - 1; i > 0; i--) {
        for (int v = 0; v < n; v++) {
            for (int type = 0; type < 2; type++) {
                sum[type][v][i - 1] += sum[type][v][i];
                sum[type][up[v][i - 1]][i - 1] += sum[type][v][i];
            }
        }
    }
    //for (int type = 0; type < 2; type++, cerr << endl) {
        //for (int i = 0; i < n; i++)
            //cerr << sum[type][i][0] << " ";
    //}

    
    long long answer = 0;
    for (int v = 1; v < n; v++) {
        int p = up[v][0];
        //db2(v, p);
        if (q.count(mp(v, p)) == 1 && q[mp(v, p)] == 1) {
            //c
            answer = (answer + deg[sum[1][v][0]] - 1) % MOD;
        }
        if (q.count(mp(p, v)) == 1 && q[mp(p, v)] == 1) {
            answer = (answer + deg[sum[0][v][0]] - 1) % MOD;
        }
        //db2(v, answer);
    }
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