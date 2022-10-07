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
const int N = 111;
const int INF = 1e9;

int n;
char s[N][N];
char res[N][N];
bool use[N][N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
}
bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void solve() {
    memset(res, 'x', sizeof(res));
    res[n - 1][n - 1] = 'o';
    for (int x1 = 0; x1 < n; x1++)
        for (int y1 = 0; y1 < n; y1++) {
            if (s[x1][y1] != '.') continue;
            for (int x2 = 0; x2 < n; x2++)
                for (int y2 = 0; y2 < n; y2++) {
                    if (s[x2][y2] != 'o') continue;
                    int dx = x1 - x2;
                    int dy = y1 - y2;
                    res[n - 1 + dx][n - 1 + dy] = '.';
                }
        }
    for (int x1 = 0; x1 < n; x1++)
        for (int y1 = 0; y1 < n; y1++) {
            if (s[x1][y1] != 'o') continue;
            for (int dx = -n + 1; dx <= n - 1; dx++)
                for (int dy = -n + 1; dy <= n - 1; dy++) {
                    if (res[n - 1 + dx][n - 1 + dy] != 'x') continue;
                    if (check(x1 + dx, y1 + dy))
                        use[x1 + dx][y1 + dy] = 1;
                }
        }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i][j] == 'x' && !use[i][j]) {
                printf("NO\n");
                return;
            }
    
 
    printf("YES\n");
    for (int i = 0; i < n * 2 - 1; i++, printf("\n"))
        for (int j = 0; j < n * 2 - 1; j++)
            printf("%c", res[i][j]);

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