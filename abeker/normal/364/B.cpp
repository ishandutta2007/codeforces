#include <cstdio>
using namespace std;

const int MAXN = 55;
const int MAXM = 500005;

int N, D;
int a[MAXN];
bool dp[MAXM][2];

void load() {
    scanf("%d%d", &N, &D);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

void solve() {
    int c = 0;
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        c ^= 1;
        for (int j = 0; j < MAXM; j++) {
            dp[j][c] = dp[j][c ^ 1];
            if (j >= a[i]) dp[j][c] |= dp[j - a[i]][c ^ 1];
        }
    }
    
    int curr = 0;
    for (int days = 0; ; days++) {
        int nxt = -1;
        for (int i = 1; i <= D && curr + i < MAXM; i++)
            if (dp[curr + i][c]) nxt = curr + i;
        if (nxt == -1) {
            printf("%d %d\n", curr, days);
            break;
        }
        curr = nxt;
    }
}

int main() {
    load();
    solve();
    return 0;
}