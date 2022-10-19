#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int N, K;
char mat[5][MAXN];
int dp[5][MAXN];
int row[30], lo[30], hi[30];
bool bio[1005];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < 3; i++)
        scanf("%s", mat[i]);
}

bool bad(int x, int y, int t) {
    for (int i = 0; i < K; i++) {
        int l = max(lo[i] - 2 * t, 0);
        int r = max(hi[i] - 2 * t, 0);
        if (row[i] == x && l <= y && y <= r) 
            return true;
    }
    return false;
}

int rec(int x, int y) {
    int &ref = dp[x][y];
    if (ref != -1) return ref;
    if (y == N - 1) return ref = !bad(x, y, y);
    ref = 0;
    if (bad(x, y, y)) return ref;
    for (int i = -1; i < 2; i++) {
        int nxt = x + i;
        if (nxt >= 0 && nxt < 3 && !bad(x, y + 1, y) && !bad(nxt, y + 1, y) && rec(nxt, y + 1))
            ref = 1;
    }
    return ref;
}

bool solve() {
    memset(bio, false, sizeof bio);
    memset(dp, -1, sizeof dp);
    int pos = 0;
    for (int i = 0; i < 3; i++)
        if (mat[i][0] == 's') pos = i;
        
    int cnt = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N; j++) {
            if (mat[i][j] < 'A' || mat[i][j] > 'Z') 
                continue;
            if (bio[mat[i][j]]) continue;
            bio[mat[i][j]] = true;
            row[cnt] = i;
            lo[cnt] = j;
            int k = j;
            for (; k < N && mat[i][k] == mat[i][j]; k++);
            hi[cnt] = k - 1;
            cnt++;
        }
            
    return rec(pos, 0);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        load();
        puts(solve() ? "YES" : "NO");
    }
    return 0;
}