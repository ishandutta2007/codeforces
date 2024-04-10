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
const int N = 2222;
const long long INF = 1e9 + 19;

int n, m;
bool useA[N];
bool useB[N];
double dp[N][N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y); x--; y--;
        useA[x] = 1;
        useB[y] = 1;
    }
}

void solve() {
    int cntA = 0;
    int cntB = 0;
    for (int i = 0; i < n; i++) {
        cntA += !useA[i];
        cntB += !useB[i];
    }
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            if (i == 0 && j == 0) continue;
            double p1 = i * j * 1.0 / n / n;   
            double p2 = (n - i) * j * 1.0 / n / n;
            double p3 = (n - j) * i * 1.0 / n / n;
            double p4 = (n - i) * (n - j) * 1.0 / n / n;
            double x1 = (i > 0 && j > 0)? dp[i - 1][j - 1]: 0;
            double x2 = (j > 0)? dp[i][j - 1]: 0;
            double x3 = (i > 0)? dp[i - 1][j]: 0;
            dp[i][j] = (1 + p1 * x1 + p2 * x2 + p3 * x3) / (1 - p4);
        }

    printf("%.17f\n", dp[cntA][cntB]);

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