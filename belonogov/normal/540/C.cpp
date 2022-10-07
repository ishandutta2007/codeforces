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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl

#define equal equalll
#define less lesss
const int N = 1e3 + 10;
const int INF = 1e9;
const int dx[4] = {1, 0, -1, 0}; 
const int dy[4] = {0, -1, 0, 1}; 

int n, m;
char s[N][N];
int b[N][N];
int d[N][N];
queue < pair < int, int > > q;
int r1, c1;
int r2, c2;

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    scanf("%d%d", &r1, &c1);
    c1--; r1--;
    scanf("%d%d", &r2, &c2); 
    r2--; c2--;
}

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = (s[i][j] == '.')? 0: 1;
    int cntFree = 0;
    for (int i = 0; i < 4; i++) {
        int x = r2 + dx[i];
        int y = c2 + dy[i];
        if (check(x, y) && b[x][y] == 0)
            cntFree++;
    }

    //if (c1 == c2 && r1 == r2) {
    if (dist(r1, c1, r2, c2) == 0) {
        if (cntFree >= 1) return 1;
        return 0;
    }
    if (dist(r1, c1, r2, c2) == 1) {
        if (b[r2][c2] == 1) return 1;
        if (cntFree >= 1) return 1;
        return 0;
    } 
    q.push(mp(r1, c1)); 
    memset(d, 63, sizeof(d));
    d[r1][c1] = 0;
    while (!q.empty()) {
        auto pr = q.front();
        q.pop();
        int x = pr.fr;
        int y = pr.sc;
        for (int i = 0; i < 4; i++) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (!check(x1, y1)) continue;
            if (b[x1][y1] == 0 && d[x1][y1] > d[x][y] + 1) {
                d[x1][y1] = d[x][y] + 1;
                q.push(mp(x1, y1));
            }
            if (b[x1][y1] == 1) {
                d[x1][y1] = min(d[x1][y1], d[x][y] + 1);
            }
        }
    }
    //for (int i = 0; i < n; i++, cerr << endl)
        //for (int j = 0; j < m; j++)
            //cerr << d[i][j] << " ";
    //db(d[r2][c2]);
    if (d[r2][c2] >= INF) return 0;
    if (b[r2][c2] == 1) return 1;
    if (cntFree < 2) return 0;
    return 1;
}

void printAns(int x) {
    if (x) printf("YES\n");
    else printf("NO\n");
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
            printAns(solve());
        }
    }
    else {
        stress();
    }

    return 0;
}