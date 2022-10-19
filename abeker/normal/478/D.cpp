#include <cstdio>
using namespace std;

const int MAXN = 200005;
const int MOD = 1000000007;

int r, g;
int dp[MAXN][2];

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

void load() {
    scanf("%d%d", &r, &g);
}

int solve() {
    int h = 1;
    while (h * (h + 1) / 2 <= r + g) h++;
    h--;
    int c = 0;
    for (int i = 0; i <= r; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= h; i++) {
        c ^= 1;
        for (int j = 0; j <= r; j++) 
            dp[j][c] = add(dp[j][c ^ 1], i > j ? 0 : dp[j - i][c ^ 1]);
    }
    
    int l = h * (h + 1) / 2 - g;
    return add(dp[r][c], l ? -dp[l - 1][c] : 0);
}
  
int main() {
    load();
    printf("%d\n", solve());
    return 0;
}