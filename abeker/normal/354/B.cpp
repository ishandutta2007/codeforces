#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 20;
const int INF = 0x3f3f3f3f;

const char msg[5][10] = {"FIRST", "SECOND", "DRAW"};

int N;
char mat[MAXN + 1][MAXN + 1];
int dp[2 * MAXN][1 << MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%s", mat[i]);
}

int sgn(int x) {
    if (x > 0) return 0;
    if (x < 0) return 1;
    return 2;
}

bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

int get(char x) {
    if (x == 'a') return 1;
    if (x == 'b') return -1;
    return 0;
}

int rec(int pos, int mask) {
    int &ref = dp[pos][mask];
    if (ref != INF) return ref;
    
    int bit[30] = {0};
    int last = -1;
    for (int i = 0; i < N; i++)
        if (mask >> i & 1) {
            last = i;
            int j = pos - i;
            if (ok(i + 1, j)) bit[mat[i + 1][j] - 'a'] |= 1 << i + 1;
            if (ok(i, j + 1)) bit[mat[i][j + 1] - 'a'] |= 1 << i;
        }
    
    if (pos & 1) {
        ref = -INF;
        for (int i = 0; i < 26; i++)
            if (bit[i]) ref = max(ref, rec(pos + 1, bit[i]));
    }
    else 
        for (int i = 0; i < 26; i++)
            if (bit[i]) ref = min(ref, rec(pos + 1, bit[i])); 
    
    ref += get(mat[last][pos - last]);
    
    return ref;
}

void solve() {
    for (int i = 0; i < 2 * N - 1; i++)
        for (int j = 0; j < 1 << N; j++)
            dp[i][j] = INF;
    dp[2 * N - 2][1 << N - 1] = get(mat[N - 1][N - 1]);
    //printf("%d\n", rec(0, 1)); 
    puts(msg[sgn(rec(0, 1))]);
}

int main() {
    load();
    solve();
    return 0;
}