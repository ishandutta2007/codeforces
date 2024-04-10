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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 3333;
const long long INF = 1e9 + 19;

int n, m;
vector < int > e[N];
int mn1[N][4];
int mn2[N][4];
int d[N][N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
    } 
}

void solve() {
    memset(d, 63, sizeof(d));
    for (int st = 0; st < n; st++) {
        d[st][st] = 0;
        queue < int > q;
        q.push(st);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto u: e[v])
                if (d[st][u] > d[st][v] + 1) {
                    d[st][u] = d[st][v] + 1;
                    q.push(u);
                }
        }
    }
    //for (int i = 0; i < n; i++, cerr << endl)
        //for (int j = 0; j < n; j++)
            //cerr << d[i][j] << " ";
    memset(mn1, -1, sizeof(mn1));
    memset(mn2, -1, sizeof(mn2));

    int answer = -1;
    int ra, rb, rc, rd;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] < INF && i != j) {
                mn1[i][3] = j;      
                //for (int k = 0; k <= 3; k++)
                    //cerr << mn1[i][k] << " ";
                //cerr << endl;
                for (int k = 2; k >= 0; k--) {
                    //db(k);
                    //for (int k = 0; k <= 3; k++)
                        //cerr << mn1[i][k] << " ";
                    //cerr << endl;
                    assert(mn1[i][k + 1] != -1);
                    if (mn1[i][k] == -1 || (d[i][mn1[i][k]] < d[i][mn1[i][k + 1]])) {
                        swap(mn1[i][k], mn1[i][k + 1]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[j][i] < INF && i != j) {
                mn2[i][3] = j;      
                for (int k = 2; k >= 0; k--) {
                    assert(mn2[i][k + 1] != -1);
                    if (mn2[i][k] == -1 || d[mn2[i][k]][i] < d[mn2[i][k + 1]][i])
                        swap(mn2[i][k], mn2[i][k + 1]);
                }
            }
        }
    }

    //for (int i = 0; i < n; i++, cerr << endl)
        //for (int j = 0; j < 3; j++)
            //cerr << mn1[i][j] << " ";

    //cerr << endl;
    //for (int i = 0; i < n; i++, cerr << endl)
        //for (int j = 0; j < 3; j++)
            //cerr << mn2[i][j] << " ";



    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++) {
            if (a == b || d[a][b] > INF) continue;
            for (int k = 0; k < 3; k++)
                for (int t = 0; t < 3; t++) {
                    int v = mn2[a][k];
                    int u = mn1[b][t];
                    if (v == -1 || u == -1) continue;
                    if (v == u || v == a || v == b) continue;
                    if (a == b || a == u || b == u) continue;
                    int res = d[v][a] + d[a][b] + d[b][u];
                    //cerr << "v a b u: " << v << " " << a << " " << b << " " << u << endl;
                    assert(res < INF);
                    if (res > answer) {
                        answer = res;
                        ra = v;
                        rb = a;
                        rc = b;
                        rd = u;
                    }
                }
        }
    //db(answer);
     

    printf("%d %d %d %d\n", ra + 1, rb + 1, rc + 1, rd + 1);

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
        }
    }
    else {
        stress();
    }

    return 0;
}