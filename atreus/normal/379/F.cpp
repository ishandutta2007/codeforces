#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

int par[maxn][30], h[maxn];

int lca (int fi, int se) {
    if (h[fi] < h[se])
        return lca (se, fi);

    for (int i = 20; i >= 0; i--)
        if (h[fi] - (1 << i) >= h[se])
            fi = par[fi][i];

    if (fi == se)
        return fi;

    for (int i = 20; i >= 0; i--) {
        if (par[fi][i] != par[se][i]) {
            fi = par[fi][i];
            se = par[se][i];
        }
    }
    return par[fi][0];
}

int Dis (int fi, int se) {
    int anc = lca (fi, se);
    return -2 * h[anc] + h[fi] + h[se];
}

int main () {
    memset (par, -1, sizeof par);
    int n;
    scanf ("%d", &n);
    int cnt = 4, len = 2, L = 2, R = 3;
    h[1] = 0;
    for (int i = 2; i <= 4; i++) {
        par[i][0] = 1;
        h[i] = 1;
    }
        
    for (int j = 1; j <= n; j++) {
        int u;
        scanf ("%d", &u);
        h[cnt + 2] = h[cnt + 1] = h[u] + 1;
        par[cnt + 2][0] = par[cnt + 1][0] = u;
        for (int i = 1; par[cnt + 1][i - 1] != -1 and i <= 20; i++)
            par[cnt + 2][i] = par[cnt + 1][i] = par[par[cnt + 1][i - 1]][i - 1];
        int x = Dis (L, cnt + 1), y = Dis (R, cnt + 1);
        if (x > len) {
            R = cnt + 1;
            len = x;
        }
        else if (y > len) {
            L = cnt + 1;
            len = y;
        }
        cnt += 2;
        printf ("%d\n", len);
    }
}