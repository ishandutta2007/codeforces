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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 333;;
const int INF = 1e9 + 19;
const int ALF = 26;

int n, k;
char s[3][N];
int dp[3][N];

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < 3; i++)
        scanf("%s", s[i]);
}

void solve() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 3; i++)
        for (int j = n; j < n * 3 + 5; j++)
            s[i][j] = '.';
    for (int i = 0; i < 3; i++)
        if (s[i][0] == 's') {
            dp[i][0] = 1;
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int dx = -1; dx <= 1; dx++) {
                int pos = j + dx;
                if (pos < 0 || pos >= 3) continue;
                if (!dp[j][i]) continue;
                if (s[pos][i + 1 + i * 2] == '.' && s[pos][i + 1 + (i + 1) * 2] == '.' && s[j][i + 1 + i * 2] == '.')
                    dp[pos][i + 1] = 1;
            }
        }
    } 
    bool ok = 0;
    for (int i = 0; i < 3; i++)
        ok |= dp[i][n];
    if (ok)
        puts("YES");
    else
        puts("NO");
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
        scanf("%d", &k);
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