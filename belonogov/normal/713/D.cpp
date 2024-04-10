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
const int N = 1010;
const long long INF = 1e9 + 19;
const int LOG = 11;

int n, m;
int a[N][N];
int b[N][N];
int pref[N][N];
short table[LOG][LOG][N][N]; 
int deg[N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}

int getSum(int x1, int y1, int x2, int y2) {
    return pref[x2][y2] - pref[x1][y2] - pref[x2][y1] + pref[x1][y1];
}

bool isSquare(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (y2 - y1) == getSum(x1, y1, x2, y2);
}

int getMax(int x1, int y1, int x2, int y2) {
    int szX = x2 - x1;
    int szY = y2 - y1;
    int dx = deg[szX];
    int dy = deg[szY];
    //db2(dx, dy);
    //db2(szX, szY);
    //db2(x1, y1);
    //db2(x2, y2);
    int tmp = max(max(table[dx][dy][x1][y1], table[dx][dy][x2 - (1 << dx)][y1]),
               max(table[dx][dy][x1][y2 - (1 << dy)], table[dx][dy][x2 - (1 << dx)][y2 - (1 << dy)]));
    //db("After");
    return tmp;
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + a[i][j];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            int l = 0;
            int r = min(n - i, m - j) + 1;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (isSquare(i, j, i + mid, j + mid))
                    l = mid;
                else
                    r = mid;
            }
            b[i][j] = l;
        }

    for (int i = 2; i <= max(n, m); i++)
        deg[i] = deg[i / 2] + 1;

    //for (int i = 0; i < 10; i++)
        //db2(i, deg[i]);

    for (int dx = 0; dx <= 10; dx++)
        for (int dy = 0; dy <= 10; dy++)
            for (int i = 0; i + (1 << dx) <= n; i++)
                for (int j = 0; j + (1 << dy) <= m; j++) {
                    if (dx == 0 && dy == 0) {
                        table[0][0][i][j] = b[i][j];
                    }
                    else if (dx != 0) {
                        table[dx][dy][i][j] = max(table[dx - 1][dy][i][j], table[dx - 1][dy][i + (1 << (dx - 1))][j]);
                    }
                    else 
                        table[dx][dy][i][j] = max(table[dx][dy - 1][i][j], table[dx][dy - 1][i][j + (1 << (dy - 1))]);
                }
    //db("tut");
    int t;
    scanf("%d", &t);
    for (int it = 0; it < t; it++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2); x1--; y1--;
        int l = 0;
        int r = min(x2 - x1, y2 - y1) + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            //db(mid);
            if (getMax(x1, y1, x2 - mid + 1, y2 - mid + 1) >= mid)
                l = mid;
            else
                r = mid;
        }

        printf("%d\n", l);
    }



}

void stress() {

}


int main(){
#ifdef MY_DEBUG
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