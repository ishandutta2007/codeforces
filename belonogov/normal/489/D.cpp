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
typedef unsigned long long ull;
typedef unsigned int ui;
const int N = 3333;
const int INF = 1e9 + 19;
const ui T = 16;
const ui BASE = 1 << T;
const ui MOD = BASE - 1;

int n, m;
int a[N][N];
ull out[N][N / 64];
ull in[N][N / 64] ;
ui tmp[BASE];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        a[v][u] = 1;
    }
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            if (a[i][j]) {
                out[i][j / 64] |= 1ll << (j & 63);
                in[j][i / 64] |= 1ll << (i & 63);
            }
    int D = (n + 64 - 1) / 64;
    ull answer = 0;
    for (ui i = 0; i < BASE; i++)
        tmp[i] = __builtin_popcount(i);
    for (int v = 0; v < n; v++)
        for (int u = 0; u < n; u++) {
            if (v == u) continue;
            ui k = 0;
            for (int i = 0; i < D; i++) {
                ull mask = out[v][i] & in[u][i];
                if (mask == 0) continue;
                k += tmp[mask & MOD];
                k += tmp[(mask >> 16) & MOD];
                k += tmp[(mask >> 32) & MOD];
                k += tmp[(mask >> 48) & MOD];
                //k += __builtin_popcountll(out[v][i] & in[u][i]);
            }
            answer += k * (k - 1) / 2;
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