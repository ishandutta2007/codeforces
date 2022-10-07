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
const int N = 1111;
const long long INF = 1e9 + 19;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};


int n, m;
char s[N][N];
int p[N * N];
int sz[N * N];
int use[N * N];
int tmr;

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int getId(int x, int y) {
    return x * m + y;
}

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
}

int getId(int v) {
    return (p[v] == v)? v: p[v] = getId(p[v]);
}

void merge(int v, int u) {
    v = getId(v);
    u = getId(u);
    if (v == u) return;
    p[v] = u;
    sz[u] += sz[v];
}

void solve() {
    for (int i = 0; i < n * m; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++) 
            if (s[i][j] == '.' && s[i][j + 1] == '.')
                merge(getId(i, j), getId(i, j + 1));

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++) 
            if (s[i][j] == '.' && s[i + 1][j] == '.')
                merge(getId(i, j), getId(i + 1, j));

    for (int i = 0; i < n; i++, puts(""))
        for (int j = 0; j < m; j++) {
            int sum; 
            if (s[i][j] == '.') 
                printf(".");
            else {
                sum = 1; 
                tmr++;
                for (int t = 0; t < 4; t++) {
                    int x = i + dx[t];
                    int y = j + dy[t]; 
                    if (check(x, y) && s[x][y] == '.') {
                        int c = getId(getId(x, y));    
                        if (use[c] != tmr) {
                            use[c] = tmr;
                            sum += sz[c];
                        }
                    }
                } 
                printf("%d", sum % 10);
            }
        }

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