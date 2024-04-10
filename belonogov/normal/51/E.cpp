#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 800;
const int inf = 1e9;

int a[maxn][maxn];
unsigned int b[maxn][maxn / 32];
int c[maxn][maxn];
int p[maxn][maxn][maxn / 32];

void insert(int x, int y) {
    b[x][y >> 5] |= (1 << (y & 31));
}

int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
#endif
    int n, m, x, y;
    long long ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y); x--; y--;
        a[x][y] = a[y][x] = 1;
        insert(x, y);
        insert(y, x);
    }
    int T = (n + 31) / 32;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < T; k++) {
                c[i][j] += __builtin_popcount(b[i][k] & b[j][k]);
                p[i][j][k + 1] = c[i][j];
            }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++) {
                if (i == k || j == k) continue;
                if (a[i][j] != 1) continue;
                int x = 0, y = 0, z = 0;
                x = p[i][k][k / 32];
                y = p[j][k][k / 32];
                //for (int ii = 0; ii < k / 32; ii++)
                    //x += __builtin_popcount(b[i][ii] & b[k][ii]);
                x += __builtin_popcount((b[i][k / 32] & b[k][k / 32]) & ((1u << (k & 31)) - 1));
                //for (int ii = 0; ii < k / 32; ii++)
                    //y += __builtin_popcount(b[j][ii] & b[k][ii]);
                y += __builtin_popcount((b[j][k / 32] & b[k][k / 32]) & ((1u << (k & 31)) - 1));
                for (int ii = 0; ii < k / 32; ii++)
                    z += __builtin_popcount(b[i][ii] & b[j][ii] & b[k][ii]); 
                z += __builtin_popcount((b[j][k / 32] & b[i][k / 32] & b[k][k / 32]) & ((1u << (k & 31)) - 1));
                x -= a[i][j] && a[k][j];
                y -= a[i][j] && a[k][i];
                //if (x * y - z > 0) {
                    //cerr << "i j k: " << i << " " << j << " " << k << "           ";
                    //cerr << "x y z + : " << x << " " << y << " " << z << "      " << x * y - z <<  endl;
                //}
                ans += x * y - z;
            }
    //cerr << "ans: " << ans << endl;
    //assert(ans % 5 == 0);
    //cout << ans / 5 << endl;
    cout << ans << endl;
    return 0;
}