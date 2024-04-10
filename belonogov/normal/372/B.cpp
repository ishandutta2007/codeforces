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
const int N = 44; 
const long long INF = 1e9 + 19;

int dp[N][N][N][N];
char s[N][N];
int up[N][N];
int st[N];
int n, m, q;


void read() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            up[i + 1][j] = (s[i][j] == '1')? 0: up[i][j] + 1;

    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++) {
            for (int i = x; i < n; i++) {
                int cur = 0;
                int area = 0;
                for (int j = y; j < m; j++) {
                    dp[x][y][i + 1][j + 1] = dp[x][y][i][j + 1] + dp[x][y][i + 1][j] - dp[x][y][i][j];
                    int val = min(i - x + 1, up[i + 1][j]);
                    for (int d = 0; d < cur; d++) {
                        if (st[d] > val) {
                            area -= st[d];
                            st[d] = val;
                            area += st[d];
                        }
                    }
                    st[cur++] = val;
                    area += val;
                    dp[x][y][i + 1][j + 1] += area;
                }  
            }

        }
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2); x1--; y1--;
        printf("%d\n", dp[x1][y1][x2][y2]);
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