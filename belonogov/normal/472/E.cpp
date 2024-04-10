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
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 33;
const int INF = 1e9;
const int dx[8] = {1, 1,  1, 0,  0, -1, -1, -1};
const int dy[8] = {1, 0, -1, 1, -1,  1,  0, -1};

int n, m;
int a[N][N];
int b[N][N];
int a0[N][N];
int b0[N][N];
int c[N];
int color[N * N];
bool use[N][N];
bool flag;
int dist[N][N];
int p[N][N];
vector < pair < int, int > > ans;
queue < pair < int, int > > q;
pair < int, int > fromBFS[N * N];
int curBFS;

void read() {
    flag = 1;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            color[a[i][j]]++;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &b[i][j]);
            color[b[i][j]]--;
            flag &= color[b[i][j]] >= 0;
        }
}

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool compM(int * a, int * b, int n) {
    for (int i = 0; i < m; i++)
        if (a[i] != b[i]) 
            return 0;
    return 1;
}

void stupidPart() {
    bool flagSwap = 0;
    if (n != 1) {
        flagSwap = 1; 
        swap(n, m);
        int l = max(n, m);
        for (int i = 0; i < l; i++)
            for (int j = i + 1; j < l; j++) {
                swap(a[i][j], a[j][i]);
                swap(b[i][j], b[j][i]);
            }
    } 
    bool flagS = 0;
    for (int i = 0; i < m && !flagS; i++) {
        for (int j = 0; j < m; j++)
            c[j] = a[0][j];        
        for (int j = 0; i - j - 1 >= 0; j++) {
            swap(c[i - j], c[i - j - 1]); 

            if (compM(b[0], c, m)) {
                ans.pb(mp(0, i));
                for (int k = 0; k <= j; k++)
                    ans.pb(mp(0, i - k - 1));
                flagS = 1;
                break;
            }
        }    
        for (int j = 0; j < m; j++)
            c[j] = a[0][j];        

        for (int j = 0; j + 1 + i < m; j++) {
            swap(c[i + j], c[i + j + 1]);


            if (compM(b[0], c, m)) {
                ans.pb(mp(0, i));
                for (int k = 0; k <= j; k++)
                    ans.pb(mp(0, i + k + 1));
                flagS = 1;
                break;
            }
        }
    }
    if (flagSwap) {
        swap(n, m);
        int l = max(n, m);
        for (int i = 0; i < l; i++)
            for (int j = i + 1; j < l; j++) {
                swap(a[i][j], a[j][i]);
                swap(b[i][j], b[j][i]);
            }
        for (int i = 0; i < (int)ans.size(); i++)
            swap(ans[i].fr, ans[i].sc);
    }
    if (!flagS)
        flag = 0;
}

int distF(int x1, int y1, int x0, int y0) {
    return abs(x1 - x0) + abs(y1 - y0);
}

void bfs(int sX, int sY, int fX, int fY, int x, int y) {
    memset(dist, 63, sizeof(dist)); 
    memset(p, -1, sizeof(p));
    dist[sX][sY] = 0;
    q.push(mp(sX, sY));
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        int x1 = t.fr;
        int y1 = t.sc;
        for (int i = 0; i < 8; i++) {
            int x2 = x1 + dx[i];
            int y2 = y1 + dy[i];
            if (check(x2, y2) && !use[x2][y2] && !(x2 == x && y2 == y) && dist[x2][y2] > dist[x1][y1] + 1) {
                dist[x2][y2] = dist[x1][y1];
                p[x2][y2] = i;
                q.push(mp(x2, y2));
            }
        }
        if (dist[fX][fY] < INF)
            break;
    }
    assert(dist[fX][fY] < INF);
    curBFS = 0;
    for (; fX != sX || fY != sY;) {
        fromBFS[curBFS++] = mp(fX, fY);
        int ddx = dx[p[fX][fY]] * -1;
        int ddy = dy[p[fX][fY]] * -1;
        fX += ddx;
        fY += ddy;
    }
    reverse(fromBFS, fromBFS + curBFS);
}

void make(int x, int y) {
    int x0 = -1, y0 = -1; 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!use[i][j] && a[i][j] == b[x][y]) {
                x0 = i;
                y0 = j;
            }
    if (x == x0 && y == y0) {
        use[x][y] = 1;
        return;
    }
    int x1 = x0;
    int y1 = y0;
    vector < pair < int, int > > path;
    path.pb(mp(x0, y0));
    for (; x1 != x || y1 != y; ) {
        bool flagT = 0;
        for (int i = 0; i < 8; i++) {
            int x2 = x1 + dx[i];
            int y2 = y1 + dy[i]; 
            if (check(x2, y2) && !use[x2][y2] && distF(x2, y2, x, y) < distF(x1, y1, x, y)) {
                path.pb(mp(x2, y2));
                x1 = x2;
                y1 = y2;
                flagT = 1;
                break;
            }
        }
        assert(flagT);
    } 
    path.pb(mp(0, 0));
    int myX = 0;
    int myY = 0;
    for (int i = 1; i < (int)path.size(); i++) {
        auto t = path[i];
        bfs(myX, myY, t.fr, t.sc, x0, y0);
        int cur = ans.size();
        for (int j = 0; j < curBFS; j++) 
            ans.pb(fromBFS[j]);

        if (i + 1 < (int)path.size())
            ans.pb(path[i - 1]);
        for (int j = cur; j < (int)ans.size(); j++)     
            swap(a[ans[j - 1].fr][ans[j - 1].sc], a[ans[j].fr][ans[j].sc]);
        myX = path[i - 1].fr;
        myY = path[i - 1].sc;
        x0 = path[i].fr;
        y0 = path[i].sc;
    }
    use[x][y] = 1;
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            a0[i][j] = a[i][j];
            b0[i][j] = b[i][j];
        }

    if (!flag) return;
    if (n == 1 || m == 1) {
        stupidPart();
        return;
    }
    int x1 = -1;
    int y1 = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (b[0][0] == a[i][j]) {
                x1 = i;
                y1 = j;
            }
    assert(x1 != -1);
    ans.pb(mp(x1, y1)); 
    bfs(x1, y1, 0, 0, -1, -1);
    for (int i = 0; i < curBFS; i++)
        ans.pb(fromBFS[i]);

    for (int j = 1; j < (int)ans.size(); j++)
        swap(a[ans[j - 1].fr][ans[j - 1].sc], a[ans[j].fr][ans[j].sc]);

    memset(use, 0, sizeof(use));
    for (int i = n - 1; i >= 2; i--)
        for (int j = m - 1; j >= 0; j--)
            make(i, j);
    for (int j = m - 1; j >= 0; j--)
        for (int i = 1; i >= 0; i--)
            if (i != 0 || j != 0)
                make(i, j);
}


void printAns() {
    if (!flag)
        printf("-1\n");
    else {
        printf("%d\n", (int)ans.size() - 1);
        for (auto x : ans)
            printf("%d %d\n", x.fr + 1, x.sc + 1);
    }
}
int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    read();
    solve();
    printAns();
}